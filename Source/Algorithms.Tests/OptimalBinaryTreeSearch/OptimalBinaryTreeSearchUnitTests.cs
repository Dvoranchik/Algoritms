using NUnit.Framework;
using Borodin.OptimalBinarySearchTree;

namespace Algorithms.Tests.OptimalBinaryTree
{
    public class OptimalBinaryTreeTests
    {



        [Test]
        public void TestConstruct_ABCD()
        {
            OptimalBinaryTreeSearch<char> tree = new OptimalBinaryTreeSearch<char>(values_ABCD, probabilities_ABCD);
            Assert.AreEqual('C', tree.root.data);
        }

        [Test]
        public void TestConstruct_ABCDEF()
        {
            OptimalBinaryTreeSearch<char> tree = new OptimalBinaryTreeSearch<char>(values_ABCDEF, probabilities_ABCDEF);
            Assert.AreEqual('D', tree.root.data);
        }

        [Test]
        public void TestConstruct_ABCDEFG()
        {
            OptimalBinaryTreeSearch<char> tree = new OptimalBinaryTreeSearch<char>(values_ABCDEFG, probabilities_ABCDEFG);
            Assert.AreEqual('D', tree.root.data);
        }

        public static char[] values_ABCD;
        public static int[] probabilities_ABCD;

        public static char[] values_ABCDEF;
        public static int[] probabilities_ABCDEF;

        public static char[] values_ABCDEFG;
        public static int[] probabilities_ABCDEFG;
    }
}