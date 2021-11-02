#include <iostream>
#include <vector>
#include <algorithm>

// Starting from the beginning, find the smallest value in array
// and swap it with the first element.
// Then, starting from the second element, find the smallest value
// and etc.
// O(N^2)
void selection_sort(std::vector<int> &arr)
{
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        std::swap(arr[i], arr[min_index]);
    }

};


int main()
{
    std::vector<int> arr = {5, 4, 3, 2, 1};
    selection_sort(arr);
    for (auto i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}