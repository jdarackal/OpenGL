
#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.hpp"

class cylinder : public Shape {

public:
    cylinder(float xyz[3]);
    cylinder(float xyz[3], float rgb[3], double rotation_, double radius_, double depth_, double speed_, double steering_, double roll_, bool isRolling, bool isSteering);

    void draw();

    double getRadius() {
        return radius;
    }

protected:
    double radius;
    double depth;
    double speed;
    double steering;
    double roll;
    bool isRolling;
    bool isSteering;
};

#endif