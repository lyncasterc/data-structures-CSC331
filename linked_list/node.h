#ifndef Node_H
#define Node_H

template<typename T>
class Node
{
    public:
        T data;
        Node<T> *next;
};

#endif