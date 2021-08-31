#include <iostream>
#include "boxtype.h"

BoxType::BoxType() : RectangleType()
{
    height = 0;
}

BoxType::BoxType(double l, double w, double h)
{
    setDimension(l, w, h);
}

void BoxType::setDimension(double l, double w, double h)
{
    RectangleType::setDimension(l, w);
    height = (h >= 0) ? h : 0;
}

double BoxType::getHeight() const { return height; }

double BoxType::area() const 
{
    return 2 * (getLength() * getWidth()
                + getLength() * height
                + getWidth() * height);
}

double BoxType::volume() const { return RectangleType::area() * height; }

void BoxType::print() const
{
    RectangleType::print();
    std::cout << "Height: " << height << std::endl;
}

std::ostream& operator<<(std::ostream &os_object, const RectangleType &rec )
{
    os_object << "Length: " <<  rec.length 
              << "Width: " << rec.width;

    return os_object;
}