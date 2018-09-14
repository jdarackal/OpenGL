
#include <GL/glut.h>
#include "TrapPrism.hpp"

trapPrism::trapPrism(float xyz[3]) : Shape(xyz[0], xyz[1], xyz[2]) {}

trapPrism::trapPrism(float xyz[3], float rgb[3], double rotation_, double alen_, double blen_, double height_, double depth_, double aoff_) : Shape(xyz[0], xyz[1], xyz[2], rotation_) {
    alen = alen_;
    blen = blen_;
    height = height_;
    depth = depth_;
    aoff = aoff_;
    setColor(rgb[0], rgb[1], rgb[2]);
}

void trapPrism::draw() {

    glPushMatrix();

    positionInGL();
    setColorInGL();

    glBegin(GL_QUADS);

    glVertex3d(alen / 2, 0, -depth / 2);
    glVertex3d(-alen / 2, 0, -depth / 2);
    glVertex3d((-alen / 2) + aoff, height, -depth / 2);
    glVertex3d((-alen / 2) + aoff + blen, height, -depth / 2);

    glVertex3d(alen / 2, 0, depth / 2);
    glVertex3d(-alen / 2, 0, depth / 2);
    glVertex3d((-alen / 2) + aoff, height, depth / 2);
    glVertex3d((-alen / 2) + aoff + blen, height, depth / 2);


    glEnd();

    glBegin(GL_QUAD_STRIP);

    glVertex3d(alen / 2, 0, -depth / 2);
    glVertex3d(alen / 2, 0, depth / 2);
    glVertex3d(-alen / 2, 0, -depth / 2);
    glVertex3d(-alen / 2, 0, depth / 2);

    glVertex3d((-alen / 2) + aoff, height, -depth / 2);
    glVertex3d((-alen / 2) + aoff, height, depth / 2);

    glVertex3d((-alen / 2) + aoff + blen, height, -depth / 2);
    glVertex3d((-alen / 2) + aoff + blen, height, depth / 2);

    glVertex3d(alen / 2, 0, -depth / 2);
    glVertex3d(alen / 2, 0, depth / 2);

    glEnd();

    glPopMatrix();
}