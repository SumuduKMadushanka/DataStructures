#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cyclic_array.h"
#include "cyclic_array.cpp"

int main()
{
    srand(time(NULL));
    
    CyclicQueue<int> c_array(20);
    for (int iter = 0; iter < 5; iter++)
    {
        for (int i = 0; i < 15; i++) c_array.insert_value(rand() % 1000);

        for (int i = 0; i < 12; i++) std::cout << c_array.get_value() << " ";
        std::cout << std::endl;
    }

    c_array.print_array();

    return 0;
}