#ifndef Stack_H
#define Stack_H

template <typename T>
class Stack
{
    private:
        int size;
        int top;
        T *arr;

    public:
        Stack();
        Stack(const Stack<T> &other);
        const Stack<T> &operator= (const Stack<T> &other);
        bool isEmpty() const;
        bool isFull() const;
        void push(const T &item);
        void pop();
        int getLength() const;
        T Top() const;
        void copy(const Stack<T> &other);
        void destroy();
        ~Stack();
};

template<typename T>
Stack<T>::Stack()
{
    size = 100;
    arr = new T[size];
    top = -1;
}

template<typename T>
Stack<T>::Stack(const Stack<T> &other)
{
    copy(other);
}

template<typename T>
const Stack<T>& Stack<T>::operator= (const Stack<T> &other)
{
    if(this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return top == -1;
}

template<typename T>
bool Stack<T>::isFull() const
{
    return top == size - 1;
}

template<typename T>
void Stack<T>::push(const T &item)
{
    if(!isFull())
    {
        arr[++top] = item;
    }
}

template<typename T>
void Stack<T>::pop()
{
    if(!isEmpty())
    {
        top--;
    }
}

template<typename T>
int Stack<T>::getLength() const
{
    return isEmpty() ? 0 : top + 1;
}

template<typename T>
T Stack<T>::Top() const
{
    return arr[top];
}

template<typename T>
void Stack<T>::copy(const Stack<T> &other)
{

    size = other.size;
    top = other.top;
    arr = new T [size];
    for (int i = 0; i < other.top + 1; i++)
    {
        arr[i] = other.arr[i];
    }
        
}


template<typename T>
void Stack<T>::destroy()
{
    delete [] arr;
}


template<typename T>
Stack<T>::~Stack()
{
    destroy();
}



#endif