#ifndef ListStack_H
#define ListStack_H
#include <string>

template <typename T>

struct Node
{
    T data;
    Node<T> *next;
};


template <typename T>
class ListStack
{
    private:
       Node<T> *top;

    public:
        ListStack();
        ListStack(const ListStack<T> &other);
        const ListStack<T> &operator= (const ListStack<T> &other);
        bool isEmpty() const;
        void push(const T &item);
        T Top() const;
        T pop();
        int getLength() const;
        void copy(const ListStack<T> &other);
        void destroy();
        ~ListStack();
};

template<typename T>
ListStack<T>::ListStack()
{
    top = NULL;
}


template<typename T>
const ListStack<T>& ListStack<T>::operator= (const ListStack<T> &other)
{
    if(this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

template<typename T>
bool ListStack<T>::isEmpty() const
{
    return !top;
}

template<typename T>
void ListStack<T>::push(const T &item)
{
    Node<T> *new_top;
    new_top = new Node<T>;
    new_top->data = item;
    new_top->next = top;
    top = new_top;
}


template<typename T>
T ListStack<T>::Top() const
{
    T item;
    
    try 
    {
        if(!isEmpty())
        {
            item = top->data;
        }

        else
        {
            throw "ERROR: Stack is empty.";
        }
    }

    catch (const char *error_msg)
    {
        std::cout << error_msg << std::endl;
    }

    return item;
}

template<typename T>
T ListStack<T>::pop()
{
    T item;

    try 
    {
        if(!isEmpty())
        {
            Node<T> *node;
            node = top;
            item = node->data;
            top = top->next;
            delete node;
        }
        else
        {
            throw "ERROR: Stack is empty.";
        }
    }

    catch(const char *error_msg)
    {
        std::cout << error_msg << std::endl;
    }
    
    return item;
    
}


template<typename T>
int ListStack<T>::getLength() const
{
    int length;
    if(isEmpty())
    {
        length = 0;
    }
    else
    {
        Node<T> *node;
        length = 1;
        node = top;
        node = node->next;

        while(node)
        {
            node = node->next;
            length++;
        }
    }

    return length;
}


template<typename T>
void ListStack<T>::copy(const ListStack<T> &other)
{

    Node<T> *current;
    Node<T> *temp;

    if(!other.top)
    {
        top = NULL;
    }
    else
    {
        current = other.top;
        top = new Node<T>;
        top->data = current->data;
        top->next = NULL;
        current = current->next;
        temp = top;

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
void ListStack<T>::destroy()
{
    Node<T> *temp;

    while(top)
    {
        temp = top;
        top = top->next;
        delete temp;
    }
}


template<typename T>
ListStack<T>::~ListStack()
{
    destroy();
}



#endif