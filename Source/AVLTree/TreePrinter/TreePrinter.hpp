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
                    dictonary[binNode->left->data]++;
                    os << "    " << "struct" << h << "[label=\"" << binNode->left->data << "." << dictonary[binNode->left->data] << "\"color=blue]";
                    os << "    " << "struct" << current_level << " -> " << "struct" << h << ";\n";
                    binNode->left->accept(this);
                    --h;
                }
                if (binNode->right != nullptr)
                {
                    ++h;
                    dictonary[binNode->right->data]++;
                    os << "    " << "struct" << h << "[label=\"" << binNode->right->data << "." << dictonary[binNode->right->data] << "\"color=red]";
                    os << "    " << "struct" << current_level << " -> " << "struct" << h << ";\n";
                    binNode->right->accept(this);
                    --h;
                }
            }

        public:
            TreePrinter(std::ostream& ostream) : os(ostream) {}

            std::map<T, int> dictonary;

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
                    dictonary[node->data]++;
                    os << "    " << "struct" << level << "[label=\"" << node->data << "." << dictonary[node->data] << "\",color=green]";
                    node->accept(this);
                }
                os << "}\n";
            }
        };
	}
}
