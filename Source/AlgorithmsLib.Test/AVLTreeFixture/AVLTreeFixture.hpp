#pragma once
#include <gtest/gtest.h>
#include "../../AVLTree/AVLTree/AVLTree.hpp"
#include "../../AVLTree/TreeVisitor/TreeVisitor.hpp"

namespace Borodin {
	namespace AVLTree {
		namespace Fixture {
			// The fixture for testing class Foo.
			class AVLTreeFixture : public ::testing::Test {

			protected:
				// You can remove any or all of the following functions if their bodies would
				// be empty.

				AVLTreeFixture() {
					// You can do set-up work for each test here.
				}

				~AVLTreeFixture() override {
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

				AVLTree<int> Initialization123();
				AVLTree<int> Initialization231();
				AVLTree<int> Initialization5324971869();
				AVLTree<char> Initialization_fidsadhysdl();
				AVLTree<int>* Initialization532497186();

				std::string ExpectedResultGraphviz123();
				std::string ExpectedResultGraphviz231();
				std::string ExpectedResultGraphviz5324971869();
				std::string ExpectedResultGraphviz_fidsadhysdl();
			};
		}
	}  // namespace project
}  // namespace my
