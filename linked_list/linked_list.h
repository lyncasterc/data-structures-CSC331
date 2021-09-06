#ifndef LinkedList_H
#define LinkedList_H
#include "node.h"
#include <iostream>

template<typename T> 
class LinkedList
{
    protected:
        Node<T> *head;
    public:
        LinkedList();
        LinkedList(const LinkedList<T> &);
        const LinkedList<T>& operator=(const LinkedList<T> &);
        int getLength() const;
        bool isEmpty() const;
        virtual void insertItem(const T &item);
        virtual void deleteItem(const T &item);
        virtual bool searchItem(const T &item) const;
        void print() const;
        void copy(const LinkedList<T> &other);
        void destroy();
        void reverseList();
        ~LinkedList();
};

template<typename T>
LinkedList<T>::LinkedList() { head = NULL; }

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other)
{
    copy(other);
}

template<typename T>
const LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T> &other)
{
    if(this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
}


template<typename T>
int LinkedList<T>::getLength() const 
{
    int length = 0;
    Node<T> *temp;
    temp = head;

    while(temp)
    {
        temp = temp->next;
        length++;
    }

    return length;
}


template<typename T>
bool LinkedList<T>::isEmpty() const { return head == NULL; }

template<typename T>
void LinkedList<T>::insertItem(const T &item)
{
    if(!head)
    {
        head = new Node<T>;
        head->data = item;
        head->next = NULL;
    }
    else
    {
        Node<T> *temp, *new_node;
        new_node = new Node<T>;
        new_node->data = item;
        new_node->next = NULL;
        temp = head;

        while(temp->next) { temp = temp->next; }

        temp->next = new_node;
    }
}

template<typename T>
void LinkedList<T>::deleteItem(const T &item)
{
    Node<T> *temp, *prev;
    
    if(!head)
    {
        std::cout << "Error: List is empty" << std::endl;
    }

    else if(head->data == item)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    else
    {
        temp = head->next;
        prev = head;

        while(temp)
        {
            if(temp->data == item)
            {
                prev->next = temp->next;
                delete temp;
                break;
            }

            if(!temp->next)
            {
                std::cout << "Error: Item not found" << std::endl;
                break;
            }

            prev = temp;
            temp = temp->next;
        }
    }

}


template<typename T>
bool LinkedList<T>::searchItem(const T &item) const
{
    Node<T> *temp;
    temp = head;

    while(temp)
    {
        if(temp->data == item)
        {
            return true; 
        }

        temp = temp->next;
    }

    return false;
}



template<typename T>
void LinkedList<T>::print() const
{
    Node<T> *temp;
    temp = head;

    while(temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}

template<typename T>
void LinkedList<T>::copy(const LinkedList<T> &other)
{
        Node<T> *current;
        Node<T> *temp;

        if(!other.head)
        {
            head = NULL;
        }
        else
        {
            current = other.head;
            head = new Node<T>;
            head->data = current->data;
            head->next = NULL;
            current = current->next;
            temp = head;

            while(current)
            {
                temp->next = new Node<T>;
                temp->next->data = current->data;
                current = current->next;
                temp = temp->next;
            }

            temp->next = NULL;
        }
}

template<typename T>
void LinkedList<T>::destroy()
{
    Node<T> *temp;

    while(head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
void LinkedList<T>::reverseList()
{
    Node<T> *curr = head, *prev = NULL, *next_node = NULL;

    while(next_node)
    {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
}

template<typename T>
LinkedList<T>::~LinkedList() { destroy(); }

#endif