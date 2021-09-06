#include <iostream>

template<typename T>
class A
{
    public:
        T val;
};

template<typename T>
class B
{
    protected:
        A<T> *head;
        
};

template<typename T>
class C : public B<T>
{
    public:
        void printVal();
};

template<typename T>
void C<T>::printVal()
{
    this->head = new A<int>;
    this->head->val = 3;
    std::cout << this->head->val;
}


int main()
{
    C<int> c;
    c.printVal();
}