#ifndef SortedLinkedList_H
#define SortedLinkedList_H
#include "linked_list.h"
#include <iostream>


template<typename T>
class SortedLinkedList : public LinkedList<T>
{
    private:
        int howMany(const T &item, Node<T> *node) const; 

    public:
        using LinkedList<T>::LinkedList;
        virtual void insertItem(const T &item);
        virtual void deleteItem(const T &item);
        virtual bool searchItem(const T &item) const;
        int smaller(const T &item) const;
        void printPosition(const T &item) const;
        void howMany(const T &item) const; 

};

template<typename T>
int SortedLinkedList<T>::howMany(const T &item, Node<T> *node) const
{
    static int count = 0;
    
    if(node)
    {
        if(node->data == item)
        {
            count++;
        }
        howMany(item, node->next);
    }
    

    return count; 

}

template<typename T>
void SortedLinkedList<T>::howMany(const T &item) const
{
    int occurences = howMany(item, this->head);

    if(occurences > 0)
    {
        std::cout << "Number of occurences: " << occurences << std::endl;
    }
    else
    {
        std::cout << "No occurences.\n";
    }
}




template<typename T>
void SortedLinkedList<T>::printPosition(const T &item) const
{
    int pos;
    int count = 0;
    bool found = false;
    Node<T> *node = this->head;

    if(!this->isEmpty())
    {
        
        while(node && node->data <= item)
        {
            if(node->data == item)
            {
                found = true;
                pos = count + 1;
                break;
            }

            node = node->next;
            count++;
        }

        
        if(found)
        {

            std::cout << "Position: " << pos << std::endl;
        }

        else
        {
            std::cout << "ERROR: Item does not exist" << std::endl;
        }

    }

    else
    {
        std::cout << "Error: List is empty." << std::endl;
    }
    
};

template<typename T>
int SortedLinkedList<T>::smaller(const T &item) const
{
    int count = 0;
    Node<T> *node;
    node = this->head;

    while(node && node->data < item) 
    {
        count++;
        node = node->next;
    }
    
    return count;
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

template<typename T>
bool SortedLinkedList<T>::searchItem(const T &item) const
{
    Node<T> *temp;
    temp = this->head;

    while(temp && temp->data <= item)
    {
        if(temp->data == item)
        {
            return true;
        }
        
        temp = temp->next;
    }

    return false;
}


#endif