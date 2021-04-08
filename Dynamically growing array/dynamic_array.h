#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include <iostream>
#include <cstring>

template <class T>
class DynamicArray
{
    private:
        T *array;
        int size;
        int step_size;
        int element_count;

        void grow_array();
        void shrink_array();

    public:
        DynamicArray(int size = 100, int step_size = 50);
        ~DynamicArray();
        
        void insert_to_end(T value);
        void insert_to_front(T value);
        void insert_to_index(T value, int index);
        
        void delete_from_end();
        void delete_from_front();
        void delete_by_value(T value);
        void delete_by_index(int index);

        bool search_value(T value);
        
        T get_value_by_index(int index);

        int get_index_by_value(T value);

        void print_array();
};

#endif