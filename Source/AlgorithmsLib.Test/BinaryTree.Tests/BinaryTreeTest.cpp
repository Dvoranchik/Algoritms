// BinaryTree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "../BinaryTreeFixture/BinaryTreeFixture.hpp"

namespace Borodin {
	namespace BinaryTree {
			using namespace Fixture;

			TEST_F(BinaryTreeFixture, Initialization123) {
					BinaryTree<int> first = Initialization123();
					std::string test;
					first.OrderPrint(test);
					std::string result = "123";
					ASSERT_EQ(result, test);
			}

			TEST_F(BinaryTreeFixture, Initialization123Tree) {
				BinaryTree<int> first = Initialization123();
				std::string test;
				first.PrintTree(test);
				std::string result = "      3\n   2\n1\n";
				ASSERT_EQ(result, test);
			}

			TEST_F(BinaryTreeFixture, Initialization231) {
				BinaryTree<int> first = Initialization231();
				std::string test;
				first.OrderPrint(test);
				std::string result = "123";
				ASSERT_EQ(result, test);
			}

			TEST_F(BinaryTreeFixture, Initialization231Tree) {
				BinaryTree<int> first = Initialization231();
				std::string test;
				first.PrintTree(test);
				std::string result = "   3\n2\n   1\n";
				ASSERT_EQ(result, test);
			}

			TEST_F(BinaryTreeFixture, Initialization5324971869Tree) {
				BinaryTree<int> first = Initialization5324971869();
				std::string test;
				first.PrintTree(test);
				std::string result = "   9\n            9\n         8\n      7\n         6\n5\n      4\n   3\n      2\n         1\n";
				ASSERT_EQ(result, test);
			}

			TEST_F(BinaryTreeFixture, Initialization5324971869) {
				BinaryTree<int> first = Initialization5324971869();
				std::string test;
				first.OrderPrint(test);
				std::string result = "1234567899";
				ASSERT_EQ(result, test);
			}
			
			TEST_F(BinaryTreeFixture, Initializationan_fidsadhysdl_Tree) {
				BinaryTree<char> first = Initialization_fidsadhysdl();
				std::string test;
				first.PrintTree(test);
				std::string result = "         y\n      s\n         s\n            l\n   i\n      h\nf\n   d\n         d\n            d\n      a\n";
				ASSERT_EQ(result, test);
			}

			TEST_F(BinaryTreeFixture, Initialization_fidsadhysdl) {
				BinaryTree<char> first = Initialization_fidsadhysdl();
				std::string test;
				first.OrderPrint(test);
				std::string result = "adddfhilssy";
				ASSERT_EQ(result, test);
			}

			TEST_F(BinaryTreeFixture, CopyConstruct) {
				BinaryTree<int> first = Initialization5324971869();
				BinaryTree<int> second(first);
				std::string test1, test2;
				first.OrderPrint(test1);
				first.OrderPrint(test2);
				ASSERT_EQ(test1, test2);
			}

			TEST_F(BinaryTreeFixture, FindIntEnd) {
				BinaryTree<int> first = Initialization5324971869();
				ASSERT_TRUE(first.Find(9));
			}

			TEST_F(BinaryTreeFixture, FindIntStart) {
				BinaryTree<int> first = Initialization5324971869();
				ASSERT_TRUE(first.Find(5));
			}

			TEST_F(BinaryTreeFixture, NoFindInt) {
				BinaryTree<int> first = Initialization5324971869();
				ASSERT_FALSE(first.Find(11));
			}

			TEST_F(BinaryTreeFixture, FindChar) {
				BinaryTree<char> first = Initialization_fidsadhysdl();
				ASSERT_TRUE(first.Find('d'));
			}

			TEST_F(BinaryTreeFixture, NoFindChar) {
				BinaryTree<char> first = Initialization_fidsadhysdl();
				ASSERT_FALSE(first.Find('z'));
			}

			TEST_F(BinaryTreeFixture, RemoveChar) {
				BinaryTree<char> first = Initialization_fidsadhysdl();
				std::string test;
				first.Remove('a');
				first.OrderPrint(test);
				std::string result = "dddfhilssy";
				ASSERT_EQ(result, test);
			}

			TEST_F(BinaryTreeFixture, RemoveInt) {
				BinaryTree<int> first = Initialization5324971869();
				std::string test;
				first.Remove(9);
				first.OrderPrint(test);
				std::string result = "123456789";
				ASSERT_EQ(result, test);
			}

			TEST_F(BinaryTreeFixture, RemoveIntStart) {
				BinaryTree<int> first = Initialization5324971869();
				std::string test;
				first.Remove(5);
				first.OrderPrint(test);
				std::string result = "123467899";
				ASSERT_EQ(result, test);
			}


			TEST_F(BinaryTreeFixture, RemoveCharEnd) {
				BinaryTree<char> first = Initialization_fidsadhysdl();
				std::string test;
				first.Remove('l');
				first.OrderPrint(test);
				std::string result = "adddfhissy";
				ASSERT_EQ(result, test);
			}
	}  // namespace BinaryTree
}  // namespace Borodin