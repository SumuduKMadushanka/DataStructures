#include "single_linked_list.h"

/***************************************************************************************************/

template <class T>
SingleLinkedList<T>::SingleLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template <class T>
SingleLinkedList<T>::~SingleLinkedList()
{
    Node<T> *tmp = nullptr;
    Node<T> *tmp_next = head;
    while (tmp_next != nullptr)
    {
        tmp = tmp_next;
        tmp_next = tmp->get_next_node();
        delete tmp;
    }

    if (tmp != nullptr)
    {
        delete tmp;
    }
}

/***************************************************************************************************/

template <class T>
void SingleLinkedList<T>::insert_value(T value)
{
    Node<T> *tmp_node = new Node<T>(value);
    if (head == nullptr)
    {
        head = tmp_node;
        tail = head;
    }
    else
    {
        tail->set_next_node(tmp_node);
        tail = tail->get_next_node();
    }
}

/***************************************************************************************************/

template <class T>
void SingleLinkedList<T>::delete_value(T value)
{
    Node<T> *pre_node = nullptr;
    Node<T> *current_node = head;
    while (current_node != nullptr && current_node->get_value() != value)
    {
        pre_node = current_node;
        current_node = current_node->get_next_node();
    }
    
    if(current_node != nullptr)
    {
        if (current_node->get_next_node() == nullptr) tail = pre_node;

        if (pre_node != nullptr) pre_node->set_next_node(current_node->get_next_node());
        else head = current_node->get_next_node();
        
        delete current_node;
    }
}

template <class T>
T SingleLinkedList<T>::get_and_delete_end()
{
    if (tail != nullptr)
    {
        T value = tail->get_value();
        delete_value(value);
        return value;
    }
}

template <class T>
T SingleLinkedList<T>::get_and_delete_front()
{
    if (head != nullptr)
    {
        T value = head->get_value();
        delete_value(value);
        return value;
    }
}

/***************************************************************************************************/

template <class T>
T SingleLinkedList<T>::get_head_value()
{
    if (head != nullptr) return head->get_value();
}

template <class T>
T SingleLinkedList<T>::get_tail_value()
{
    if (tail != nullptr) return tail->get_value();
}

/***************************************************************************************************/

template <class T>
bool SingleLinkedList<T>::search_value(T value)
{
    Node<T> *current_node = head;
    while (current_node != nullptr && current_node->get_value() != value)
    {
        current_node = current_node->get_next_node();
    }

    if (current_node != nullptr) return true;
    return false;
}

/***************************************************************************************************/

template <class T>
void SingleLinkedList<T>::print_list()
{
    Node<T> *current_node = head;
    while (current_node != nullptr)
    {
        std::cout << current_node->get_value() << " ";
        current_node = current_node->get_next_node();
    }
    std::cout << std::endl;
}

/***************************************************************************************************/