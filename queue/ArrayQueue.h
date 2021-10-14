#ifndef ArrayQueue_H
#define ArrayQueue_H
#include <iostream>

    template<typename T>
    class ArrayQueue
    {
        private:
            T *arr;
            int size;
            int front;
            int rear;
            int length;
        public:
            ArrayQueue(int size = 100);
            ArrayQueue(const ArrayQueue<T> &other);
            const ArrayQueue<T>& operator=(const ArrayQueue<T> &other);
            bool isFull() const;
            bool isEmpty() const;
            void enqueue(const T &item);
            void dequeue();
            T first() const;
            T last() const;
            int getLength() const;
            ~ArrayQueue();
    };


    template<typename T>
    ArrayQueue<T>::ArrayQueue(int size)
    {
        this->size = size;
        arr = new T[size];
        front = length = 0;
        rear = size - 1;
    }
    
    template<typename T>
    ArrayQueue<T>::ArrayQueue(const ArrayQueue<T> &other)
    {
        size = other.size;
        length = other.length;
        rear = other.rear;
        front = other.front;
        arr = new T[size];

        if(length > 0)
        {
            int i = front;
            while(i != rear)
            {
                arr[i] = other.arr[i];
                i = (i + 1) % size;
            }

            arr[rear] = other.arr[rear];
        }
    };

    template<typename T>
    const ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T> &other)
    {
        if(this != &other)
        {
            delete [] arr;
            size = other.size;
            length = other.length;
            rear = other.rear;
            front = other.front;
            arr = new T[size];
        }

        int i = front;
        for (int j = 0; j < length; j++)
        {
            arr[i] = other.arr[i];
            i = (i+1)% size;
        }

        return *this;    
    } 

    template<typename T>
    bool ArrayQueue<T>::isFull() const
    {
        return length == size;
    }

    template<typename T>
    bool ArrayQueue<T>::isEmpty() const
    {
        return length == 0;
    }

    template<typename T>
    void ArrayQueue<T>::enqueue(const T &item)
    {
        if(!isFull())
        {
            rear = (rear + 1) % size;
            arr[rear] = item;
            length++;
        }
    }

    template<typename T>
    void ArrayQueue<T>::dequeue()
    {
        if(!isEmpty())
        {
            front = (front + 1) % size;
            length--;
        }
    }

    template<typename T>
    T ArrayQueue<T>::first() const
    {
        T item;

        try
        {
            if(!isEmpty())
            {
                item = arr[front];
            }
            else
            {
                throw "Error: Queue is empty.";
            }
        }

        catch(const char *error_msg)
        {
            std::cout << error_msg << std::endl;
        }
        
        return item;
    }

    template<typename T>
    T ArrayQueue<T>::last() const
    {
        T item;

        try
        {
            if(!isEmpty())
            {
                item = arr[rear];
            }
            else
            {
                throw "Error: Queue is empty.";
            }
        }

        catch(const char *error_msg)
        {
            std::cout << error_msg << std::endl;
        }
        
        return item;
    }


    template<typename T>
    int ArrayQueue<T>::getLength() const
    {
        return length;
    }

    template<typename T>
    ArrayQueue<T>::~ArrayQueue()
    {
        delete [] arr;
    }


#endif


