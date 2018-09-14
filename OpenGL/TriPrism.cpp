
#include <GL/glut.h>
#include "TriPrism.hpp"
#include "math.h"

triPrism::triPrism(float xyz[3]) : Shape(xyz[0], xyz[1], xyz[2]) {}

triPrism::triPrism(float xyz[3], float rgb[3], double rotation_, double alen_, double blen_, double angle_, double depth_) : Shape(xyz[0], xyz[1], xyz[2], rotation_) {
    alen = alen_;
    blen = blen_;
    angle = angle_ * 3.1415 / 180;
    depth = depth_;
    setColor(rgb[0], rgb[1], rgb[2]);
}

void triPrism::draw() {

    glPushMatrix();

    positionInGL();
    setColorInGL();

    glBegin(GL_TRIANGLES);

    glVertex3d(alen / 2, 0, -depth / 2);
    glVertex3d(-alen / 2, 0, -depth / 2);
    glVertex3d(blen * cos(angle) - alen / 2, blen * sin(angle), -depth / 2);

    glVertex3d(alen / 2, 0, depth / 2);
    glVertex3d(-alen / 2, 0, depth / 2);
    glVertex3d(blen * cos(angle) - alen / 2, blen * sin(angle), depth / 2);

    glEnd();

    glBegin(GL_QUAD_STRIP);

    glVertex3d(alen / 2, 0, -depth / 2);
    glVertex3d(alen / 2, 0, depth / 2);
    glVertex3d(-alen / 2, 0, -depth / 2);
    glVertex3d(-alen / 2, 0, depth / 2);

    glVertex3d(blen * cos(angle) - alen / 2, blen * sin(angle), -depth / 2);
    glVertex3d(blen * cos(angle) - alen / 2, blen * sin(angle), depth / 2);

    glVertex3d(alen / 2, 0, -depth / 2);
    glVertex3d(alen / 2, 0, depth / 2);

    glEnd();

    glPopMatrix();
}
