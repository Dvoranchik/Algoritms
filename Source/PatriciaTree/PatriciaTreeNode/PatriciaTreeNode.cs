using System;
using System.Collections.Generic;
using System.Text;


namespace Borodin
{
    namespace PatriciaTree
    {
        public class PatriciaTreeNode: PatriciaTreeINode
        {

            public PatriciaTreeNode(char data)
            {
                this.data = data;
                left = this;
                right = this;
            }

            public PatriciaTreeNode()
            {
                this.data = '0';
                this.key = 0;
                left = this;
                right = this;
                level = 0;
            }

            public int level;
            public int key = 0;
            public PatriciaTreeNode left;
            public PatriciaTreeNode right;
            public char data;
        }

    }
}