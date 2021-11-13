#include <iostream>
#include <vector>

void quick_sort(std::vector<int> &v, int start, int end)
{
    if((end - start) > 1)
    {
        int pivot = v[start], i = start + 1, j = end - 1, temp;
        while(j >= i)
        {
            if(v[i] > pivot && v[j] <= pivot)
            { 
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                i++;
                j--;

            }
            if(v[i] <= pivot)
            {
                i++;
            }

            if(v[j] > pivot)
            {
                j--;
            }
        
        }

        temp = v[j];
        v[j] = pivot;
        v[start] = temp;

        quick_sort(v, start, j);
        quick_sort(v, j + 1, end);
    }

};


int main()
{

}