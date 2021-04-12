#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
#include "node_template.h"
#include "node_template.cpp"

template <class T>
class BinaryTree
{
    private:
        Node<T> *root;

    public:
        BinaryTree();
        ~BinaryTree();

        void insert_value(T value);
        
        bool search_value(T value);
        bool search_value(Node<T> *node, T value);

        void delete_value(T value);

        Node<T>* get_min();
        Node<T>* get_min(Node<T> *node);

        Node<T>* get_max();
        Node<T>* get_max(Node<T> *node);

        void print_binary_tree();
        void print_binary_tree(Node<T> *Node);


};

#endif