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
        virtual void deleteItem(const T &item);
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
template<typename T>
void SortedLinkedList<T>::deleteItem(const T &item)
{
    Node<T> *temp, *prev;

    if(!this->head)
    {
        std::cout << "Error: List is empty" << std::endl;
    }

    else if(this->head->data == item)
    {
        temp = this->head;
        this->head = this->head->next;
        delete temp;
    }

    else
    {
        temp = this->head->next;
        prev = this->head;

        while(temp)
        {
            if(temp->data == item)
            {
                prev->next = temp->next;
                delete temp;
                break;
            }

            if(!temp->next || temp->next->data > item)
            {
                std::cout << "Error: Item not found" << std::endl;
                break;
            }

            prev = temp;
            temp = temp->next;

        }
    }
}







#endif