#pragma once
#include "ISortAlgorithm.hpp"

namespace Borodin {
	namespace Sort {
		template <typename T>
		class QuickSortAlgorithm : public ISortAlgorithm<T>
		{
		public:
			QuickSortAlgorithm() = default;

			virtual ~QuickSortAlgorithm() = default;

            virtual void Sort(std::vector<T>& vector) override
            {
                long size = vector.size();
                if (size > 0) {
                    long i, j;

                    long lb, ub;

                    std::vector<T> lbstack;
                    std::vector<T> ubstack;
                    lbstack.resize(size / 2);
                    ubstack.resize(size / 2);
                    long stackpos = 1;
                    long ppos;
                    T pivot;
                    T temp;
               
                    lbstack[1] = 0;
                    ubstack[1] = size - 1;
                    do {
                        lb = lbstack[stackpos];
                        ub = ubstack[stackpos];
                        stackpos--;

                        do {

                            ppos = (lb + ub) >> 1;
                            i = lb;
                            j = ub;
                            pivot = vector[ppos];

                            do {
                                while (vector[i] < pivot) i++;
                                while (pivot < vector[j]) j--;

                                if (i <= j) {
                                    temp = vector[i];
                                    vector[i] = vector[j];
                                    vector[j] = temp;
                                    i++; j--;
                                }
                            } while (i <= j);

                            if (i < ppos) {

                                if (i < ub) {
                                    stackpos++;
                                    lbstack[stackpos] = i;
                                    ubstack[stackpos] = ub;
                                }
                                ub = j;
                            }
                            else {
                                if (j > lb) {
                                    stackpos++;
                                    lbstack[stackpos] = lb;
                                    ubstack[stackpos] = j;
                                }
                                lb = i;
                            }

                        } while (lb < ub);

                    } while (stackpos != 0);
                }
            }
		};
	}
}