#include "dynamic_array.h"

/***************************************************************************************************/

template <class T>
DynamicArray<T>::DynamicArray(int size, int step_size) : size(size), step_size(step_size)
{
    array = new T[size];
    element_count = 0;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] array;
}

/***************************************************************************************************/

template <class T>
void DynamicArray<T>::insert_to_end(T value)
{
    if(element_count >= size) grow_array();

    array[element_count++] = value;
}

template <class T>
void DynamicArray<T>::insert_to_front(T value)
{
    insert_to_index(value, 0);
}

template <class T>
void DynamicArray<T>::insert_to_index(T value, int index)
{
    if(element_count >= size) grow_array();
    if (element_count >= index) memmove(array + index + 1, array + index, (element_count - index) * sizeof array);
    
    array[index] = value;
    element_count++;
}

/***************************************************************************************************/

template <class T>
void DynamicArray<T>::delete_from_end()
{
    if (element_count != 0)
    {
        array[element_count - 1] = array[element_count];
        element_count--;
        if (element_count < size - step_size) shrink_array();
    }
}

template <class T>
void DynamicArray<T>::delete_from_front()
{
    delete_by_index(0);
}

template <class T>
void DynamicArray<T>::delete_by_value(T value)
{
    int index = get_index_by_value(value);
    if (index != -1) delete_by_index(index);
}

template <class T>
void DynamicArray<T>::delete_by_index(int index)
{
    if (index < element_count)
    {
        memmove(array + index, array + index + 1, (--element_count - index) * sizeof array);
        if (element_count < size - step_size) shrink_array();
    }
}

/***************************************************************************************************/

template <class T>
bool DynamicArray<T>::search_value(T value)
{
    if (get_index_by_value(value) != -1) return true;
    return false;
}

/***************************************************************************************************/

template <class T>
T DynamicArray<T>::get_value_by_index(int index)
{
    if (index < element_count) return array[index];
    return false;
}

/***************************************************************************************************/

template <class T>
int DynamicArray<T>::get_index_by_value(T value)
{
    int index = 0;
    while(index < element_count && array[index] != value) index++;
    if (index < element_count) return index;
    else return -1;
}

/***************************************************************************************************/

template <class T>
void DynamicArray<T>::print_array()
{
    for (int i = 0; i < element_count; i++) std::cout << array[i] << " ";
    std::cout << std::endl;
}

/***************************************************************************************************/

template <class T>
void DynamicArray<T>::grow_array()
{
    size += step_size;
    T *tmp_array = new T[size];
    memcpy(tmp_array, array, element_count * sizeof array);
    delete[] array;
    array = tmp_array;
    // std::cout << "Array Grow to " << size << std::endl; // For test the code

}

template <class T>
void DynamicArray<T>::shrink_array()
{
    size -= step_size;
    T *tmp_array = new T[size];
    memcpy(tmp_array, array, element_count * sizeof array);
    delete[] array;
    array = tmp_array;
    // std::cout << "Array Shrink to " << size << std::endl; // For test the code
}

/***************************************************************************************************/