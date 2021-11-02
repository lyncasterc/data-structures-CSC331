#include <iostream>
#include <vector>
#include <algorithm>


// Insertion sort
// Time complexity: O(n^2)
// consider first element as it's own sorted subarray
// next element is compared with all elements in sorted subarray,
// if subarray elements are bigger, shift them to right
// ex: [3,2,1]
//     3 _ _ -> to insert 2, 3 needs to shift over to the right
//     _ 3 _ -> 
//     2 3 _ -> now to insert one, 3 needs to shift again
//     2 _ 3 -> 2 also needs to shift because it's bigger than 1
//     _ 2 3 -> now 1 can be inserted
//     1 2 3

// instead of literally shifting, we are copying the elements to the right and storing the element to be inserted in a temp variable
// 3 3 1
// 2 3 1
// 2 3 3
// 2 2 3
// 1 2 3


void insertion_sort(std::vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            std::swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

int main()
{
    std::vector<int> arr = {8, 5, 2, 9, 5, 6, 3};
    insertion_sort(arr);
    for (int i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}