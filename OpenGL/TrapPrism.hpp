
#ifndef TRAPPRISM_H
#define TRAPPRISM_H

#include "Shape.hpp"

class trapPrism : public Shape {

public:
    trapPrism(float xyz[3]);
    trapPrism(float xyz[3], float rgb[3], double rotation_, double alen_, double blen_, double height_, double depth_, double aoff_);

    void draw();

protected:
    double alen;
    double blen;
    double height;
    double depth;
    double aoff;

};
#endif
