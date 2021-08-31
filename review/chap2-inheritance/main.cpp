#include <iostream>
#include "rectangletype.h"
#include "boxtype.h"


int main()
{
    RectangleType rec{ 3, 3 };
    RectangleType rec2{ 3, 4 };
    BoxType box{ 2, 3, 4 };
    bool result = (rec != rec2);

    std::cout << result;
}