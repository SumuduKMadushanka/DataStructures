#include "binary_tree_template.h"

/***************************************************************************************************/

template <class T>
BinaryTree<T>::BinaryTree()
{
    this->root = nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    this->root->~Node();
}

/***************************************************************************************************/

template <class T>
void BinaryTree<T>::insert_value(T value)
{
    Node<T> *parent_node = nullptr;
    Node<T> *child_node = root;
    bool left = false;
    while (child_node != nullptr)
    {
        parent_node = child_node;
        if (child_node->get_value() == value) return;
        else if (child_node->get_value() > value)
        {
            child_node = child_node->get_left_child();
            left = true;
        }
        else
        {
            child_node = child_node->get_right_child();
            left = false;
        }
    }
    
    Node<T> *tmp_node = new Node<T>(value);
    if (parent_node == nullptr) root = tmp_node;
    else if (left) parent_node->set_left_child(tmp_node);
    else parent_node->set_right_child(tmp_node);
}

/***************************************************************************************************/

template <class T>
bool BinaryTree<T>::search_value(T value)
{
    return search_value(root, value);
}

template <class T>
bool BinaryTree<T>::search_value(Node<T> *node, T value)
{
    if (node != nullptr)
    {
        if (node->get_value() == value) return true;
        else if (node->get_value() > value) return search_value(node->get_left_child(), value);
        else if (node->get_value() < value) return search_value(node->get_right_child(), value);
    }
    return false;
}

/***************************************************************************************************/

template <class T>
void BinaryTree<T>::delete_value(T value)
{
    Node<T> *parent_node = nullptr;
    Node<T> *child_node = root;
    bool left = false;
    bool found = false;
    while (child_node != nullptr)
    {
        if (child_node->get_value() == value)
        {
            found = true;
            break;
        }
        
        parent_node = child_node;
        if (child_node->get_value() > value)
        {
            child_node = child_node->get_left_child();
            left = true;
        }
        else
        {
            child_node = child_node->get_right_child();
            left = false;
        }
    }

    if (found)
    {
        Node<T> *new_node;
        if (child_node->get_left_child() != nullptr && child_node->get_right_child() == nullptr) new_node = nullptr;
        else if (child_node->get_right_child() == nullptr) new_node = child_node->get_left_child();
        else if (child_node->get_left_child()== nullptr) new_node = child_node->get_right_child();
        else
        {
            int new_value = get_min(child_node->get_right_child())->get_value();
            delete_value(new_value);
            child_node->set_value(new_value);
            return;
        }

        if (left)
        {
            parent_node->set_left_child(new_node);
        }
        else
        {
            parent_node->set_right_child(new_node);
        }
        delete child_node;
    }
}

/***************************************************************************************************/

template <class T>
Node<T>* BinaryTree<T>::get_min()
{
    return get_min(root);
}

template <class T>
Node<T>* BinaryTree<T>::get_min(Node<T> *node)
{
    if (node != nullptr)
    {
        Node<T> *current_node = node;
        while (current_node->get_left_child() != nullptr) current_node = current_node->get_left_child();
        return current_node;
    }
    return node;
}

/***************************************************************************************************/

template <class T>
Node<T>* BinaryTree<T>::get_max()
{
    return get_max(root);
}

template <class T>
Node<T>* BinaryTree<T>::get_max(Node<T> *node)
{
    if (node != nullptr)
    {
        Node<T> *current_node = node;
        while (current_node->get_right_child() != nullptr) current_node = current_node->get_right_child();
        return current_node;
    }
    return node;
}

/***************************************************************************************************/

template <class T>
void BinaryTree<T>::print_binary_tree()
{
    print_binary_tree(root);
    std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::print_binary_tree(Node<T> *node)
{
    if (node != nullptr)
    {
        std::cout << node->get_value() << " ";
        print_binary_tree(node->get_left_child());
        print_binary_tree(node->get_right_child());
    }
}

/***************************************************************************************************/