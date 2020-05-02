using System;
using System.Collections.Generic;
using System.Text;

namespace Borodin
{
    namespace PatriciaTree
    {
        public interface VisitorTree
        {
            void visitBinaryTree(PatriciaTreeNode node);
        }
    }
}