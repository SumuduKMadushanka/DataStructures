#ifndef NODE
#define NODE

class Node
{
    private:
        int value;
        Node *left_child;
        Node *right_child;

    public:
        Node(int value);
        ~Node();

        void set_value(int value);
        int get_value();

        void set_left_child(Node *left_child);
        void set_right_child(Node *right_child);
        Node* get_left_child();
        Node* get_right_child();
};

#endif