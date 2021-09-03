#include <iostream>
#include <forward_list>

// forward list is a singly linked list

int main()
{
    std::forward_list<int> list = {8, 3, 1}, list2 = {5, 11, 2};

    //  insert_after - inserts after given iterator
    list.insert_after(list.begin(), 2);

    std::cout << list.front() << std::endl; // returns front value

    list.sort(); // sorts list 
    list2.sort();

    list.merge(list2); // merges two SORTED list
    
    for (auto &&i : list)
    {
        std::cout << i << " ";
    }
    
}