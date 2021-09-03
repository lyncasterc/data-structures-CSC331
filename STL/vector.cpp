#include <vector>
#include <iostream>

// sequence container

// essentially a combination of dynamic array and linked list
    // dynamic sizing
    // O(1) acces to elements
    // whenever vector runs out of space to insert new element,
        // it creates an array of double the original size
        // if you know the size you need, use reserve(n) to save time on vector size doubling
    

// accesing data:
    // at(), [], front(), back(), data()


int main()
{
    std::vector<int> arr, arr2;
    arr.push_back(1); // adds new item to back of vector
    arr.pop_back(); // removes last item, does not return 
    arr.size(); // returns length of vector
    arr.empty(); // returns true if vector is empty
    
    arr2.push_back(8); // {8}

    // insert - takes iterator and value
    // inserts value at iterator
    auto it = arr2.begin();
    arr2.insert(it, 2); // {2, 8}
    std::cout << arr2.at(0); // at - returns element at index
    
    
}