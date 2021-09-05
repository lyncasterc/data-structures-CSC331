#include <vector>
#include <iostream>
#include <algorithm>

// sequence container

// essentially a combination of dynamic array and linked list
    // dynamic sizing
    // O(1) acces to elements
    // whenever vector runs out of space to insert new element,
        // it creates an array of double the original size
        // if you know the size you need, use reserve(n) to save time on vector size doubling
    

// accesing data:
    // at(), [], front(), back(), data()


bool f(int x, int y)
{
    return x > y;
}

int main()
{
    std::vector<int> arr, arr2;
    arr.push_back(1); // adds new item to back of vector
    arr.pop_back(); // removes last item, does not return 
    arr.size(); // returns length of vector
    arr.empty(); // returns true if vector is empty

    arr2.push_back(8); 
    arr2 = {12, 3, 5, 10};

    // insert - takes iterator and value
    // inserts value at iterator
    auto it = arr2.begin();
    arr2.insert(it, 2);
    std::cout << arr2.at(0); // at - returns element at index
    
    // sorts vector - requires algorithm library
    // O(NlogN)
    std::sort(arr2.begin(), arr2.end()); 
    for (auto &&i : arr2)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //std::find returns an iterator equal to arr2.end() if item is not present
    // O(N)
    bool present = (std::find(arr2.begin(), arr2.end(), 3) != arr2.end()); 
    
    //std::binary_search - returns true if element is present
    //vector needs to be sorted. O(NLogN)
    bool present2 = (std::binary_search(arr2.begin(), arr2.end(), 10));

    std::cout << present2 << std::endl;

    // std::lower_bound returns first iterator >= to val 
    auto it2 = std::lower_bound(arr2.begin(), arr2.end(), 7);

    //std::upper_bound returns the first iterator strictly > to val
    // O(NLogN) for sorted vectors
    auto it3 = std::upper_bound(arr2.begin(), arr2.end(), 10);

    std::cout << *it3 << std::endl; 

    // std::distance returns distance between two iterators.
    // can be used to find index of item in vector
    int index =  std::distance(arr2.begin(), it3);

    std::cout << index << std::endl;

    // sorting in reverse order - passing in comparative function
    std::sort(arr2.begin(), arr2.end(), f);
    

    
    
}