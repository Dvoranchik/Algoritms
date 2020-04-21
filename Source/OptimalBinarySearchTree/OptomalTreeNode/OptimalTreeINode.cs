using System;

namespace Borodin
{
    namespace OptimalBinarySearchTree
    {
        interface OptimalTreeINode<T> where T : IComparable
        {
            public abstract void Accept(VisitorTree<T> visitor);
        }
    }
};
