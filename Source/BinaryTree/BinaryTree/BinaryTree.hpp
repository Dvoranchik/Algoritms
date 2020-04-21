#pragma once
#include "../Predicats/Predicats.hpp"
#include "../TreeNode/TreeNode.hpp"
#include <iostream>
#include <queue>
#include <stack>
using std::stack;
using std::queue;
using std::cout;

namespace Borodin {
	namespace BinaryTree {

		template<typename T>
		class BinaryTree
		{
		public:

			BinaryTree(TreeNode<T> *ptr = nullptr) :_root(ptr) {}
			BinaryTree<T>(const BinaryTree<T>& right);

			~BinaryTree();

			bool Find(T item);

			TreeNode<T>* GetRoot();
			TreeNode<T>* FindMin(TreeNode<T>*ptr);
			TreeNode<T>* Find(TreeNode<T>* ptr, T item);

			void OrderPrint(std::string &str);
			void Insert(T item);
			void PrintTree(std::string &str);
			void ClearAll();
			void Remove(T item);

		private:
			void orderPrint(TreeNode<T> *root, std::string& result);
			void print_Tree(TreeNode<T>* ptr, std::string &result, int level = 0);
			TreeNode<T>* _root;
			TreeNode<T>* Insert(TreeNode<T> *ptr, T item);
			TreeNode<T>* RemoveItem(T item, TreeNode<T>* ptr);
			TreeNode<T>* CopyTree(TreeNode<T> * node);
			void Clear(TreeNode<T>* ptr);
		};

		template<typename T>
		TreeNode<T>* BinaryTree<T>::Insert(TreeNode<T> *ptr, T item)
		{
			Predicats pred;
			if (ptr == nullptr) {
				ptr = new TreeNode<T>(item);
			}
			else if (pred(item, ptr->data))
				ptr->right = Insert(ptr->right, item);
			else
				ptr->left = Insert(ptr->left, item);
			return ptr;
		}

		template<typename T>
		TreeNode<T>* BinaryTree<T>::RemoveItem(T item, TreeNode<T>* ptr)
		{
			if (ptr == nullptr)
				return ptr;
			if (item < ptr->data)
				ptr->left = RemoveItem(item, ptr->left);
			else if (item > ptr->data)
				ptr->right = RemoveItem(item, ptr->right);
			else if (ptr->left != nullptr && ptr->right != nullptr) {
				ptr->data = FindMin(ptr->right)->data;
				ptr->right = RemoveItem(ptr->data, ptr->right);
			}
			else {
				if (ptr->left != nullptr)
					ptr = ptr->left;
				else if (ptr->right != nullptr) {
					ptr = ptr->right;
				}
				else {
					delete ptr;
					ptr = nullptr;
				}
			}
			return ptr;
		}

		template<typename T>
		inline void BinaryTree<T>::Remove(T item)
		{
			RemoveItem(item, _root);
		}

		template<typename T>
		inline TreeNode<T>* BinaryTree<T>::GetRoot()
		{
			return _root;
		}

		template<typename T>
		inline TreeNode<T>* BinaryTree<T>::CopyTree(TreeNode<T>* node)
		{
			if (node == nullptr)
				return nullptr;

			TreeNode<T> * newnode = new TreeNode<T>(node->data);
			newnode->left = CopyTree(node->left);
			newnode->right = CopyTree(node->right);

			return newnode;
		}

		template<typename T>
		inline void BinaryTree<T>::Clear(TreeNode<T>* ptr)
		{
			if (ptr != nullptr) {
				Clear(ptr->left);
				Clear(ptr->right);
				delete ptr;
				ptr = nullptr;
			}
		}

		template<typename T>
		inline TreeNode<T>* BinaryTree<T>::FindMin(TreeNode<T>* ptr)
		{
			if (ptr->left == nullptr) {
				return ptr;
			}
			return FindMin(ptr->left);
		}

		template<typename T>
		inline BinaryTree<T>::~BinaryTree()
		{
			Clear(_root);
			_root = nullptr;
		}

		template<typename T>
		inline void BinaryTree<T>::print_Tree(TreeNode<T>* ptr, std::string & result, int level)
		{
			if (ptr)
			{
				std::ostringstream ost;
				ost << ptr->data;
				print_Tree(ptr->right, result, level + 1);
				for (int i = 0; i < level; i++) {
					result += "   ";
				}
				result += ost.str() + '\n';
				print_Tree(ptr->left, result, level + 1);

			}
		}

		template<typename T>
		inline void BinaryTree<T>::ClearAll()
		{
			Clear(_root);
		}

		template<typename T>
		inline bool BinaryTree<T>::Find(T item)
		{
			if (Find(_root, item) != nullptr)
				return true;
			return false;
		}

		template<typename T>
		inline TreeNode<T>* BinaryTree<T>::Find(TreeNode<T>* ptr, T item)
		{
			if (ptr == nullptr || item == ptr->data)
				return ptr;
			if (item < ptr->data) {
				return Find(ptr->left, item);
			}
			else {
				return Find(ptr->right, item);
			}
		}

		template<typename T>
		inline void BinaryTree<T>::OrderPrint(std::string &str)
		{
			orderPrint(_root, str);
		}

		template<typename T>
		inline void BinaryTree<T>::Insert(T item)
		{
			TreeNode<T>* node = Insert(_root, item);
			if (_root == nullptr)
				_root = node;
		}

		template<typename T>
		inline void BinaryTree<T>::PrintTree(std::string &str)
		{
			print_Tree(_root, str);
		}

		template<typename T>
		void BinaryTree<T>::orderPrint(TreeNode<T>* root, std::string& result)
		{
			if (root == nullptr)  
			{
				return;
			}
			std::ostringstream ost;
			ost << root->data;
			
			orderPrint(root->left, result);   
			result += ost.str();
			orderPrint(root->right, result);  
		}
	
		template<typename T>
		inline BinaryTree<T>::BinaryTree(const BinaryTree<T>& right)
		{
			_root = CopyTree(right._root);
		}
	}
}
	