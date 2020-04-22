

#include "AVLTreeFixture.hpp"
#include <fstream>
namespace Borodin {
	namespace AVLTree {
		AVLTree<int> Fixture::AVLTreeFixture::Initialization123()
		{
			AVLTree<int> res;
			int a[3] = { 1,2,3 };
			for (size_t i = 0; i < 3; i++)
			{
				res.Insert(a[i]);
			}
			return res;
		}

		AVLTree<int> Fixture::AVLTreeFixture::Initialization231()
		{
			AVLTree<int> res;
			int a[3] = { 2,3,1 };
			for (size_t i = 0; i < 3; i++)
			{
				res.Insert(a[i]);
			}
			return res;
		}

		AVLTree<int> Fixture::AVLTreeFixture::Initialization5324971869()
		{
			AVLTree<int> res;
			int a[10] = { 5,3,2,4,9,7,1,8,6,9 };
			for (size_t i = 0; i < 10; i++)
			{
				res.Insert(a[i]);
			}
			return res;
		}
		AVLTree<char> Fixture::AVLTreeFixture::Initialization_fidsadhysdl()
		{
			AVLTree<char> res;
			char a[11] = { 'f','i','d','s','a','d','h','y','s','d','l' };
			for (size_t i = 0; i < 11; i++)
			{
				res.Insert(a[i]);
			}
			return res;
		}

		AVLTree<int>* Fixture::AVLTreeFixture::Initialization532497186()
		{
			AVLTree<int>* res = new AVLTree<int>();
			int a[10] = { 5,3,2,4,9,7,1,8,6,9 };
			for (size_t i = 0; i < 10; i++)
			{
				res->Insert(a[i]);
			}
			return res;
		}

		std::string Fixture::AVLTreeFixture::ExpectedResultGraphviz123()
		{
			std::ifstream in("ExpectedTreeFoGraphviz/ExpectedResultGraphviz123.txt");
			std::ostringstream out;
			out << in.rdbuf();
			return out.str();
		}

		std::string Fixture::AVLTreeFixture::ExpectedResultGraphviz231()
		{
			std::ifstream in("ExpectedTreeFoGraphviz/ExpectedResultGraphviz231.txt");
			std::ostringstream out;
			out << in.rdbuf();
			return out.str();
		}

		std::string Fixture::AVLTreeFixture::ExpectedResultGraphviz5324971869()
		{
			std::ifstream in("ExpectedTreeFoGraphviz/ExpectedResultGraphviz5324971869.txt");
			std::ostringstream out;
			out << in.rdbuf();
			return out.str();
		}

		std::string Fixture::AVLTreeFixture::ExpectedResultGraphviz_fidsadhysdl()
		{
			std::ifstream in("ExpectedTreeFoGraphviz/ExpectedResultGraphviz_fidsadhysdl.txt");
			std::ostringstream out;
			out << in.rdbuf();
			return out.str();
		}
	}//namespace AVLTree
}//namespace Borodin