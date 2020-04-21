using System;
using System.Collections.Generic;
using System.Text;

namespace Borodin
{
    namespace OptimalBinarySearchTree
    {
        public class OptimalTreeNode<T> : OptimalTreeINode<T> where T : IComparable
        {
            public OptimalTreeNode(T value, int prob)
            {
                data = value;
                propability = prob;
            }

            public T data;
            public int propability;
            public OptimalTreeNode<T> left;
            public OptimalTreeNode<T> right;

            public void Accept(VisitorTree<T> visitor)
            {
                visitor.visitBinaryTree(this);
            }
        }
    }
}