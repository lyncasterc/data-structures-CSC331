#include <iostream>
#include "ArrayQueue.h"
#include "ListQueue.h"

int main()
{
    ArrayQueue<int> q1, q2;
    q1.enqueue(1);
    q1.enqueue(32); // 1, 32

    q2.enqueue(1);
    q2.enqueue(32); 
    
    q2 = q1;



    std::cout << q1.first() << std::endl;
    std::cout << q1.last() << std::endl;
    std::cout << q1.getLength();

    std::cout << "\n\n";

    std::cout << q2.first() << std::endl;
    std::cout << q2.last() << std::endl;
    std::cout << q2.getLength();
}