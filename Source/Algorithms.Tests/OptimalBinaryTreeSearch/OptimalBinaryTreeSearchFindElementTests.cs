using NUnit.Framework;
using Borodin.OptimalBinarySearchTree;

namespace Algorithms.Tests.OptimalBinaryTree
{
    class OptimalBinaryTreeSearchFindElementTests
    {
        [SetUp]
        public void Setup()
        {
            OptimalBinaryTreeTests.values_ABCD = new char[] { 'A', 'B', 'C', 'D' };
            OptimalBinaryTreeTests.probabilities_ABCD = new int[] { 6, 2, 8, 7 };

            OptimalBinaryTreeTests.values_ABCDEF = new char[] { 'A', 'B', 'C', 'D', 'E', 'F' };
            OptimalBinaryTreeTests.probabilities_ABCDEF = new int[] { 6, 2, 8, 7, 4, 10 };


            OptimalBinaryTreeTests.values_ABCDEFG = new char[] { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
            OptimalBinaryTreeTests.probabilities_ABCDEFG = new int[] { 3, 5, 8, 11, 4, 10, 1 };
        }

        [Test]
        public void TestFindA_ABCD()
        {
            OptimalBinaryTreeSearch<char> tree = new OptimalBinaryTreeSearch<char>(OptimalBinaryTreeTests.values_ABCD, OptimalBinaryTreeTests.probabilities_ABCD);
            Assert.True(tree.FindElement('A'));
        }

        [Test]
        public void TestFindB_ABCD()
        {
            OptimalBinaryTreeSearch<char> tree = new OptimalBinaryTreeSearch<char>(OptimalBinaryTreeTests.values_ABCD, OptimalBinaryTreeTests.probabilities_ABCD);
            Assert.True(tree.FindElement('B'));
        }

        [Test]
        public void TestFindC_ABCD()
        {
            OptimalBinaryTreeSearch<char> tree = new OptimalBinaryTreeSearch<char>(OptimalBinaryTreeTests.values_ABCD, OptimalBinaryTreeTests.probabilities_ABCD);
            Assert.True(tree.FindElement('C'));
        }

        [Test]
        public void TestFindF_ABCDEFG()
        {
            OptimalBinaryTreeSearch<char> tree = new OptimalBinaryTreeSearch<char>(OptimalBinaryTreeTests.values_ABCDEFG, OptimalBinaryTreeTests.probabilities_ABCDEFG);
            Assert.True(tree.FindElement('F'));
        }


        [Test]
        public void TestNoFindK_ABCD()
        {
            OptimalBinaryTreeSearch<char> tree = new OptimalBinaryTreeSearch<char>(OptimalBinaryTreeTests.values_ABCD, OptimalBinaryTreeTests.probabilities_ABCD);
            Assert.False(tree.FindElement('K'));
        }
    }
}
