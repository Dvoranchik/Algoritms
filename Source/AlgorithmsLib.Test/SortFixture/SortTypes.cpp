#include "SortTypes.hpp"


namespace Borodin {
	namespace Tests {
		std::string dictionary[COUNTOFSORTS] = 
		{
			"ShellSortTriple",
			"ShellSortDouble",
			"ShellSortSedgwick",
			"QuickSort",
			"HeapSort",
			"MergeDWSort",
			"MergeNoDWSort",
		};

		std::string GetSuffix(::testing::TestParamInfo<SortTypes> info)
		{
			return dictionary[info.param];
		}
	}
}