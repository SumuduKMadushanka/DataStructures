#ifndef CYCLIC_ARRAY
#define CYCLIC_ARRAY

#include <iostream>

template <class T>
class CyclicQueue
{
    private:
        T *array;
        int head;
        int tail;
        int size;
        int elements;

    public:
        CyclicQueue(int size);
        ~CyclicQueue();

        void insert_value(T value);

        T get_value();

        void print_array();
};

#endif