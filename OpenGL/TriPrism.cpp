
#include <GL/glut.h>
#include "TriPrism.hpp"
#include "math.h"

triPrism::triPrism() : Shape() {}

triPrism::triPrism(double x_, double y_, double z_) : Shape(x_, y_, z_) {}

triPrism::triPrism(double x_, double y_, double z_, double rotation_, double lengthA_, double lengthB_, double theta_, double depth_) : Shape(x_, y_, z_, rotation_) {
    lengthA = lengthA_;
    lengthB = lengthB_;
    theta = theta_ * 3.1415 / 180;
    depth = depth_;
}

void triPrism::draw() {

    glPushMatrix();

    positionInGL();

    glBegin(GL_TRIANGLES);

    glVertex3d(lengthA / 2, 0, -depth / 2);
    glVertex3d(-lengthA / 2, 0, -depth / 2);
    glVertex3d(lengthB * cos(theta) - lengthA / 2, lengthB * sin(theta), -depth / 2);

    glVertex3d(lengthA / 2, 0, depth / 2);
    glVertex3d(-lengthA / 2, 0, depth / 2);
    glVertex3d(lengthB * cos(theta) - lengthA / 2, lengthB * sin(theta), depth / 2);

    glEnd();

    glBegin(GL_QUAD_STRIP);

    glVertex3d(lengthA / 2, 0, -depth / 2);
    glVertex3d(lengthA / 2, 0, depth / 2);
    glVertex3d(-lengthA / 2, 0, -depth / 2);
    glVertex3d(-lengthA / 2, 0, depth / 2);

    glVertex3d(lengthB * cos(theta) - lengthA / 2, lengthB * sin(theta), -depth / 2);
    glVertex3d(lengthB * cos(theta) - lengthA / 2, lengthB * sin(theta), depth / 2);

    glVertex3d(lengthA / 2, 0, -depth / 2);
    glVertex3d(lengthA / 2, 0, depth / 2);

    glEnd();

    glPopMatrix();
}
