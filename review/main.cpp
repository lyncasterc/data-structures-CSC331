#include "array.h"
#include "t_array.h"
#include "../Timer.h"
#include <iostream>
#include <string>

int main()
{
    Timer t;
    Array arr;
    T_Array<std::string> arr2;
    arr.insert(2);
    arr.insert(3);
    arr.print();
    
    arr2.insert("hi");
    arr2.insert("bye");
    arr2.print();

    std::cout << arr.getLength() << std::endl;

    std::cout << t.elapsed() << std::endl;


}