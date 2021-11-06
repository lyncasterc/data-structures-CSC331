#include <iostream>
#include <vector>

std::vector<int>merge(std::vector<int> &left, std::vector<int> &right)
{
    std::vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            result.push_back(left[i++]); 
        }
        
        else
        {
            result.push_back(right[j++]);
        }
    }

    while (i < left.size())
    {
        result.push_back(left[i++]);
    }
    
    while (j < right.size())
    {
        result.push_back(right[j++]);
    }

    return result;
}

// code merge sort
std::vector<int> merge_sort(std::vector<int> &array)
{
    if (array.size() < 2)
    {
        return array;
    }

    int mid = array.size() / 2;
    std::vector<int> left(array.begin(), array.begin() + mid);
    std::vector<int> right(array.begin() + mid, array.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}


int main()
{
    // test merge sort with unsorted array
    std::vector<int> array = {5, 4, 3, 2, 1};
    std::vector<int> sorted_array = merge_sort(array);

    //print sorted array
    for (auto &&i : sorted_array)
    {
        std::cout << i << " ";
    }
    
    
}
