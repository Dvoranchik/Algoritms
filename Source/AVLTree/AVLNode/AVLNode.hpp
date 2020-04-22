#pragma once

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
        };

	}
}