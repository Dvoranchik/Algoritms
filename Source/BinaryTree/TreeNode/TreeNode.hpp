#pragma once
#include "../TreeVisitor/TreeVisitor.hpp"



namespace Borodin {
	namespace BinaryTree {


		template<typename T>
		struct ITreeNode {
		public:
			virtual ~ITreeNode() = default;
			virtual void accept(TreeVisitor<T>*, int&) = 0;
		};


		template<typename T>
		struct  TreeNode : public ITreeNode<T>
		{
			TreeNode(T item) : data(item), left(nullptr), right(nullptr) {}
			T data;
			TreeNode* left;
			TreeNode* right;
			
			void accept(TreeVisitor<T>* visitor, int& level) override {
				visitor->visitAdd(this, level);
			}
		};
	}
}