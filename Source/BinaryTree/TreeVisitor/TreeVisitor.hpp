#pragma once

namespace Borodin {
    namespace BinaryTree {
		template <typename T>
		class TreeNode;

		template <typename T>
		class TreeVisitor {
		public:
			virtual void visitAdd(TreeNode<T>* ptr, int& level) = 0;
		};
    }
}