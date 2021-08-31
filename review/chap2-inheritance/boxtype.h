#ifndef BoxType_H
#define BoxType_H
#include "rectangletype.h"
#include <iostream>

class BoxType: public RectangleType
{
    private:
        double height;

    public:
        BoxType();
        BoxType(double l, double w, double h);
        void setDimension(double l, double w, double h);
        double getHeight() const;
        double volume() const;
        double area() const;
        void print() const;
        

};

#endif