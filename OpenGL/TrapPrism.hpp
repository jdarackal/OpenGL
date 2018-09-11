
#ifndef TRAPPRISM_H
#define TRAPPRISM_H

#include "Shape.hpp"

class trapPrism : public Shape {

public:
    trapPrism();
    trapPrism(double x_, double y_, double z_);
    trapPrism(double x_, double y_, double z_, double rotation_, double lengthA_, double lengthB_, double height_, double depth_, double offset_);

    void draw();

protected:
    double lengthA;
    double lengthB;
    double height;
    double depth;
    double offset;

};
#endif
