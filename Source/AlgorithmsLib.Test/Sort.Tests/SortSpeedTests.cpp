#include "../SortFixture/SortFixture.h"

namespace Borodin {
	using namespace Sort;
	namespace Tests {
	
		TEST_P(SortsUnitTestsFixture, RandomValues) {
			std::vector<long> vector = Randvector;

			Algorithm->Sort(vector);
			ASSERT_TRUE(std::is_sorted(vector.begin(), vector.end()));
		}

		TEST_P(SortsUnitTestsFixture, InvertValues) {
			std::vector<long> vector = Invertvector;

			Algorithm->Sort(vector);
			ASSERT_TRUE(std::is_sorted(vector.begin(), vector.end()));
		}

		TEST_P(SortsUnitTestsFixture, StraightValues) {
			std::vector<long> vector = Straightvector;

			Algorithm->Sort(vector);
			ASSERT_TRUE(std::is_sorted(vector.begin(), vector.end()));
		}

		TEST_P(SortsUnitTestsFixture, ManyRepitValues) {
			std::vector<long> vector = ManyRepitvector;

			Algorithm->Sort(vector);
			ASSERT_TRUE(std::is_sorted(vector.begin(), vector.end()));
		}

		INSTANTIATE_TEST_SUITE_P(Unit, SortsUnitTestsFixture, ::testing::Values(SortTypes::ShellSort1, 
			SortTypes::ShellSort2, SortTypes::ShellSort3,
			SortTypes::QuickSort, SortTypes::MergeRecSort, 
			SortTypes::MergeNoRecSort, SortTypes::HeapSort), GetSuffix);
	}
}