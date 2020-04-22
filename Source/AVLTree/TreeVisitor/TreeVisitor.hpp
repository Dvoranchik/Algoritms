#pragma once


namespace Borodin {
	namespace AVLTree {
		template <typename T>
		class Node;

		template <typename T>
		class TreeVisitor {
		public:
			virtual void visitAdd(Node<T>* ptr) = 0;
		};
	}
}