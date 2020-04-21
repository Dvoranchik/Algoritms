using System;
using System.Collections.Generic;
using System.Text;


namespace Borodin
{
    namespace OptimalBinarySearchTree
    {
        public interface VisitorTree<T> where T : IComparable
        {
            void visitBinaryTree(OptimalTreeNode<T> node);
        }
    }
}