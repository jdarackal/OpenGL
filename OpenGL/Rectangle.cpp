
#include <GL/glut.h>
#include "Rectangle.hpp"

rectangle::rectangle() : Shape() {}

rectangle::rectangle(double x_, double y_, double z_) : Shape(x_, y_, z_) {}

rectangle::rectangle(double x_, double y_, double z_, double rotation_, double length_, double width_) : Shape(x_, y_, z_, rotation_) {
    length = length_;
    width = width_;
}

void rectangle::SetLength(double length_) {
    length = length_;
}

void rectangle::SetWidth(double width_) {
    width = width_;
}

void rectangle::draw() {
    glPushMatrix();

    positionInGL();
    glRotated(rotation, 0, 1, 0);

    glBegin(GL_QUADS);

    glVertex3d(-length / 2, -width / 2, 0);
    glVertex3d(length / 2, -width / 2, 0);
    glVertex3d(length / 2, width / 2, 0);
    glVertex3d(-length / 2, width / 2, 0);

    setColorInGL();

    glEnd();

    glPopMatrix();
}

