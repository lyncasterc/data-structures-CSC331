#ifndef RectangleType_H
#define RectangleType_H

#include <iostream>

class RectangleType
{
    friend std::ostream& operator<<(std::ostream&, const RectangleType &);

    private:
        double length;
        double width;

    public:
        RectangleType();
        RectangleType(double l, double w);
        void setDimension(double l, double w);
        double getLength() const;
        double getWidth() const;
        double area() const;
        double perimeter() const;
        bool operator ==(const RectangleType &rec) const;
        bool operator !=(const RectangleType &rec) const;
        void print() const;

};

#endif