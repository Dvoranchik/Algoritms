#pragma once
#include <gtest/gtest.h>
#include "../../BinaryTree/BinaryTree/BinaryTree.hpp"


namespace Borodin {
	namespace BinaryTree {
		namespace Fixture {
			// The fixture for testing class Foo.
			class BinaryTreeFixture : public ::testing::Test {

			protected:
				// You can remove any or all of the following functions if their bodies would
				// be empty.

				BinaryTreeFixture() {
					// You can do set-up work for each test here.
				}

				~BinaryTreeFixture() override {
					// You can do clean-up work that doesn't throw exceptions here.
				}

				// If the constructor and destructor are not enough for setting up
				// and cleaning up each test, you can define the following methods:

				void SetUp() override {
					// Code here will be called immediately after the constructor (right
					// before each test).
				}

				void TearDown() override {
					// Code here will be called immediately after each test (right
					// before the destructor).
				}
				BinaryTree<int> Initialization123();
				BinaryTree<int> Initialization231();
				BinaryTree<int> Initialization5324971869();
				BinaryTree<char> Initialization_fidsadhysdl();
				BinaryTree<int>* Initialization532497186();

				std::string ExpectedResultGraphviz123();
				std::string ExpectedResultGraphviz231();
				std::string ExpectedResultGraphviz5324971869();
				std::string ExpectedResultGraphviz_fidsadhysdl();
			};
		}
	}  // namespace project
}  // namespace my
