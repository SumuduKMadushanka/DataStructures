#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class CyclicQueue
{
    private:
        T *array;
        int head;
        int tail;
        int size;
        int elements;

    public:
        CyclicQueue(int size) : size(size), elements(0)
        {
            array = new T[size];
            head = 0;
            tail = 0;
        }
        ~CyclicQueue()
        {
            delete[] array;
        }

        void insert_value(T value)
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

        T get_value()
        {
            if (elements != 0)
            {
                T val = array[head];
                head = (head + 1) % size;
                elements--;
                return val;
            }
        }

        void print_array()
        {
            for (int i = 0; i < elements; i++)
            {
                std::cout << array[(head + i) % size] << " ";
            }
            std::cout << std::endl;
        }
};

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