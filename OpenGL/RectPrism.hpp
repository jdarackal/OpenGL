
#ifndef RECTPRISM_H
#define RECTPRISM_H

#include "Shape.hpp"

class rectPrism : public Shape {

public:
    rectPrism();
    rectPrism(double x_, double y_, double z_);
    rectPrism(double x_, double y_, double z_, double rotation_, double length_, double width_, double depth_);

    void draw();

protected:
    double length;
    double width;
    double depth;

};
#endif

