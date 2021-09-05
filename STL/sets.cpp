#include <iostream>
#include <set>

// sets store unique elements
// values can not be modified once in a set
// inserts items in sorted order
// insertion and deletion -  O(NLogN)


int main()
{
    std::set<int> s;
    
    // inserting
    // O(NLogN)
    s.insert(2);
    s.insert(-1);
    s.insert(100);
    s.insert(10);
    s.insert(4);

    for (auto &&i : s)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // finding element in set
    // returns iterator to element if found or end if not

    auto it = s.find(-1);
    std::cout << *it << std::endl;

    // lower_bound and upper_bound is available in the class

    auto it2 = s.lower_bound(2);
    std::cout << *it2 << std::endl;

    // erasing elements 
    s.erase(2);
    for (auto &&i : s)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

}