using System;
using System.Collections.Generic;
using System.Text;

namespace Borodin.OptimalBinarySearchTree
{
    class MainFun
    {
        static void Main(string[] args)
        {
            char[] values = new char[] { 'A', 'B', 'C', 'D' ,'E', 'F'};
            int[] probabilities = new int[] { 6, 2, 8, 7 ,4 , 8};
            OptimalBinaryTreeSearch<char> tree = new OptimalBinaryTreeSearch<char>(values, probabilities);

            TreePrinter<char> printer = new TreePrinter<char>("123.txt");
            printer.VisitTreeNode(tree.root);
        }
       
    }
}
