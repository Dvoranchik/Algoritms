#pragma once
#include <vector>
#include <memory>

namespace Borodin {
		namespace Sort {
			template <typename T>
			struct ISortAlgorithm
			{
				virtual ~ISortAlgorithm() = default;
				virtual void Sort(std::vector<T>& vector) = 0;
			};
			template <typename T>
			using SortAlgorithmPtr = std::shared_ptr<ISortAlgorithm<T>>;
		}
}