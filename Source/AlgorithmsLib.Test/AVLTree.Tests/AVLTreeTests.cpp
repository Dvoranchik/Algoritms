#include "../AVLTreeFixture/AVLTreeFixture.hpp"
#include "../../AVLTree/TreePrinter/TreePrinter.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace Borodin {
	namespace AVLTree {
		using namespace Fixture;

		TEST_F(AVLTreeFixture, InitializationVisitor123) {
			AVLTree<int> first = Initialization123();
			std::ofstream file("ResultsTreeForGraphviz/Result123.txt");
			std::stringstream ss;
			TreePrinter<int> printer(ss);
			printer.PrintInString(first.GetRoot());
			std::string test = ss.str();
			file << test;
			std::string result = "123";
			ASSERT_EQ(ExpectedResultGraphviz123(), test);
		}

		TEST_F(AVLTreeFixture, InitializationVisitor231) {
			AVLTree<int> first = Initialization231();
			std::ofstream file("ResultsTreeForGraphviz/Result231.txt");
			std::stringstream ss;
			TreePrinter<int> printer(ss);
			printer.PrintInString(first.GetRoot());
			std::string test = ss.str();
			file << test;
			ASSERT_EQ(ExpectedResultGraphviz231(), test);
		}

		TEST_F(AVLTreeFixture, InitializationVisitor5324971869) {
			AVLTree<int> first = Initialization5324971869();
			std::ofstream file("ResultsTreeForGraphviz/Result5324971869.txt");
			std::stringstream ss;
			TreePrinter<int> printer(ss);
			printer.PrintInString(first.GetRoot());
			std::string test = ss.str();
			file << test;
			ASSERT_EQ(ExpectedResultGraphviz5324971869(), test);
		}

		TEST_F(AVLTreeFixture, InitializationVisitor_fidsadhysdl) {
			AVLTree<char> first = Initialization_fidsadhysdl();
			std::ofstream file("ResultsTreeForGraphviz/Result_fidsadhysdl.txt");
			std::stringstream ss;
			TreePrinter<char> printer(ss);
			printer.PrintInString(first.GetRoot());
			std::string test = ss.str();
			file << test;
			ASSERT_EQ(ExpectedResultGraphviz_fidsadhysdl(), test);
		}
	}  // namespace BinaryTree
}  // namespace Borodin