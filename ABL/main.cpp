#include "arraylisttype.h"
#include <iostream>

int main()
{
    ArrayListType<int> list;
    list.insertEnd(10);
    list.insertEnd(2);
    list.insertEnd(4);
    list.insertEnd(6);
    list.insertEnd(8);

    list.remove(1);
    list.print();
    
}