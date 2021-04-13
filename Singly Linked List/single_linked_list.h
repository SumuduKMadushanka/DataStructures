#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

#include <iostream>
#include "node.h"
#include "node.cpp"

template <class T>
class SingleLinkedList
{
    private:
        Node<T> *head;
        Node<T> *tail;

    public:
        SingleLinkedList();
        ~SingleLinkedList();

        void insert_value(T value);

        void delete_value(T value);
        T get_and_delete_end();
        T get_and_delete_front();
        
        T get_head_value();
        T get_tail_value();

        bool search_value(T value);

        void print_list();
};

#endif