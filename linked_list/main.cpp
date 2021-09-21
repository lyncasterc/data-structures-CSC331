#include <iostream>
#include "linked_list.h"
#include "sorted_linked_list.h"
#include "doubly_linked_list.h"

void validate_input(const std::istream &stream, int &x)
{
    while(!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Input must be a number. Try again: \n";
        std::cin >> x;
    }
};

int getMenuChoice()
{
    int num;
    std::cout << "1: Add item" << std::endl
            << "2: Delete item" << std::endl
            << "3: Print the list" << std::endl
            << "4: Search the list for an item" << std::endl
            << "5: Get the numbers of items in the list " << std::endl
            << "6: Quit" << std::endl;
    std::cin >> num;
    validate_input(std::cin, num);

    return num;
}

void addItem(DoublyLinkedList<int> &list)
{
    int item;
    std::cout << "Enter integer to insert: ";
    std::cin >> item;
    validate_input(std::cin, item);
    list.insertItem(item);

    std::cout << "Number inserted\n\n";
}

void deleteItem(DoublyLinkedList<int> &list)
{
    int item;

    std::cout << "Enter integer to be deleted: ";
    std::cin >> item;
    validate_input(std::cin, item);

    if(list.searchItem(item))
    {
        list.deleteItem(item);
        std::cout << "Integer deleted\n\n";
    }
    else
        std::cout << "Integer not found\n\n";
}

void searchItem(DoublyLinkedList<int> &list)
{
    int item;

    std::cout << "Enter integer to search for: ";
    std::cin >> item;
    validate_input(std::cin, item);

    if(list.searchItem(item))
    {
        std::cout << "Integer found \n\n";
    }
    else
        std::cout << "Integer not found\n\n";
}


int main()
{
    DoublyLinkedList<int> list, list2;
    list.insertItem(1);
    list.insertItem(2);
    list.deleteItem(2);
    list.deleteItem(4);
    list.print();
    
    
    
    // int choice;
    // std::cout << "List below are the operations allowed on a doubly linked list" << std::endl;
    // std::cout << "Enter a Integer and press enter" << std::endl;
    
    // choice = getMenuChoice();

    // while(choice != 6)
    // {
    //     switch (choice)
    //     {
    //     case 1:
    //         addItem(list);
    //         break;
    //     case 2:
    //         deleteItem(list);
    //         break;
    //     case 3:
    //         list.print();
    //         break;
    //     case 4:
    //         searchItem(list);
    //         break;
    //     case 5:
    //         std::cout << "Number of items in the list: " << list.getLength() 
    //                 << std::endl << std::endl;
    //         break;
        
    //     default:
    //         std::cout << "Incorrect choice. Try again\n\n";
    //         break;
    //     }

    //     choice = getMenuChoice();
    // }

    // std::cout << "Ending program...\n\n";
}