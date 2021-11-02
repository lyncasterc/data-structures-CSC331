#include <iostream>

template<typename T>
bool binary_search(T arr[], int n, T key)
{
    int left = 0, right = n - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) 
        {
            return true;
        } 
        else if (arr[mid] < key) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }

    return false;
}

int main()
{
    int x[] = {1,2,3,4,5,6};
    int length = 6;

    std::cout << binary_search(x, length, 5);
}