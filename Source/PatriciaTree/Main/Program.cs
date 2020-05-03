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
                test.orderedPrint(test._root.left, 0);
              
            }
        }
    }
}
