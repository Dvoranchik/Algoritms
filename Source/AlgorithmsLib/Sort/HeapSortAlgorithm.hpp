#pragma once
#include "ISortAlgorithm.hpp"

namespace Borodin {
	namespace Sort {
		template <typename T>
		class HeapSortAlgorithm : public ISortAlgorithm<T>
		{
			public:
				virtual ~HeapSortAlgorithm() = default;

				virtual void Sort(std::vector<T>& vector) {
					long n = vector.size();
					for (int i(n / 2 - 1); i >= 0; --i)
						SiftDown(vector, i, n);

					while (n > 1)
					{
						--n;

						T const firstElem(vector[0]);
						vector[0] = vector[n];
						vector[n] = firstElem;

						SiftDown(vector, 0, n);
					}
				}

			private:
				void SiftDown(std::vector<T>& vector, T i, int const n)
				{
					T nMax(i);
					T const value(vector[i]);

					while (true)
					{
						i = nMax;

						T childN(i * 2 + 1);
						if ((childN < n) && (vector[childN] > value))
							nMax = childN;
						++childN;
						if ((childN < n) && (vector[childN] > vector[nMax]))
							nMax = childN;
						if (nMax == i) break;

						vector[i] = vector[nMax];
						vector[nMax] = value;
					}
				}
		};
	}
}