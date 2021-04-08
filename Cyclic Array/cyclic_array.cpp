#include "cyclic_array.h"

/***************************************************************************************************/

template <class T>
CyclicQueue<T>::CyclicQueue(int size) : size(size), elements(0)
{
    array = new T[size];
    head = 0;
    tail = 0;
}

template <class T>
CyclicQueue<T>::~CyclicQueue()
{
    delete[] array;
}

/***************************************************************************************************/
template <class T>
void CyclicQueue<T>::insert_value(T value)
{
    array[tail] = value;
    tail = (tail + 1) % size;

    if (elements == size)
    {
        head = (head + 1) % size;
    }
    else
    {
        elements++;
    }
}

/***************************************************************************************************/

template <class T>
T CyclicQueue<T>::get_value()
{
    if (elements != 0)
    {
        T val = array[head];
        head = (head + 1) % size;
        elements--;
        return val;
    }
}

/***************************************************************************************************/

template <class T>
void CyclicQueue<T>::print_array()
{
    for (int i = 0; i < elements; i++)
    {
        std::cout << array[(head + i) % size] << " ";
    }
    std::cout << std::endl;
}

/***************************************************************************************************/