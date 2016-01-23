///finalquiz.cpp

double max(double a, double b);

void swap(int &a, int &b);

int& getLargestElement(const int *array,int length);

//what's wrong?
int& doSomething()
{
    int array[] = { 1, 2, 3, 4, 5 };
    return array[3];
} //array cease to exist

int sumTo(int value)
{
    return value + sumTo(value - 1);
} //no basecase
//c
float divide(float x, float y)
{
    return x / y;
}

double divide(float x, float y)
{
    return x / y;
}//functions evaluated by parameters

#include <iostream>

int main()
{
    int array[100000000];

    for (const auto &x: array)
        std::cout << x << ' ';

    return 0;
}
//
#include <iostream>

int main(int argc, int *argv[])
{
    int times = argv[1];
    for (int count = 0; count < times; count++)
        std::cout << count << ' ';

    return 0;
}