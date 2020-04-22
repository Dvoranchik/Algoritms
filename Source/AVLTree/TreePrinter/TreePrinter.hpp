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
            int h = 0;
            void visitBinaryTree(Node<T>* binNode)
            {
                int current_level = level;
                if (binNode->left != nullptr)
                {
                    ++h;
                    os << "    " << "struct" << h << "[label=\"" << binNode->left->data << "." << binNode->left->height << "\"color=blue]";
                    os << "    " << "struct" << current_level << " -> " << "struct" << h << ";\n";
                    binNode->left->accept(this);
                    --h;
                }
                if (binNode->right != nullptr)
                {
                    ++h;
                    os << "    " << "struct" << h << "[label=\"" << binNode->right->data << "." <<binNode->right->height << "\"color=red]";
                    os << "    " << "struct" << current_level << " -> " << "struct" << h << ";\n";
                    binNode->right->accept(this);
                    --h;
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
                    os << "    " << node->data << ";\n";
                else {
                    int level = 0;
                    os << "    " << "struct" << level << "[label=\"" << node->data << "." << node->height << "\",color=green]";
                    node->accept(this);
                }
                os << "}\n";
            }
        };
	}
}
