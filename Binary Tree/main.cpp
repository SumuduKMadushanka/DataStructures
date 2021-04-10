#include <iostream>
#include <cstdlib>
#include <ctime>

#include "binary_tree.h"

int main()
{
    srand(time(NULL));

    BinaryTree b_tree;
    int tmp;
    for (int i = 0; i < 100; i++)
    {
        tmp = rand() % 1000;
        std::cout << tmp << " ";
        b_tree.insert_value(tmp);
    }
    std::cout << std::endl;
    std::cout << std::endl;
    b_tree.print_binary_tree();
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 100; i++)
    {
        tmp = rand() % 1000;
        std::cout << tmp << " " << b_tree.search_value(tmp) << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 1000; i++)
    {
        tmp = rand() % 1000;
        std::cout << tmp << " ";
        b_tree.delete_value(tmp);
    }
    std::cout << std::endl;
    std::cout << std::endl;
    b_tree.print_binary_tree();
    std::cout << std::endl;

    return 0;
}