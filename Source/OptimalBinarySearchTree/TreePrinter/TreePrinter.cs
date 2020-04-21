using System;
using System.Collections.Generic;
using System.IO;


namespace Borodin
{
    namespace OptimalBinarySearchTree
    {
        public class TreePrinter<T>: VisitorTree<T> where T : IComparable
        {
            public TreePrinter(string path)
            {
                writePath = path;
            }
                 
            public void visitBinaryTree(OptimalTreeNode<T> binNode)
            {
                 int currentlevel = level;
                 if (binNode.left != null)
                 {
                     toWrite += "    struct" + (level+1).ToString() + "[label=\"" + binNode.left.data.ToString() + "\",color=blue]";
                     toWrite += "    struct" + level.ToString() + " -> " + "struct" + (level + 1).ToString() + ";\n";
                     ++level;
                     binNode.left.Accept(this);
                 }
                 if (binNode.right != null)
                 {
                     toWrite += "    struct" + (level + 1).ToString() + "[label=\"" + binNode.right.data.ToString() + "\",color=red]";
                     toWrite += "    struct" + currentlevel.ToString()+ " -> struct" + (level+1).ToString() + ";\n";
                     ++level;
                     binNode.right.Accept(this);
                 }
            }

            public void VisitTreeNode(OptimalTreeNode<T> node)
            {
                using (StreamWriter sw = new StreamWriter(writePath, false, System.Text.Encoding.Default))
                {
                    sw.Write("digraph BST {\n    node [fontname=\"Arial\"];\n");
                    if (node == null)
                        sw.Write("\n");
                    else if (node.right == null && node.left == null)
                        sw.Write("    " + node.data + ";\n");
                    else
                    {
                        sw.Write("    struct" + level + "[label=\"" + node.data + "\",color=green];\n");
                        visitBinaryTree(node);
                    }
                }
                using (StreamWriter sw = new StreamWriter(writePath, true, System.Text.Encoding.Default))
                {
                    sw.Write(toWrite);
                    sw.Write("}\n");
                }
            }

            int level = 0;
            string writePath;
            string toWrite;
        }
    }
}