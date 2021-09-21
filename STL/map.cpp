#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

// similar to a hash or dictionary
// syntax - map<T1, T2> obj;
    // T1 is key type, T2 is value type
// keys are unique
// stored in sorted order by key

// comparison function to sort vector of pairs by values in descending order
bool f(std::pair<char, int> &a,
        std::pair<char, int> &b)
{
    return a.second > b.second;
};

// creates a vector of pairs from a map and sorts them, returns vector
std::vector<std::pair<char, int>> map_value_sort(std::map<char, int> &m)
{
    std::vector<std::pair<char, int>> arr;

    for (auto &&i : m)
    {
        arr.push_back(i);
    }
    
    std::sort(arr.begin(), arr.end(), f);
    
    return arr;
    
}


int main()
{
    std::map<std::string, int> ages;

    ages["Stiven"] = 25;
    ages["Emilia"] = 23;
    ages.insert(std::make_pair("Kari", 21)); 

    // looping

    for (auto &&i : ages)
    {
        std::cout << i.first << " " << i.second << std::endl;
    }

    // accessing key
        // returns value as reference, changes actual value
        // key can not be changed

    std::cout << ages["Stiven"] << std::endl;

    // finding occurences of chars in map

    std::map<char, int> char_count;
    std::string name = "Emilia Telfer";

    for (auto &&i : name)
    {
        // if char is present in map, it increments.
        // if not, it creates it in map
        char_count[i]++;
    }

    std::cout << char_count['b'] << std::endl;

    // finding keys in map
    auto it = char_count.find('a');
    std::cout <<  "Key: " <<  it->first << 
                " Value: " << it->second << std::endl;

    //erasing keys - map.erase(key);

    std::vector<std::pair<char, int>> sorted_char_count = map_value_sort(char_count);

    std::cout << sorted_char_count[2].first << std::endl;
    

}