#include "node.h"

/***************************************************************************************************/

template <class T>
Node<T>::Node(T value) : value(value)
{
    this->next_node = nullptr;
}

template <class T>
Node<T>::~Node()
{
    
}

/***************************************************************************************************/

template <class T>
T Node<T>::get_value()
{
    return value;
}

/***************************************************************************************************/

template <class T>
void Node<T>::set_next_node(Node<T> *next_node)
{
    this->next_node = next_node;
}

template <class T>
Node<T>* Node<T>::get_next_node()
{
    return next_node;
}

/***************************************************************************************************/