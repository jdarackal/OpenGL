
#ifndef RECTPRISM_H
#define RECTPRISM_H

#include "Shape.hpp"

class rectPrism : public Shape {

public:
    rectPrism(float xyz[3]);
    rectPrism(float xyz[3], float rgb[3], double rotation_, double xlen_, double ylen_, double zlen_);

    void draw();

protected:
    double xlen;
    double ylen;
    double zlen;

};
#endif

