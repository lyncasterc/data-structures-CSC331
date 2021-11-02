#include <iostream>
#include "linked_list.h"
#include "sorted_linked_list.h"
#include "doubly_linked_list.h"



int main()
{

    // smaller() 
    // howMany()

    // SortedLinkedList<int> sorted_list;
    // sorted_list.insertItem(1);
    // sorted_list.insertItem(2);
    // sorted_list.insertItem(2);
    // sorted_list.insertItem(3);
    // sorted_list.insertItem(4);
    // sorted_list.insertItem(0);
    // sorted_list.insertItem(0);
    // sorted_list.insertItem(0);

    // std::cout << sorted_list.smaller(1) << std::endl;

    // printPosition()
    // sorted_list.printPosition(1);
    // sorted_list.howMany(0);







    // printBoth()

    // DoublyLinkedList<int> double_list;
    // double_list.insertItem(1);
    // double_list.insertItem(2);
    // double_list.insertItem(3);
    // double_list.insertItem(4);
    // double_list.insertItem(5);
    // double_list.insertItem(6);
    // double_list.insertItem(8);
    // double_list.insertItem(0);

    // double_list.printBoth();


    // replace_item()
    // getLargest()
    // greater()

    LinkedList<int> list;
    list.insertItem(1);
    list.insertItem(2);
    list.insertItem(2);
    list.insertItem(2);
    list.insertItem(5);
    list.insertItem(6);
    list.insertItem(8);
    list.insertItem(0);
    list.insertItem(0);
    list.insertItem(100);

    // list.replaceItem(0, 69);

    // std::cout << list.getLargest();

    // list.greater(5);

    // list.occurences(2);
    list.occurences(0);


}


