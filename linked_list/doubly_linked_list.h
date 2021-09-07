#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H
#include <iostream>

template<typename T>
struct Node2
{
    T data;
    Node2<T> *prev;
    Node2<T> *next;
};

template<typename T>
class DoublyLinkedList
{
    private:
        Node2<T> *head;
    public:
        DoublyLinkedList();
        DoublyLinkedList(const DoublyLinkedList<T> &);
        const DoublyLinkedList<T>& operator=(const DoublyLinkedList<T> &);
        int getLength() const;
        bool isEmpty() const;
        void insertItem(const T &item);
        void deleteItem(const T &item);
        void pop();
        bool searchItem(const T &item) const;
        void print() const;
        void copy(const DoublyLinkedList<T> &other);
        void destroy();
        ~DoublyLinkedList();

};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() { head = NULL; }

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &other)
{
    copy(other);
}

template<typename T>
const DoublyLinkedList<T>& DoublyLinkedList<T>::operator =(const DoublyLinkedList<T> &other)
{
    if(this != &other)
    {
        destroy();
        copy(other);
    }
    return *this;
}

template<typename T>
int DoublyLinkedList<T>::getLength() const 
{
    int length = 0;
    Node2<T> *temp;
    temp = head;

    while(temp)
    {
        temp = temp->next;
        length++;
    }

    return length;
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() const { return head == NULL; }


template<typename T>
void DoublyLinkedList<T>::insertItem(const T &item)
{
    Node2<T> *new_node;
    new_node = new Node2<T>;
    new_node->data = item;

    if(!head)
    {
        new_node->prev = NULL;
        new_node->next = NULL;
        head = new_node;
    }
    else
    {   
        Node2<T> *temp = head;

        while(temp->next) { temp = temp->next; }

        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = NULL;
    }
}


template<typename T>
void DoublyLinkedList<T>::deleteItem(const T &item)
{
    Node2<T> *temp;

    if(!head)
    {
        std::cout << "Error: List is empty" << std::endl;
    }

    else if(head->data == item)
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }

    else
    {
        temp = head->next;

        while(temp)
        {
            if(temp->data == item)
            {
                temp->prev->next = temp->next;

                if(temp->next)
                {
                    temp->next->prev = temp->prev;
                }

                delete temp;
                break;
            }

            if(!temp->next)
            {
                std::cout << "Error: Item not found" << std::endl;
                break;
            }

            temp = temp->next;
        }
    }
}


template<typename T>
bool DoublyLinkedList<T>::searchItem(const T &item) const
{
    Node2<T> *temp;
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
void DoublyLinkedList<T>::pop()
{
    Node2<T> *temp;

    if(!head)
    {
        std::cout << "Error: List is empty" << std::endl;
    }
    
    else
    {
        temp = head;

        while(temp->next) { temp = temp->next; }

        if (temp == head)
        {
            head = NULL;
        }

        else
        {
            temp->prev->next = NULL;
        } 

        delete temp;
    }

}


template<typename T>
void DoublyLinkedList<T>::print() const
{
    Node2<T> *temp;
    temp = head;

    while(temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::copy(const DoublyLinkedList<T> &other)
{
    Node2<T> *current, *temp;
    

    if(!other.head)
    {
        head = NULL;
    }

    else
    {
        current = other.head;
        head = new Node2<T>;
        head->data = current->data;
        head->next = NULL;
        head->prev = NULL;
        current = current->next;
        temp = head;

        while(current)
        {
            temp->next = new Node2<T>;
            temp->next->data = current->data;
            temp->next->prev = temp;
            current = current->next;
            temp = temp->next;
        }

        temp->next = NULL;
    }
}

template<typename T>
void DoublyLinkedList<T>::destroy()
{
    Node2<T> *temp;

    while(head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() { destroy(); }



#endif