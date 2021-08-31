#ifndef Array_H
#define Array_H


class Array
{
    private: 
        int *A{};
        int size{};
        int length = 0;

    public: 
        Array();
        Array(int size);
        void insert(int val);
        int getLength() { return length; }
        void print();

};  

#endif