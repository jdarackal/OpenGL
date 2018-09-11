
#include <GL/glut.h>
#include "TrapPrism.hpp"

trapPrism::trapPrism() : Shape() {}

trapPrism::trapPrism(double x_, double y_, double z_) : Shape(x_, y_, z_) {}

trapPrism::trapPrism(double x_, double y_, double z_, double rotation_, double lengthA_, double lengthB_, double height_, double depth_, double offset_) : Shape(x_, y_, z_, rotation_) {
    lengthA = lengthA_;
    lengthB = lengthB_;
    height = height_;
    depth = depth_;
    offset = offset_;
}

void trapPrism::draw() {

    glPushMatrix();

    positionInGL();

    glBegin(GL_QUADS);

    glVertex3d(lengthA / 2, 0, -depth / 2);
    glVertex3d(-lengthA / 2, 0, -depth / 2);
    glVertex3d((-lengthA / 2) + offset, height, -depth / 2);
    glVertex3d((-lengthA / 2) + offset + lengthB, height, -depth / 2);

    glVertex3d(lengthA / 2, 0, depth / 2);
    glVertex3d(-lengthA / 2, 0, depth / 2);
    glVertex3d((-lengthA / 2) + offset, height, depth / 2);
    glVertex3d((-lengthA / 2) + offset + lengthB, height, depth / 2);


    glEnd();

    glBegin(GL_QUAD_STRIP);

    glVertex3d(lengthA / 2, 0, -depth / 2);
    glVertex3d(lengthA / 2, 0, depth / 2);
    glVertex3d(-lengthA / 2, 0, -depth / 2);
    glVertex3d(-lengthA / 2, 0, depth / 2);

    glVertex3d((-lengthA / 2) + offset, height, -depth / 2);
    glVertex3d((-lengthA / 2) + offset, height, depth / 2);

    glVertex3d((-lengthA / 2) + offset + lengthB, height, -depth / 2);
    glVertex3d((-lengthA / 2) + offset + lengthB, height, depth / 2);

    glVertex3d(lengthA / 2, 0, -depth / 2);
    glVertex3d(lengthA / 2, 0, depth / 2);

    glEnd();

    glPopMatrix();
}