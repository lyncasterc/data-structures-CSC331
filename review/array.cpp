#include "array.h"
#include <iostream>


Array::Array()
{
    size = 20;
    A = new int[size];
}


Array::Array(int size)
{
    this->size = size;
    A = new int[size];
}


void Array::insert(int val)
{
    if(length < size)
    {
        A[length++] = val;
    }
}


void Array::print()
{
    for (size_t i = 0; i < length; i++)
    {
        std::cout << A[i] << " ";
    }

    std::cout << std::endl;
}
