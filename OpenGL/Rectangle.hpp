
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.hpp"

class rectangle : Shape {

public:
    rectangle();
    rectangle(double x_, double y_, double z_);
    rectangle(double x_, double y_, double z_, double rotation_, double length_, double width_);

    void SetLength(double length_);
    void SetWidth(double width_);

    void draw();

protected:
    double length;
    double width;

};
#endif