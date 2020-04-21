#pragma once

#include "BinaryTreeFixture.hpp"
#include <fstream>
namespace Borodin {
	namespace BinaryTree {
		BinaryTree<int> Fixture::BinaryTreeFixture::Initialization123()
		{
			BinaryTree<int> res;
			int a[3] = { 1,2,3 };
			for (size_t i = 0; i < 3; i++)
			{
				res.Insert(a[i]);
			}
			return res;
		}

		BinaryTree<int> Fixture::BinaryTreeFixture::Initialization231()
		{
			BinaryTree<int> res;
			int a[3] = { 2,3,1 };
			for (size_t i = 0; i < 3; i++)
			{
				res.Insert(a[i]);
			}
			return res;
		}

		BinaryTree<int> Fixture::BinaryTreeFixture::Initialization5324971869()
		{
			BinaryTree<int> res;
			int a[10] = { 5,3,2,4,9,7,1,8,6,9 };
			for (size_t i = 0; i < 10; i++)
			{
				res.Insert(a[i]);
			}
			return res;
		}
		BinaryTree<char> Fixture::BinaryTreeFixture::Initialization_fidsadhysdl()
		{
			BinaryTree<char> res;
			char a[11] = { 'f','i','d','s','a','d','h','y','s','d','l' };
			for (size_t i = 0; i < 11; i++)
			{
				res.Insert(a[i]);
			}
			return res;
		}

		BinaryTree<int>* Fixture::BinaryTreeFixture::Initialization532497186()
		{
			BinaryTree<int>* res = new BinaryTree<int>();
			int a[10] = { 5,3,2,4,9,7,1,8,6,9 };
			for (size_t i = 0; i < 10; i++)
			{
				res->Insert(a[i]);
			}
			return res;
		}

		std::string Fixture::BinaryTreeFixture::ExpectedResultGraphviz123()
		{
			std::ifstream in("ExpectedTreeFoGraphviz/ExpectedResultGraphviz123.txt");
			std::ostringstream out;
			out << in.rdbuf();
			return out.str();
		}

		std::string Fixture::BinaryTreeFixture::ExpectedResultGraphviz231()
		{
			std::ifstream in("ExpectedTreeFoGraphviz/ExpectedResultGraphviz231.txt");
			std::ostringstream out;
			out << in.rdbuf();
			return out.str();
		}

		std::string Fixture::BinaryTreeFixture::ExpectedResultGraphviz5324971869()
		{
			std::ifstream in("ExpectedTreeFoGraphviz/ExpectedResultGraphviz5324971869.txt");
			std::ostringstream out;
			out << in.rdbuf();
			return out.str();
		}

		std::string Fixture::BinaryTreeFixture::ExpectedResultGraphviz_fidsadhysdl()
		{
			std::ifstream in("ExpectedTreeFoGraphviz/ExpectedResultGraphviz_fidsadhysdl.txt");
			std::ostringstream out;
			out << in.rdbuf();
			return out.str();
		}
	}//namespace BinaryTree
}//namespace Borodin