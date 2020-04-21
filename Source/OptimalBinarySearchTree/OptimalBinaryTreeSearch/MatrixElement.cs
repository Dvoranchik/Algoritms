
namespace Borodin
{
    namespace OptimalBinarySearchTree
    {
        public class MatrixElement<T>
        {
            public MatrixElement()
            {
                root = 0;
                weight = 0;
                pathLength = 0;
            }
            public int root { get; set ; }
            public int weight { get; set; }
            public int pathLength { get; set; }
        }
    }
}