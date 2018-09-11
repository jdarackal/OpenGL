
#include <GL/glut.h>
#include "RectPrism.hpp"

rectPrism::rectPrism():Shape() {}

rectPrism::rectPrism(double x_, double y_, double z_) : Shape(x_, y_, z_) {}

rectPrism::rectPrism(double x_, double y_, double z_, double rotation_, double length_, double width_, double depth_) : Shape(x_, y_, z_, rotation_) {
    length = length_;
    width = width_;
    depth = depth_;
}

void rectPrism::draw() {

    glPushMatrix();

    positionInGL();

    glBegin(GL_QUAD_STRIP);

    glVertex3d(-length / 2, 0, -depth / 2);
    glVertex3d(length / 2, 0, -depth / 2);
    glVertex3d(-length / 2, 0, depth / 2);
    glVertex3d(length / 2, 0, depth / 2);

    glVertex3d(-length / 2, width, depth / 2);
    glVertex3d(length / 2, width, depth / 2);

    glVertex3d(-length / 2, width, -depth / 2);
    glVertex3d(length / 2, width, -depth / 2);

    glVertex3d(-length / 2, 0, -depth / 2);
    glVertex3d(length / 2, 0, -depth / 2);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3d(length / 2, 0, -depth / 2);
    glVertex3d(length / 2, 0, depth / 2);
    glVertex3d(length / 2, width, depth / 2);
    glVertex3d(length / 2, width, -depth / 2);

    glVertex3d(-length / 2, 0, -depth / 2);
    glVertex3d(-length / 2, 0, depth / 2);
    glVertex3d(-length / 2, width, depth / 2);
    glVertex3d(-length / 2, width, -depth / 2);

    glEnd();

    glPopMatrix();
}

