#ifndef WHEEL_H
#define WHEEL_H

#include "Shape.hpp"

class Wheel : public Shape {

public:
    Wheel();
    Wheel(double x_, double y_, double z_);
    Wheel(double x_, double y_, double z_, double rotation_);
    Wheel(double x_, double y_, double z_, double rotation_, double wheel_rotation);
    void draw();
    double get_wheel_rotation();
    void set_wheel_rotation(double new_wheel_rotation);

    void addShape(Shape * shape);
    ~Wheel();

protected:
    double wheel_rotation;
    
};
#endif