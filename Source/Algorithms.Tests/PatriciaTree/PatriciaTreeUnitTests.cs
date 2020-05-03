using NUnit.Framework;
using Borodin.PatriciaTree;

namespace Algorithms.Tests.PatriciaTreeTests
{
    public class PatriciaTreeTests
    {


        [SetUp]
        public void Setup()
        {
            values_Test_tea = new char[] { 'в','ы','п','е','и','ч','а','ю'};
            foreach(var word in values_Test_tea)
            {
                tree.insert(word);
            }
        }

        [Test]
        public void TestConstruct_tea()
        {
            PatriciaTree ntree = new PatriciaTree();
            Assert.AreEqual(ntree._root.data, '0');
        }

        [Test]
        public void TestConstruct_Insert2symb()
        {
            PatriciaTree ntree = new PatriciaTree();
            ntree.insert('в');
            ntree.insert('ы');
            Assert.AreEqual(ntree._root.left.left.data, 'в');
        }

        [Test]
        public void TestPrint()
        {
            tree.orderedPrint(tree._root.left, 0);

            Assert.AreEqual("0авеипчыю", tree.toPrint);
        }

        [Test]
        public void TestSearchFirst()
        {
            Assert.IsTrue(tree.search('ы'));
        }


        public void TestSearchLast()
        {
            Assert.IsTrue(tree.search('а'));
        }

        public void TestNoSearch()
        {
            Assert.IsFalse(tree.search('з'));
        }

        public static char[] values_Test_tea;
        PatriciaTree tree = new PatriciaTree();
    }
}