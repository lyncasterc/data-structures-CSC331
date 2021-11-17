#include <iostream>
#include "BSTree.h"
#include <vector>

int main()
{
    BSTree<int> tree;
    std::vector<int> nums = {8,5,7,3,2,9};


    for (auto &&i : nums)
    {
        tree.insertItem(i);
    }

    tree.postOrder();
    std::cout << std::endl;

    tree.preOrder();
    std::cout << std::endl;
    
    tree.inOrder();
    std::cout << std::endl;

    tree.deleteItem(8);
    tree.inOrder();
    std::cout << std::endl;
    
}