using System;
using System.Collections.Generic;


namespace Borodin
{
    namespace PatriciaTree
    {
        class PatriciaTree
        {
            public PatriciaTree()
            {
                insert('0');
            }

            int bit(char data, int num)
            {
                return Keys[data] & mask[num - 1];
            }

            /** function to search for an element **/
            public bool search(char k)
            {

                PatriciaTreeNode searchNode = search(_root, k);
                if (searchNode.data == k)
                    return true;
                else
                    return false;
            }
            /** function to search for an element **/
            private PatriciaTreeNode search(PatriciaTreeNode t, char k)
            {
                PatriciaTreeNode currentNode, nextNode;
                if (t == null)
                {
                    return null;
                }
                nextNode = t.left;
                currentNode = t;
                while (nextNode.level > currentNode.level)
                {
                    currentNode = nextNode;
                    nextNode = (bit(k, nextNode.level)==1) ? nextNode.right : nextNode.left;
                }
                return nextNode;
            }


            public void insert(char ele)
            {
                _root = insert(_root, ele);
            }
            /** function to insert and element **/
            private PatriciaTreeNode insert(PatriciaTreeNode t, char ele)
            {
                PatriciaTreeNode current, parent, lastNode, newNode;
                int i;

                if (t == null)
                {
                    t = new PatriciaTreeNode(ele);
                    t.level = 0;
                    t.data = ele;
                    t.left = t;
                    t.right = t;
                    return t;
                }

                lastNode = search(t, ele);

                if (ele == lastNode.data)
                {
                    return t;
                }

                for (i = 1; bit(ele, i) == bit(lastNode.data, i); i++) ;

                current = t.left; parent = t;
                while (current.level > parent.level && current.level < i)
                {
                    parent = current;
                    current = (bit(ele, current.level) == 1) ? current.right : current.left;
                }

                newNode = new PatriciaTreeNode();
                newNode.level = i;
                newNode.data = ele;
                newNode.left = (bit(ele, i)==1) ? current : newNode;
                newNode.right = (bit(ele, i)==1) ? newNode : current;

                if (current == parent.left)
                    parent.left = newNode;
                else
                    parent.right = newNode;

                return t;
            }

            private Dictionary<char, int> Keys = new Dictionary<char, int>
            {
                {'а', 0b00001},{'б',0b00010},{'в',0b00011},{'г',0b00100},{'д',0b00101},
                { 'е', 0b00110},{'ж',0b00111},{'з', 0b01000},{'и', 0b01001},{'к',0b01010},
                    { 'л',0b01011},{'м', 0b01100},{'н',0b01101},{'о', 0b01110},{'п',0b01111},
                {'р', 0b10000},{'с', 0b10001},{'т',  0b10010},{'у', 0b10011},{'ф',  0b10100}
                ,{ 'х', 0b10101},{'ц', 0b10110},{'ч',0b10111},{'ш',0b11000},
                {'щ',0b11001},{ 'ъ', 0b11010},{'ы', 0b11011},{ 'ь',0b11100},
                {'э',0b11101},{'ю',0b11110},{'я', 0b11111},{'0',0}
            };
            private int[] mask = new int[5] {0b10000, 0b01000, 0b00100, 0b00010, 0b00001};
            public PatriciaTreeNode _root;
        }
    }
}