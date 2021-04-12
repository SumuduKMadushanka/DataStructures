#include "node_template.h"

/***************************************************************************************************/

template <class T>
Node<T>::Node(T value) : value(value)
{
    this->left_child = nullptr;
    this->right_child = nullptr;
}

template <class T>
Node<T>::~Node()
{
    if (left_child != nullptr) left_child->~Node();
    if (right_child != nullptr) right_child->~Node();
}

/***************************************************************************************************/

template <class T>
void Node<T>::set_value(T value)
{
    this->value = value;
}

template <class T>
T Node<T>::get_value()
{
    return value;
}

/***************************************************************************************************/

template <class T>
void Node<T>::set_left_child(Node<T> *left_child)
{
    this->left_child = left_child;
}

template <class T>
void Node<T>::set_right_child(Node<T> *right_child)
{
    this->right_child = right_child;
}

template <class T>
Node<T>* Node<T>::get_left_child()
{
    return left_child;
}

template <class T>
Node<T>* Node<T>::get_right_child()
{
    return right_child;
}

/***************************************************************************************************/