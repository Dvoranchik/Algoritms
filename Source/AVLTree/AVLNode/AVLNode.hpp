#pragma once
#include "../TreeVisitor/TreeVisitor.hpp"


namespace Borodin {
	namespace AVLTree {
        template<typename T>
        class Node
        {
            public:
                T key;
                Node* left;
                Node* right;
                int height;

                void accept(TreeVisitor<T>* visitor) {
                    visitor->visitAdd(this);
                }
        };

	}
}