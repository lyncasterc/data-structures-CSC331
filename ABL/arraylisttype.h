#ifndef ArrayListType_H
#define ArrayListType_H
#include <cassert>
#include <iostream>

template<typename T>
class ArrayListType
{
    private:
        T *list;
        int max_size;
        int length;
    public:
        ArrayListType(int size = 100);
        ArrayListType(const ArrayListType<T> &other_list);
        bool isEmpty() const;
        bool isFull() const;
        int listSize() const;
        int maxListSize() const;
        void print() const;
        bool isItemAtEqual(int location, const T &item) const;
        void insertAt(int location, const T &item);
        void insertEnd(const T &item);
        void removeAt(int location);
        void retrieveAt(int location, T &item) const;
        void replaceAt(int location, const T &item);
        void clearList();
        int seqSearch(const T &item) const;
        void insert(const T &item);
        void remove(const T &item);
        ArrayListType& operator= (const ArrayListType &list);
        ~ArrayListType();
};

template<typename T>
ArrayListType<T>::ArrayListType(int size)
{
    if(size < 0)
    {
        std::cout << "Error: Size must be positive integer. Defaulting to size of 100" << std::endl;
        max_size = 100;
    }
    else
    {
        max_size = size;
    }

    list = new T[max_size];
    assert(list);
    length = 0;
    
}

template<typename T>
ArrayListType<T>::ArrayListType(const ArrayListType<T> &other_list)
{
    max_size = other_list.max_size;
    length = other_list.length;
    list = new T[max_size];
    assert(list);

    for (int i = 0; i < length; i++)
    {
        list[i] = other_list.list[i];
    }
    
}

template<typename T>
bool ArrayListType<T>::isEmpty() const { return length == 0; }

template<typename T>
bool ArrayListType<T>::isFull() const { return length == max_size; }

template<typename T>
int ArrayListType<T>::listSize() const { return length; }

template<typename T>
int ArrayListType<T>::maxListSize() const { return max_size; }

template<typename T>
void ArrayListType<T>::print() const 
{ 
    for (int i = 0; i < length; i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
bool ArrayListType<T>::isItemAtEqual(int location, const T &item) const
{
    return list[location] == item;
}

template<typename T>
void ArrayListType<T>::insertAt(int location, const T &item)
{
    if(length >= max_size)
    {
        std::cout << "Error: List is full" << std::endl;
    }
    else if(location >= max_size || location < 0)
    {
        std::cout << "Error: Out of range" << std::endl;
    }
    else
    {
        for (int i = length - 1; i >= location; i--)
        {
            list[i + 1] = list[i];
        }
        
        list[location] = item;
        length++;
    }
}

template<typename T>
void ArrayListType<T>::insertEnd(const T &item)
{
    if(isFull())
    {
        std::cout << "Error: List is full" << std::endl;
    }
    else
    {
        list[length++] = item;
    }
}

template<typename T>
void ArrayListType<T>::removeAt(int location)
{
    if(location < 0 || location >= length)
    {
        std::cout << "Error: Out of range" << std::endl;
    }
    else
    {
        for (int i = location; i < length - 1; i++)
        {
            list[i] = list[i + 1];
        }
        length--;
    }
}

template<typename T>
void ArrayListType<T>::retrieveAt(int location, T &item) const
{
    if(location < 0 || location >= length)
    {
        std::cout << "Error: Out of range" << std::endl;

    }
    else
    {
        item = list[location];
    }
}

template<typename T>
void ArrayListType<T>::replaceAt(int location, const T &item) 
{
    if(location < 0 || location >= length)
    {
        std::cout << "Error: Out of range" << std::endl;

    }
    else
    {
        
        list[location] = item;
    }
}

template<typename T>
void ArrayListType<T>::clearList() { length = 0; }

template<typename T>
ArrayListType<T>& ArrayListType<T>::operator= (const ArrayListType &other_list)
{
    // Checking for self-assignment
    if(this == &other_list)
    {
        return *this;
    }

    if(list)
    {
        delete[] list;
    }

    length = other_list.length;
    max_size = other_list.max_size;

    for (int i = 0; i < length; i++)
    {
        list[i] = other_list.list[i];
    }

    return *this;

}

template<typename T>
int ArrayListType<T>::seqSearch(const T &item) const
{  
    for (int i = 0; i < length; i++)
    {
        if(list[i] == item)
        {
            return i;
        }
    }

    return -1;
}

template<typename T>
void ArrayListType<T>::insert(const T &item) 
{
    if(seqSearch(item) != -1)
    {
        std::cout << "Error: Item already exists" << std::endl;
    }
    else if (isFull())
    {
        std::cout << "Error: List is full" << std::endl;
    }
    else
    {
        insertEnd(item);
    }
}

template<typename T>
void ArrayListType<T>::remove(const T &item) 
{
    int location = seqSearch(item);

    if(location == -1)
    {
        std::cout << "Error: Item not found" << std::endl;
    }

    else
    {
        removeAt(location);
    }
}

template<typename T>
ArrayListType<T>::~ArrayListType() { delete []list; }

#endif