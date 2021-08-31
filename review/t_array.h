#ifndef T_Array_H
#define T_Array_H
#include <iostream>


template <typename T>
class T_Array
{
    private: 
        T *A{};
        int size{};
        int length = 0;

    public: 
        T_Array()
        {
            size = 20;
            A = new T[size];
        }
        
        T_Array(int size)
        {
            this->size = size;
            A = new T[size]; 
        }

        void insert(T val)
        {
            if(length < size)
            A[length++] = val;
        }

        int getLength() { return length; }

        void print()
        {
            for (size_t i = 0; i < length; i++)
            {
                std::cout << A[i] << " ";
            }

            std::cout << std::endl;
        }

};  

#endif