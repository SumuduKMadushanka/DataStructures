#include "node.h"

/***************************************************************************************************/

Node::Node(int value) : value(value)
{
    this->left_child = nullptr;
    this->right_child = nullptr;
}

Node::~Node()
{
    if (left_child != nullptr) left_child->~Node();
    if (right_child != nullptr) right_child->~Node();
}

/***************************************************************************************************/

void Node::set_value(int value)
{
    this->value = value;
}

int Node::get_value()
{
    return value;
}

/***************************************************************************************************/

void Node::set_left_child(Node *left_child)
{
    this->left_child = left_child;
}

void Node::set_right_child(Node *right_child)
{
    this->right_child = right_child;
}

Node* Node::get_left_child()
{
    return left_child;
}

Node* Node::get_right_child()
{
    return right_child;
}

/***************************************************************************************************/