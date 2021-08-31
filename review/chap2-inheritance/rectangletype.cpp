#include <iostream>
#include "rectangletype.h"



RectangleType::RectangleType()
{
    length = 0;
    width = 0;
}

RectangleType::RectangleType(double l, double w)
{
    setDimension(l, w);
}

void RectangleType::setDimension(double l, double w)
{
    length = (l >= 0) ? l : 0;
    width = (w >= 0) ? w : 0;
}

double RectangleType::getLength() const { return length; }

double RectangleType::getWidth() const { return width; }

double RectangleType::area() const { return length * width; }

double RectangleType::perimeter() const { return 2 * (length + width); }

bool RectangleType::operator ==(const RectangleType &rec) const
{
    return length == rec.length && width == rec.width;
}

bool RectangleType::operator !=(const RectangleType &rec) const
{
    return length != rec.length || width != rec.width;
}

void RectangleType::print() const 
{
    std::cout << "Length: " << length << 
    std::endl << "Width: " << width << std::endl;
}



