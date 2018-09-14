
#ifndef TRIPRISM_H
#define TRIPRISM_H

#include "Shape.hpp"

class triPrism : public Shape {

public:
    triPrism(float xyz[3]);
    triPrism(float xyz[3], float rgb[3], double rotation_, double alen_, double blen_, double angle_, double depth_);

    void draw();

protected:
    double alen;
    double blen;
    double angle;
    double depth;

};

#endif
