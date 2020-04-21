#pragma once
#include <gtest/gtest.h>
#include <iostream>
#define COUNTOFSORTS 7
namespace Borodin{
	namespace Tests {
		enum SortTypes
		{
			ShellSort1 ,
			ShellSort2,
			ShellSort3,
			QuickSort,
			MergeRecSort,
			MergeNoRecSort,
			HeapSort,
		};

		std::string GetSuffix(::testing::TestParamInfo<SortTypes> info);
	}
}