#pragma once
#include <iostream>
#include "../AVLNode/AVLNode.hpp"

namespace Borodin {
	namespace AVLTree {

		template<typename T>
		class AVLTree
		{
		public:
			int max(int a, int b)
			{
				return (a > b) ? a : b;
			}

			T height(Node<T>* N)
			{
				if (N == NULL)
					return 0;
				return N->height;
			}

			Node<T>* newNode(T key)
			{
				Node<T>* node = new Node<T>();
				node->key = key;
				node->left = NULL;
				node->right = NULL;
				node->height = 1; 
								  
				return(node);
			}

			Node<T>* rightRotate(Node<T>* y)
			{
				Node<T>* x = y->left;
				Node<T>* T2 = x->right;

				x->right = y;
				y->left = T2;

				y->height = max(height(y->left),
					height(y->right)) + 1;
				x->height = max(height(x->left),
					height(x->right)) + 1;

				return x;
			}

			Node<T>* leftRotate(Node<T>* x)
			{
				Node<T>* y = x->right;
				Node<T>* T2 = y->left;

				y->left = x;
				x->right = T2;

				x->height = max(height(x->left),
					height(x->right)) + 1;
				y->height = max(height(y->left),
					height(y->right)) + 1;

				return y;
			}


			int getBalance(Node<T>* N)
			{
				if (N == NULL)
					return 0;
				return height(N->left) -
					height(N->right);
			}


			Node* insert(Node* node, int key)
			{
				if (node == NULL)
					return(newNode(key));

				if (key < node->key)
					node->left = insert(node->left, key);
				else if (key > node->key)
					node->right = insert(node->right, key);
				else 
					return node;

				node->height = 1 + max(height(node->left),
					height(node->right));

				int balance = getBalance(node);

				if (balance > 1 && key < node->left->key)
					return rightRotate(node);

				if (balance < -1 && key > node->right->key)
					return leftRotate(node);

				if (balance > 1 && key > node->left->key)
				{
					node->left = leftRotate(node->left);
					return rightRotate(node);
				}

				if (balance < -1 && key < node->right->key)
				{
					node->right = rightRotate(node->right);
					return leftRotate(node);
				}

				return node;
			}

			Node<T>* minValueNode(Node<T>* node)
			{
				Node<T>* current = node;

				while (current->left != NULL)
					current = current->left;

				return current;
			}

            Node* deleteNode(Node* root, int key)
            {
                if (root == NULL)
                    return root;

                if (key < root->key)
                    root->left = deleteNode(root->left, key);

                else if (key > root->key)
                    root->right = deleteNode(root->right, key);
                else
                {
                    if ((root->left == NULL) ||
                        (root->right == NULL))
                    {
                        Node<T>* temp = root->left ?
                            root->left :
                            root->right;

                        if (temp == NULL)
                        {
                            temp = root;
                            root = NULL;
                        }
                        else 
                            *root = *temp; 

                        delete temp;
                    }
                    else
                    {
                        Node<T>* temp = minValueNode(root->right);

                        root->key = temp->key;

                        root->right = deleteNode(root->right,
                            temp->key);
                    }
                }

                if (root == NULL)
                    return root;

                root->height = 1 + max(height(root->left),
                    height(root->right));

                int balance = getBalance(root);


                if (balance > 1 &&
                    getBalance(root->left) >= 0)
                    return rightRotate(root);

                if (balance > 1 &&
                    getBalance(root->left) < 0)
                {
                    root->left = leftRotate(root->left);
                    return rightRotate(root);
                }

                if (balance < -1 &&
                    getBalance(root->right) <= 0)
                    return leftRotate(root);

                if (balance < -1 &&
                    getBalance(root->right) > 0)
                {
                    root->right = rightRotate(root->right);
                    return leftRotate(root);
                }

                return root;
            }

			void preOrder(Node<T>* root)
			{
				if (root != NULL)
				{
					std::cout << root->key << " ";
					preOrder(root->left);
					preOrder(root->right);
				}
			}
		};
	}
}