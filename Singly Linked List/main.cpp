#include <iostream>
#include <cstdlib>
#include <ctime>

#include "single_linked_list.h"
#include "single_linked_list.cpp"

int main()
{
    srand(time(NULL));

    SingleLinkedList<int> s_list;
    for (int i = 0; i < 100; i++)
    {
        s_list.insert_value(rand() % 1000);
    }
    s_list.print_list();
    std::cout << std::endl;
    std::cout << std::endl;

    int tmp;
    for (int i = 0; i < 100; i++)
    {
        tmp = rand() % 1000;
        std::cout << tmp << " " << s_list.search_value(tmp) << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 100; i++)
    {
        tmp = rand() % 1000;
        std::cout << tmp << " ";
        s_list.delete_value(tmp);
    }
    std::cout << std::endl;
    std::cout << std::endl;
    s_list.print_list();
    std::cout << std::endl;

    std::cout << s_list.get_and_delete_end() << " " << s_list.get_and_delete_front() << std::endl;
    std::cout << s_list.get_head_value() << " " << s_list.get_tail_value() << std::endl;
    s_list.print_list();

    return 0;
}