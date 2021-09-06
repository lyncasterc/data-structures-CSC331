#ifndef SortedLinkedList_H
#define SortedLinkedList_H
#include "linked_list.h"
#include <iostream>


template<typename T>
class SortedLinkedList : public LinkedList<T>
{
    public:
        using LinkedList<T>::LinkedList;
        virtual void insertItem(const T &item);
        // virtual void deleteItem(const T &item);
        // virtual bool searchItem(const T &item) const;
};

template<typename T>
void SortedLinkedList<T>::insertItem(const T &item)
{
    Node<T> *new_node;
    new_node = new Node<T>;
    new_node->data = item;

    if(!this->head || this->head->data > item)
    {
        new_node->next = this->head;
        this->head = new_node;
    }

    else
    {
        Node<T> *temp, *prev;
        temp = this->head->next;
        prev = this->head;

        while(temp && item > temp->data)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = new_node;
        new_node->next = temp;
    }
}






#endif