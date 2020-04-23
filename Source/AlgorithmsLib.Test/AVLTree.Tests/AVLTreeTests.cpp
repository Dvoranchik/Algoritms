#include "../AVLTreeFixture/AVLTreeFixture.hpp"
#include "../../AVLTree/TreePrinter/TreePrinter.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace Borodin {
	namespace AVLTree {
		using namespace Fixture;

		TEST_F(AVLTreeFixture, Initialization123) {
			AVLTree<int> first = Initialization123();
			std::string test;
			first.preOrder(test, first.GetRoot());
			std::string result = "123";
			ASSERT_EQ(result, test);
		}

		TEST_F(AVLTreeFixture, Initialization231) {
			AVLTree<int> first = Initialization231();
			std::string test;
			first.preOrder(test, first.GetRoot());
			std::string result = "123";
			ASSERT_EQ(result, test);
		}

		TEST_F(AVLTreeFixture, Initialization5324971869Tree) {
			AVLTree<int> first = Initialization5324971869();
			std::string test;
			first.preOrder(test, first.GetRoot());
			std::string result = "1234567899";
			ASSERT_EQ(result, test);
		}

		TEST_F(AVLTreeFixture, Initializationan_fidsadhysdl_Tree) {
			AVLTree<char> first = Initialization_fidsadhysdl();
			std::string test;
			first.preOrder(test, first.GetRoot());
			std::string result = "adddfhilssy";
			ASSERT_EQ(result, test);
		}

		TEST_F(AVLTreeFixture, CopyConstruct) {
			AVLTree<int> first = Initialization5324971869();
			AVLTree<int> second(first);
			std::string test1, test2;
			first.preOrder(test1, first.GetRoot());
			first.preOrder(test2, first.GetRoot());
			ASSERT_EQ(test1, test2);
		}

		TEST_F(AVLTreeFixture, FindIntEnd) {
			AVLTree<int> first = Initialization5324971869();
			ASSERT_TRUE(first.Find(9));
		}

		TEST_F(AVLTreeFixture, FindIntStart) {
			AVLTree<int> first = Initialization5324971869();
			ASSERT_TRUE(first.Find(5));
		}

		TEST_F(AVLTreeFixture, NoFindInt) {
			AVLTree<int> first = Initialization5324971869();
			ASSERT_FALSE(first.Find(11));
		}

		TEST_F(AVLTreeFixture, FindChar) {
			AVLTree<char> first = Initialization_fidsadhysdl();
			ASSERT_TRUE(first.Find('d'));
		}

		TEST_F(AVLTreeFixture, NoFindChar) {
			AVLTree<char> first = Initialization_fidsadhysdl();
			ASSERT_FALSE(first.Find('z'));
		}

		TEST_F(AVLTreeFixture, RemoveChar) {
			AVLTree<char> first = Initialization_fidsadhysdl();
			std::string test;
			first.Delete('a');
			first.preOrder(test, first.GetRoot());
			std::string result = "dddfhilssy";
			ASSERT_EQ(result, test);
		}

		TEST_F(AVLTreeFixture, RemoveInt) {
			AVLTree<int> first = Initialization5324971869();
			std::string test;
			first.Delete(9);
			first.preOrder(test, first.GetRoot());
			std::string result = "123456789";
			ASSERT_EQ(result, test);
		}

		TEST_F(AVLTreeFixture, RemoveIntStart) {
			AVLTree<int> first = Initialization5324971869();
			std::string test;
			first.Delete(5);
			first.preOrder(test, first.GetRoot());
			std::string result = "123467899";
			ASSERT_EQ(result, test);
		}


		TEST_F(AVLTreeFixture, RemoveCharEnd) {
			AVLTree<char> first = Initialization_fidsadhysdl();
			std::string test;
			first.Delete('l');
			first.preOrder(test, first.GetRoot());
			std::string result = "adddfhissy";
			ASSERT_EQ(result, test);
		}
	}  // namespace BinaryTree
}  // namespace Borodin