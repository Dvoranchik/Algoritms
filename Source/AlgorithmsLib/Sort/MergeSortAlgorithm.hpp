#pragma once
#include "ISortAlgorithm.hpp"

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>

namespace Borodin {
	namespace Sort {
		template <typename T>
		class MergeSortRecursiveAlgorithm : public ISortAlgorithm<T>
		{
		public:
            MergeSortRecursiveAlgorithm() = default;
			virtual ~MergeSortRecursiveAlgorithm() = default;
            virtual void Sort(std::vector<T>& vector) override {
                if(!vector.empty())
                    mergeSort(vector, 0, vector.size() - 1);
            }

        private:
            void mergeSort(std::vector<T>& vector, int l, int r)
            {
                if (l == r) return; 
                int mid = (l + r) / 2; 
                mergeSort(vector, l, mid);
                mergeSort(vector, mid + 1, r);
                int i = l;  
                int j = mid + 1; 
                std::vector<T> tmp; 
                tmp.resize(vector.size());
                for (int step = 0; step < r - l + 1; step++) 
                {
                    if ((j > r) || ((i <= mid) && (vector[i] < vector[j])))
                    {
                        tmp[step] = vector[i];
                        i++;
                    }
                    else
                    {
                        tmp[step] = vector[j];
                        j++;
                    }
                }
                for (int step = 0; step < r - l + 1; step++)
                    vector[l + step] = tmp[step];
            }
		};

        template <typename T>
        class MergeSortNoRecursiveAlgorithm : public ISortAlgorithm<T>
        {
        public:
            MergeSortNoRecursiveAlgorithm() = default;
            virtual ~MergeSortNoRecursiveAlgorithm() = default;
            virtual void Sort(std::vector<T>& vector) override
            {
                long n = vector.size();
                long step = 1;
                T* temp = new T[n * sizeof(temp)];
                while (step < n)
                {
                    long index = 0;
                    long l = 0;
                    long m = l + step;
                    long r = l + step * 2;
                    do
                    {
                        m = m < n ? m : n;
                        r = r < n ? r : n;
                        long i1 = l, i2 = m;
                        for (; i1 < m && i2 < r; )
                        {
                            if (vector[i1] < vector[i2]) { temp[index++] = vector[i1++]; }
                            else { temp[index++] = vector[i2++]; }
                        }
                        while (i1 < m) temp[index++] = vector[i1++];
                        while (i2 < r) temp[index++] = vector[i2++];
                        l += step * 2;
                        m += step * 2;
                        r += step * 2;
                    } while (l < n);
                    for (int i = 0; i < n; i++)
                        vector[i] = temp[i];
                    step *= 2;
                }
                delete[] temp;
            }
        };

	}
}