#include <iostream>
#include <cstdlib>
#include <ctime>

#include "double_linked_list.h"
#include "double_linked_list.cpp"

int main()
{
    srand(time(NULL));

    DoubleLinkedList<int> d_list;
    for (int i = 0; i < 100; i++)
    {
        d_list.insert_value(rand() % 1000);
    }
    d_list.print_list();
    std::cout << std::endl;
    std::cout << std::endl;

    int tmp;
    for (int i = 0; i < 100; i++)
    {
        tmp = rand() % 1000;
        std::cout << tmp << " " << d_list.search_value(tmp) << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 100; i++)
    {
        tmp = rand() % 1000;
        std::cout << tmp << " ";
        d_list.delete_value(tmp);
    }
    std::cout << std::endl;
    std::cout << std::endl;
    d_list.print_list();
    std::cout << std::endl;

    std::cout << d_list.get_and_delete_end() << " " << d_list.get_and_delete_front() << std::endl;
    std::cout << d_list.get_head_value() << " " << d_list.get_tail_value() << std::endl;
    d_list.print_list();

    return 0;
}