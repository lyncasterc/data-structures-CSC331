#include <map>
#include <string>
#include <iostream>

// similar to a hash or dictionary
// syntax - map<T1, T2> obj;
    // T1 is key type, T2 is value type
// keys are unique
// stored in sorted order

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
    

}