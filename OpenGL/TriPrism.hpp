
#ifndef TRIPRISM_H
#define TRIPRISM_H

#include "Shape.hpp"

class triPrism : public Shape {

public:
    triPrism();
    triPrism(double x_, double y_, double z_);
    triPrism(double x_, double y_, double z_, double rotation_, double lengthA_, double lengthB_, double theta_, double depth_);

    void draw();

protected:
    double lengthA;
    double lengthB;
    double theta;
    double depth;

};

#endif
