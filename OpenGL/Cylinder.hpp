
#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.hpp"

class cylinder : public Shape {

public:
    cylinder();
    cylinder(double x_, double y_, double z_);
    cylinder(double x_, double y_, double z_, double rotation_, double radius_, double height_);

    void draw();

protected:
    double radius;
    double height;
};

#endif