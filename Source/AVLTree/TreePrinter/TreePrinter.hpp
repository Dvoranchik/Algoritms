#pragma once
#include "../AVLNode/AVLNode.hpp"
#include "../TreeVisitor/TreeVisitor.hpp"
#include <iostream>
#include <map>


namespace Borodin {
	namespace AVLTree {

        template <typename T>
        class TreePrinter : public TreeVisitor<T>
        {
            std::ostream& os;
            void visitBinaryTree(Node<T>* binNode)
            {
                int current_level = level;
                if (binNode->left != nullptr)
                {
                    ++level;
                    os << "    " << "struct" << level << "[label=\"" << binNode->left->key << "." << binNode->left->height << "\"color=blue]";
                    os << "    " << "struct" << current_level << " -> " << "struct" << level << ";\n";
                    binNode->left->accept(this);
                }
                if (binNode->right != nullptr)
                {
                    ++level;
                    os << "    " << "struct" << level << "[label=\"" << binNode->right->key << "." <<binNode->right->height << "\"color=red]";
                    os << "    " << "struct" << current_level << " -> " << "struct" << level << ";\n";
                    binNode->right->accept(this);
                }
            }

        public:
            TreePrinter(std::ostream& ostream) : os(ostream) {}

            int level = 0;

            void visitAdd(Node<T>* addExpr) override
            {
                visitBinaryTree(addExpr);
            }

            void PrintInString(Node<T>* node)
            {
                os << "digraph BST {\n";
                os << "    node [fontname=\"Arial\"];\n";

                if (!node)
                    os << "\n";
                else if (!node->right && !node->left)
                    os << "    " << "struct" << level << "[label=\"" << node->key << "." << node->height << "\",color=green]";
                else {
                    int level = 0;
                    os << "    " << "struct" << level << "[label=\"" << node->key << "." << node->height << "\",color=green]";
                    node->accept(this);
                }
                os << "}\n";
            }
        };
	}
}
