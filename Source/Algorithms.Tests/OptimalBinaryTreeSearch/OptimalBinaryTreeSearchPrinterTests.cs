using NUnit.Framework;
using Borodin.OptimalBinarySearchTree;
using System.IO;

namespace Algorithms.Tests
{
    public class PrinterTests
    {

        [Test]
        public void TestPrinter_ABCD()
        {
            OptimalBinaryTreeSearch<char> tree = new OptimalBinaryTreeSearch<char>(OptimalBinaryTreeTests.values_ABCD, OptimalBinaryTreeTests.probabilities_ABCD);
            TreePrinter<char> printer = new TreePrinter<char>("../../../Source/Algorithms.Tests/ResultsTreeForGraphviz/Result_ABCD.txt");
            printer.VisitTreeNode(tree.root);
            string expected, result;
            using (StreamReader sr = new StreamReader("../../../Source/Algorithms.Tests/ExpectedTreeFoGraphviz/ExpectedResultGraphviz_ABCD.txt"))
            {
                expected = sr.ReadToEnd();
            }
            using (StreamReader sr2 = new StreamReader("../../../Source/Algorithms.Tests/ResultsTreeForGraphviz/Result_ABCD.txt"))
            {
                result = sr2.ReadToEnd();
            }
            Assert.AreEqual(expected, result);
        }

        [Test]
        public void TestPrinter_ABCDEF()
        {
            OptimalBinaryTreeSearch<char> tree = new OptimalBinaryTreeSearch<char>(OptimalBinaryTreeTests.values_ABCDEF, OptimalBinaryTreeTests.probabilities_ABCDEF);
            TreePrinter<char> printer = new TreePrinter<char>("../../../Source/Algorithms.Tests/ResultsTreeForGraphviz/Result_ABCDEF.txt");
            printer.VisitTreeNode(tree.root);
            string expected, result;
            using (StreamReader sr = new StreamReader("../../../Source/Algorithms.Tests/ExpectedTreeFoGraphviz/ExpectedResultGraphviz_ABCDEF.txt"))
            {
                expected = sr.ReadToEnd();
            }
            using (StreamReader sr2 = new StreamReader("../../../Source/Algorithms.Tests/ResultsTreeForGraphviz/Result_ABCDEF.txt"))
            {
                result = sr2.ReadToEnd();
            }
            Assert.AreEqual(expected, result);
        }

        [Test]
        public void TestPrinter_ABCDEFG()
        {
            OptimalBinaryTreeSearch<char> tree = new OptimalBinaryTreeSearch<char>(OptimalBinaryTreeTests.values_ABCDEFG, OptimalBinaryTreeTests.probabilities_ABCDEFG);
            TreePrinter<char> printer = new TreePrinter<char>("../../../Source/Algorithms.Tests/ResultsTreeForGraphviz/Result_ABCDEFG.txt");
            printer.VisitTreeNode(tree.root);
            string expected, result;
            using (StreamReader sr = new StreamReader("../../../Source/Algorithms.Tests/ExpectedTreeFoGraphviz/ExpectedResultGraphviz_ABCDEFG.txt"))
            {
                expected = sr.ReadToEnd();
            }
            using (StreamReader sr2 = new StreamReader("../../../Source/Algorithms.Tests/ResultsTreeForGraphviz/Result_ABCDEFG.txt"))
            {
                result = sr2.ReadToEnd();
            }
            Assert.AreEqual(expected, result);
        }

    }
}