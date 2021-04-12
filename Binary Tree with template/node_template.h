#ifndef NODE
#define NODE

template <class T>
class Node
{
    private:
        T value;
        Node<T> *left_child;
        Node<T> *right_child;

    public:
        Node(T value);
        ~Node();

        void set_value(T value);
        T get_value();

        void set_left_child(Node<T> *left_child);
        void set_right_child(Node<T> *right_child);
        Node<T>* get_left_child();
        Node<T>* get_right_child();
};

#endif