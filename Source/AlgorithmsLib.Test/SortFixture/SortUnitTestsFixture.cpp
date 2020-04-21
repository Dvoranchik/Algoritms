#include "SortFixture.h"

std::vector<long> Borodin::Tests::SortsUnitTestsFixture::GetInvert()
{
	std::vector<long> vector;
	vector.resize(SIZE);
	for (size_t i = 0; i < SIZE; i++)
	{
		vector[i] = SIZE - i - 1;
	}
	return vector;
}

std::vector<long> Borodin::Tests::SortsUnitTestsFixture::GetRand()
{
	std::vector<long> vector;
	vector.resize(SIZE);
	for (size_t i = 0; i < SIZE; i++)
	{
		vector[i] = std::rand() % SIZE;
	}
	return vector;
}

std::vector<long> Borodin::Tests::SortsUnitTestsFixture::GetStraight()
{
	std::vector<long> vector;
	vector.resize(SIZE);
	for (size_t i = 0; i < SIZE; i++)
	{
		vector[i] = i;
	}
	return vector;
}

std::vector<long> Borodin::Tests::SortsUnitTestsFixture::GetManyRepit()
{
	std::vector<long> vector;
	vector.resize(SIZE);
	for (size_t i = 0; i < SIZE; i++)
	{
		vector[i] = std::rand() % 10;
	}
	return vector;
}
