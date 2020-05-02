using System.Collections.Generic;
using System;
using System.Linq;
namespace Borodin
{
    namespace OptimalBinarySearchTree
    {
        public class OptimalBinaryTreeSearch<T> where T : IComparable
        {
            public bool FindElement(T data)
            {
                return findByValue(data, root);
            }

            bool findByValue(T data, OptimalTreeNode<T> node)
            {
                if (node == null) 
                    return false;

                if (data.Equals(node.data))
                {
                    return true;
                }

                if (data.CompareTo(node.data) > 0)
                {
                    return findByValue(data, node.right);
                }
                else if (data.CompareTo(node.data) < 0)
                {
                    return findByValue(data, node.left);
                }

                else 
                    return false;
            }
            public void Insert(T data, int prob)
            {
                if (root == null)
                {
                    root = new OptimalTreeNode<T>(data, prob);
                }

                OptimalTreeNode<T> current = root;

                while (current != null)
                {
                    if (data.CompareTo(current.data) > 0)
                    {
                        if (current.right != null)
                        {
                            current = current.right;
                            continue;
                        }
                        current.right = new OptimalTreeNode<T>(data, prob);
                    }

                    else if (data.CompareTo(current.data) < 0)
                    {
                        if (current.left != null)
                        {
                            current = current.left;
                            continue;
                        }
                        current.left = new OptimalTreeNode<T>(data, prob);
                    }

                    else
                    {
                        return;
                    }

                }
            }

            static void optimalSearchTree(T[] keys, int[] freq, int n)
            {
                matrix = new MatrixElement<T>[n+1][];
                for (int i = 0; i < n+1; i++)
                {
                    matrix[i] = new MatrixElement<T>[n+1];
                    for (int j = 0; j < n+1; j++)
                    {
                        matrix[i][j] = new MatrixElement<T>();
                    }
                }

                for (int i = 0; i < n; i++)
                {
                    matrix[i][i].root = i;
                    matrix[i][i].pathLength = 0;
                    matrix[i][i].weight = freq[i];
                }

                for (int L = 2; L <= n; L++)
                {

                    for (int i = 0; i <= n - L + 1; i++)
                    {

                        int j = i + L - 1;
                        matrix[i][j].weight = ((j < n) ? freq[j] : 0) + matrix[i][j - 1].weight;
                        int k = find(matrix, i, j);
                        matrix[i][j].pathLength = ((k > i) ? matrix[i][k - 1].pathLength : 0) + ((k < j) ? matrix[k + 1][j].pathLength : 0)
                            +
                            ((k > i) ? matrix[i][k - 1].weight : 0) + ((k < j) ? matrix[k + 1][j].weight : 0);
                        matrix[i][j].root = k;
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        Console.Write("   {" + matrix[i][j].root.ToString() + " " + matrix[i][j].pathLength + " " + matrix[i][j].weight + "}\t");
                    }
                    Console.WriteLine();
                }
            }

            public static int find(MatrixElement<T>[][] matrix, int i, int j)
            {
                int min = int.MaxValue;
                int l = 0 ,c = 0;
                for (int k = i; k <= j; k++)
                {
                    c = ((k > i) ? matrix[i][k - 1].pathLength : 0 ) + ((k < j) ? matrix[k+1][j].pathLength : 0) + ((k > i) ? matrix[i][k-1].weight : 0 ) + ((k < j) ? matrix[k+1][j].weight : 0);
                    if (c < min)
                    {
                        min = c;
                        l = k;
                    }
                }
                return l;
            }

            public OptimalTreeNode<T> construct_OBST(MatrixElement<T>[][] matrix, int i, int j, T[] keys, int[] prob)
            {
                OptimalTreeNode<T> p;
                if (i > j)
                    p = null;
                else
                {
                    p = new OptimalTreeNode<T>(keys[matrix[i][j].root], prob[matrix[i][j].root]);
                    p.left = construct_OBST(matrix, i, matrix[i][j].root - 1, keys, prob); 
                    p.right = construct_OBST(matrix, matrix[i][j].root + 1, j, keys, prob);
                }
                return p;
            }

            public OptimalBinaryTreeSearch(T[] elements, int[] weights)
            {
                int count = elements.Length;
                optimalSearchTree(elements, weights, count);
                root = construct_OBST(matrix, 0, count-1, elements, weights);
            }

            static MatrixElement<T>[][] matrix;
            public OptimalTreeNode<T> root = null;
        }
    }
}