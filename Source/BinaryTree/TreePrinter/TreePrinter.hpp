#pragma once
#include "../TreeVisitor/TreeVisitor.hpp"
#include "../BinaryTree/BinaryTree.hpp"
#include <iostream>
#include <map>

namespace Borodin {
	namespace BinaryTree {
        template <typename T>
        class TreePrinter : public TreeVisitor<T> 
        {
            std::ostream& os;
            int h = 0;
            void visitBinaryTree(TreeNode<T>* binNode, int& level)
            {
                int current_level = level;
                if (binNode->left != nullptr)
                {
                    ++h;
                    dictonary[binNode->left->data]++;
                    os << "    " << "struct" << level + 1 << "[label=\"" << binNode->left->data << "." << dictonary[binNode->left->data] << "\"color=blue]";
                    os << "    " <<"struct"<< current_level << " -> " << "struct" <<level+1<< ";\n";
                    binNode->left->accept(this, ++level);
                    --h;
                }
                if (binNode->right != nullptr)
                {
                    ++h;
                    dictonary[binNode->right->data]++;
                    os << "    " << "struct" << level + 1 << "[label=\"" << binNode->right->data << "." << dictonary[binNode->right->data] << "\"color=red]";
                    os << "    " << "struct" << current_level <<" -> " << "struct" << level + 1 << ";\n";
                    binNode->right->accept(this, ++level);
                    --h;
                }
            }

        public:
            TreePrinter(std::ostream& ostream) : os(ostream){}
            
            std::map<T, int> dictonary;


            void visitAdd(TreeNode<T>* addExpr, int& level) override
            {
                visitBinaryTree(addExpr, level);
            }

            void PrintInString(TreeNode<T>* node) 
            {
                os << "digraph BST {\n";
                os <<"    node [fontname=\"Arial\"];\n";

                if (!node)
                    os << "\n";
                else if (!node->right && !node->left)
                    os << "    " << node->data << ";\n";
                else {
                    int level = 0;
                    dictonary[node->data]++;
                    os << "    " << "struct" << level << "[label=\"" << node->data << "." << dictonary[node->data] << "\",color=green]";
                    node->accept(this, level);
                }
               os << "}\n";
            }
        };
	}
}