#pragma once
#include <gtest/gtest.h>
#include "SortTypes.hpp"
#include "../../AlgorithmsLib/Sort/ISortAlgorithm.hpp"
#include "../../AlgorithmsLib/Sort/ShellSortAlgorithm.hpp"
#include "../../AlgorithmsLib/Sort/QuickSortAlgorithm.hpp"
#include "../../AlgorithmsLib/Sort/MergeSortAlgorithm.hpp"
#include "../../AlgorithmsLib/Sort/HeapSortAlgorithm.hpp"


#include <memory>

#ifdef _DEBUG
#define SIZE 10000
#else
#define SIZE 100000
#endif

namespace Borodin {
	using namespace Sort;
	namespace Tests {

		class SortsUnitTestsFixture : public testing::TestWithParam<SortTypes> {
		protected:
			
			void SetUp() override
			{
				Randvector = GetRand();
				Invertvector = GetInvert();
				Straightvector = GetStraight();
				ManyRepitvector = GetManyRepit();

				auto sortType = GetParam();

				switch (sortType)
				{
				case ShellSort1:
				{
					Algorithm = SortAlgorithmPtr<long>(new ShellSortAlgorithm3T<long>());
					return;
				}
				case ShellSort2:
				{
					Algorithm = SortAlgorithmPtr<long>(new ShellSortAlgorithm2T<long>());
					return;
				}
				case ShellSort3:
				{
					Algorithm = SortAlgorithmPtr<long>(new ShellSortAlgorithmEven<long>());
					return;
				}
				case QuickSort:
				{
					Algorithm = SortAlgorithmPtr<long>(new QuickSortAlgorithm<long>());
					return;
				}
				case MergeRecSort:
				{
					Algorithm = SortAlgorithmPtr<long>(new MergeSortRecursiveAlgorithm<long>());
					return;
				}
				case MergeNoRecSort:
				{
					Algorithm = SortAlgorithmPtr<long>(new MergeSortNoRecursiveAlgorithm<long>());
					return;
				}
				case HeapSort:
				{
					Algorithm = SortAlgorithmPtr<long>(new HeapSortAlgorithm<long>());
					return;
				}
				}
			}

			std::vector<long> GetInvert();
			std::vector<long> GetRand();
			std::vector<long> GetStraight();
			std::vector<long> GetManyRepit();

			std::vector<long> Randvector;
			std::vector<long> Invertvector;
			std::vector<long> Straightvector;
			std::vector<long> ManyRepitvector;


			SortAlgorithmPtr<long> Algorithm;
		};
	}
}