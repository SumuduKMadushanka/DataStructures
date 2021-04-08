#include <iostream>
#include <cstring>
#include "dynamic_array.h"
#include "dynamic_array.cpp"

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