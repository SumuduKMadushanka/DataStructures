#ifndef NODE
#define NODE

template <class T>
class Node
{
    private:
        T value;
        Node<T> *next_node;
        Node<T> *prev_node;

    public:
        Node(T value);
        ~Node();

        T get_value();

        void set_next_node(Node<T> *next_node);
        void set_prev_node(Node<T> *prev_node);
        Node<T>* get_next_node();
        Node<T>* get_prev_node();
};

#endif