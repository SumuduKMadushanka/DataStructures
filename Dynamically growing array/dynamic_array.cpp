#include <iostream>
#include <cstring>

template <typename T>
class DynamicArray
{
    private:
        T *array;
        int size;
        int step_size;
        int element_count;
        
        void grow_array()
        {
            size += step_size;
            T *tmp_array = new T[size];
            memcpy(tmp_array, array, element_count * sizeof array);
            delete[] array;
            array = tmp_array;
            // std::cout << "Array Grow to " << size << std::endl; // For test the code

        }
        void shrink_array()
        {
            size -= step_size;
            T *tmp_array = new T[size];
            memcpy(tmp_array, array, element_count * sizeof array);
            delete[] array;
            array = tmp_array;
            // std::cout << "Array Shrink to " << size << std::endl; // For test the code
        }

    public:
        DynamicArray(int size = 100, int step_size = 50) : size(size), step_size(step_size)
        {
            array = new T[size];
            element_count = 0;
        }
        ~DynamicArray()
        {
            delete[] array;
        }
        
        void insert_to_end(T value)
        {
            if(element_count >= size) grow_array();

            array[element_count++] = value;
        }
        void insert_to_front(T value)
        {
            insert_to_index(value, 0);
        }
        void insert_to_index(T value, int index)
        {
            if(element_count >= size) grow_array();
            if (element_count >= index) memmove(array + index + 1, array + index, (element_count - index) * sizeof array);
            
            array[index] = value;
            element_count++;
        }
        
        void delete_from_end()
        {
            if (element_count != 0)
            {
                array[element_count - 1] = array[element_count];
                element_count--;
                if (element_count < size - step_size) shrink_array();
            }
        }
        void delete_from_front()
        {
            delete_by_index(0);
        }
        void delete_by_value(T value)
        {
            int index = get_index_by_value(value);
            if (index != -1) delete_by_index(index);
        }
        void delete_by_index(int index)
        {
            if (index < element_count)
            {
                memmove(array + index, array + index + 1, (--element_count - index) * sizeof array);
                if (element_count < size - step_size) shrink_array();
            }
        }

        bool search_value(T value)
        {
            if (get_index_by_value(value) != -1) return true;
            return false;
        }
        
        T get_value_by_index(int index)
        {
            if (index < element_count) return array[index];
            return false;
        }

        int get_index_by_value(T value)
        {
            int index = 0;
            while(index < element_count && array[index] != value) index++;
            if (index < element_count) return index;
            else return -1;
        }

        void print_array()
        {
            for (int i = 0; i < element_count; i++) std::cout << array[i] << " ";
            std::cout << std::endl;
        }
};

int main()
{
    DynamicArray<int> array(3, 1);
    array.insert_to_end(45);
    array.insert_to_end(46);
    array.insert_to_end(47);
    array.insert_to_end(49);
    array.insert_to_front(500);
    array.insert_to_index(250, 2);

    array.print_array();
    array.delete_by_value(46);
    array.delete_by_value(49);
    array.print_array();

    std::cout << "250 " << array.search_value(250) << std::endl;
    std::cout << "260 " << array.search_value(260) << std::endl;
    std::cout << "index of 250 " << array.get_index_by_value(250) << std::endl;
    std::cout << "value of 3 " << array.get_value_by_index(3) << std::endl;

    return 0;
}