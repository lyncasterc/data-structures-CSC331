#include <iostream>
#include "linked_list.h"
#include "sorted_linked_list.h"
#include "doubly_linked_list.h"


int main()
{
    // LinkedList<int> list, list2;
    // SortedLinkedList<int> list;
    DoublyLinkedList<int> list, list2;
    list.insertItem(3);
    list.insertItem(2);
    list.insertItem(1);
    list.insertItem(5);

    list.pop();
    list.pop();
    list.pop();
    list.pop();
    list.pop();
    list.print(); 
    // std::cout << list.getLength();
}