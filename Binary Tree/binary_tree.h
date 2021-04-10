#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
#include "node.h"

class BinaryTree
{
    private:
        Node *root;

    public:
        BinaryTree();
        ~BinaryTree();

        void insert_value(int value);
        
        bool search_value(int value);
        bool search_value(Node *node, int value);

        void delete_value(int value);

        Node* get_min();
        Node* get_min(Node *node);

        Node* get_max();
        Node* get_max(Node *node);

        void print_binary_tree();
        void print_binary_tree(Node *Node);


};

#endif