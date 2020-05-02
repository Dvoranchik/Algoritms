using System;
using System.IO;
namespace Borodin
{
    namespace PatriciaTree
    {
        class MainClass
        {
            static void Main(string[] args)
            {
                PatriciaTree test = new PatriciaTree();
                test.insert('в');
                test.insert('ы');
                test.insert('п');
                test.insert('е');
                test.insert('и');
                test.insert('ч'); 
                test.insert('а');
                test.insert('ю');

               
                //TreePrinter printer = new TreePrinter("Result_ABCD.txt");
                //printer.VisitTreeNode(test._root);
                //string result;
                ////using (StreamReader sr = new StreamReader("ExpectedResultGraphviz_ABCD.txt"))
                ////{
                ////    expected = sr.ReadToEnd();
                ////}
                //using (StreamReader sr2 = new StreamReader("Result_ABCD.txt"))
                //{
                //    result = sr2.ReadToEnd();
                //}
            }
        }
    }
}
