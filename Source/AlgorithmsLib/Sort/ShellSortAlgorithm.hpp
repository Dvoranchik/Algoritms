#pragma once
#include "ISortAlgorithm.hpp"

#include <vector>
#include <memory>

namespace Borodin {
	namespace Sort {
		template <typename T>
		class ShellSortAlgorithm : public ISortAlgorithm<T>
		{
		public:
			ShellSortAlgorithm(std::vector<T>& vector)
			{
				_hArray = vector;
			}

			virtual ~ShellSortAlgorithm() = default;
			virtual void InitArray() = 0;
			virtual void Sort(std::vector<T>& vector, std::vector<T>& _hArray)
			{
				T temp;
				int i, j, r;
				int t = _hArray.size();
				int n = vector.size();
				for (r = t - 1; r >= 0; --r)
					for (i = _hArray[r]; i < n; ++i) {
						temp = vector[i];
						j = i - _hArray[r];
						while (j > -1 && vector[j] > temp) {
							vector[j + _hArray[r]] = vector[j];
							j -= _hArray[r];
						}
						vector[j + _hArray[r]] = temp;
					}
			}
		private:
			std::vector<T> _hArray;
		};

		template <typename T>
		class ShellSortAlgorithm3T : public ShellSortAlgorithm<T>
		{
		public:
			ShellSortAlgorithm3T() :ShellSortAlgorithm<T>(_hArray)
			{
				InitArray();
			}
			virtual ~ShellSortAlgorithm3T() = default;

			virtual void Sort(std::vector<T>& vector) override {
				ShellSortAlgorithm<T>::Sort(vector, _hArray);
			}
		private:
			virtual void InitArray() override{
				_hArray.resize(20);
				_hArray[0] = 1;
				for (size_t i = 1; i < 20; i++)
				{
					_hArray[i] = _hArray[i - 1] * 3 + 1;
				}
			}
			std::vector<T> _hArray;
		};

		template <typename T>
		class ShellSortAlgorithm2T : public ShellSortAlgorithm<T>
		{
		public:
			ShellSortAlgorithm2T() :ShellSortAlgorithm<T>(_hArray)
			{
				InitArray();
			}
			virtual ~ShellSortAlgorithm2T() = default;
			virtual void Sort(std::vector<T>& vector) override {
				ShellSortAlgorithm<T>::Sort(vector, _hArray);
			}
		private:
			virtual void InitArray() override {
				_hArray.resize(20);
				_hArray[0] = 1;
				for (size_t i = 1; i < 20; i++)
				{
					_hArray[i] = _hArray[i - 1] * 2 + 1;
				}
			}
			std::vector<T> _hArray;
		};

		template <typename T>
		class ShellSortAlgorithmEven : public ShellSortAlgorithm<T>
		{
		public:
			ShellSortAlgorithmEven():ShellSortAlgorithm<T>(_hArray)
			{
				InitArray();
			
			}
			virtual ~ShellSortAlgorithmEven() = default;
			virtual void Sort(std::vector<T>& vector) override {
				ShellSortAlgorithm<T>::Sort(vector, _hArray);
			}
		private:
			virtual void InitArray() override {
				_hArray.resize(20);
				_hArray[0] = 1;
				for (size_t i = 1; i < 20; i++)
				{
					if (i % 2 == 0) {
						_hArray[i] = 9 * (1 << i) - 9 * (1 << (i/2)) + 1;
					}
					else {
						_hArray[i] = 8 * (1 << i) - 6 * (1 << (i + 1) / 2) + 1;
					}
				}
			}
			std::vector<T> _hArray;
		};
	}
}