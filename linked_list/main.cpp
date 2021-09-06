#include <iostream>
#include "linked_list.h"
#include "sorted_linked_list.h"


int main()
{
    // LinkedList<int> list, list2;
    // list.insertItem(2);
    // list.reverseList();
    // list.print();
    SortedLinkedList<int> list;
    list.insertItem(1);
    list.insertItem(3);
    list.insertItem(2);
    list.insertItem(5);
    list.insertItem(7);
    list.insertItem(6);
    list.insertItem(4);
    list.insertItem(-4);
    list.insertItem(-2);
    list.insertItem(0);
    list.print();
    std::cout << list.getLength();

}