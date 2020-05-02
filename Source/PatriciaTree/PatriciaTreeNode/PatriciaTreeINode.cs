using System;
using System.Collections.Generic;
using System.Text;


namespace Borodin
{
    namespace PatriciaTree
    {
        public interface PatriciaTreeINode
        {
            public abstract void Accept(VisitorTree visitor);

            
        }

    }
}