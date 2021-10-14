#ifndef ListQueue_H
#define ListQueue_H
#include <iostream>



    template<typename T>
    struct Node 
    {
        T data;
        Node<T> *next;
    };


    template<typename T>
    class ListQueue
    {
        private:
            Node<T> *front;
            Node<T> *rear;
        public:
            ListQueue();
            void copy(const ListQueue<T> &other);
            ListQueue(const ListQueue<T> &other);
            const ListQueue<T>& operator=(const ListQueue<T> &other);
            bool isEmpty() const;
            void enqueue(const T &item);
            void dequeue();
            T first() const;
            T last() const;
            int getLength() const;
            void destroy();
            ~ListQueue();
    };


    template<typename T>
    ListQueue<T>::ListQueue()
    {
        front = rear = NULL;
    }

    template<typename T>
    void ListQueue<T>::copy(const ListQueue<T> &other)
    {

        Node<T> *current;
        Node<T> *temp;

        if(!other.front)
        {
            front = rear = NULL;
        }

        else
        {
            current = other.front;
            front = new Node<T>;
            front->data = current->data;
            front->next = NULL;
            current = current->next;
            temp = front;

            while(current)
            {
                temp->next = new Node<T>;
                temp->next->data = current->data;
                current = current->next;
                temp = temp->next;
            }

            rear = temp;
            temp->next = NULL;
        }

    }

    template<typename T>
    ListQueue<T>::ListQueue(const ListQueue<T> &other)
    {
        copy(other);
    }


    template<typename T>
    const ListQueue<T>& ListQueue<T>::operator=(const ListQueue<T> &other)
    {
        if (this != &other)
        {
            destroy();
            copy(other);
        }
        
        return *this;
    }


    template<typename T>
    bool ListQueue<T>::isEmpty() const
    {
        return front == NULL;
    }

    template<typename T>
    void ListQueue<T>::enqueue(const T &item) 
    {  
        Node<T> *node;
        node = new Node<T>;
        node->data = item;
        node->next = NULL;

        if(rear)
        {
            rear->next = node;
        }
        else
        {
            front = node;
        }
        
        rear = node;

    }

    template<typename T>
    void ListQueue<T>::dequeue() 
    {  
        if(!isEmpty())
        {
            Node<T> *node;
            node = front;
            front = front->next;
            
            if(!front)
            {
                rear = NULL;
            }

            delete node;
        }

    }

    template<typename T>
    T ListQueue<T>::first() const
    {
        T item;

        try
        {
            if(!isEmpty())
            {
                item = front->data;
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
    T ListQueue<T>::last() const
    {
        T item;

        try
        {
            if(!isEmpty())
            {
                item = rear->data;
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
    void ListQueue<T>::destroy()
    {
        Node<T> *temp;

        while(front)
        {
            temp = front;
            front = front->next;
            delete temp;
        }

        rear = NULL;
    }

    template<typename T>
    ListQueue<T>::~ListQueue()
    {
        destroy();
    }



#endif
