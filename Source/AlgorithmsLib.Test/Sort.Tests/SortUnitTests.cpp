#include "../SortFixture/SortFixture.h"

namespace Borodin {
	using namespace Sort;
	namespace Tests {
		

		TEST_P(SortsUnitTestsFixture, EmptyArray) {
			std::vector<long> vector;
			const std::vector<long> expectedVector;

			Algorithm->Sort(vector);
			EXPECT_EQ(expectedVector, vector);
		}

		TEST_P(SortsUnitTestsFixture, SortedArrayWithUniqueValues) {
			std::vector<long> vector = { 1, 3, 5, 8, 9 };
			const std::vector<long> expectedVector = { 1, 3, 5, 8, 9 };

			Algorithm->Sort(vector);
			EXPECT_EQ(expectedVector, vector);
		}

		TEST_P(SortsUnitTestsFixture, SortedArrayWithSingleValues) {
			std::vector<long> vector = { 433, 433, 433, 433, 433 };
			const std::vector<long> expectedVector = { 433, 433, 433, 433, 433 };

			Algorithm->Sort(vector);
			EXPECT_EQ(expectedVector, vector);
		}

		TEST_P(SortsUnitTestsFixture, DecreasingArrayWithUniqueValues) {
			std::vector<long> vector = { 35, 33, 7, 3, 1 };
			const std::vector<long> expectedVector = { 1, 3, 7, 33, 35 };

			Algorithm->Sort(vector);
			EXPECT_EQ(expectedVector, vector);
		}

		INSTANTIATE_TEST_SUITE_P(Unit, SortsUnitTestsFixture, ::testing::Values(SortTypes::ShellSort1,
			SortTypes::ShellSort2, SortTypes::ShellSort3, 
			SortTypes::QuickSort, SortTypes::MergeRecSort,
			SortTypes::MergeNoRecSort, SortTypes::HeapSort), GetSuffix);
	}
}