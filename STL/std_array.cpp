#include <array>
#include <iostream>

int main()
{
    // fixed size
    // passed to functions by value, not reference
    // accessing elments - at(), [], front(), back()
        // data() - access the underlying array

    std::array<int, 5> arr, arr2;
    arr2 = {1,2,3,4,5};

    arr.fill(9); // fills array with default value

    int size = arr.size();

    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    

}