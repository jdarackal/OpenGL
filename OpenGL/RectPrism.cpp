
#include <GL/glut.h>
#include "RectPrism.hpp"

rectPrism::rectPrism(float xyz[3]) : Shape(xyz[0], xyz[1], xyz[2]) {}

rectPrism::rectPrism(float xyz[3], float rgb[3], double rotation_, double xlen_, double ylen_, double zlen_) : Shape(xyz[0], xyz[1], xyz[2], rotation_) {
    xlen = xlen_;
    ylen = ylen_;
    zlen = zlen_;
    setColor(rgb[0], rgb[1], rgb[2]);
}

void rectPrism::draw() {

    glPushMatrix();

    positionInGL();
    setColorInGL();

    glBegin(GL_QUAD_STRIP);

    glVertex3d(-xlen / 2, 0, -zlen / 2);
    glVertex3d(xlen / 2, 0, -zlen / 2);
    glVertex3d(-xlen / 2, 0, zlen / 2);
    glVertex3d(xlen / 2, 0, zlen / 2);

    glVertex3d(-xlen / 2, ylen, zlen / 2);
    glVertex3d(xlen / 2, ylen, zlen / 2);

    glVertex3d(-xlen / 2, ylen, -zlen / 2);
    glVertex3d(xlen / 2, ylen, -zlen / 2);

    glVertex3d(-xlen / 2, 0, -zlen / 2);
    glVertex3d(xlen / 2, 0, -zlen / 2);

    glEnd();

    glBegin(GL_QUADS);

    glVertex3d(xlen / 2, 0, -zlen / 2);
    glVertex3d(xlen / 2, 0, zlen / 2);
    glVertex3d(xlen / 2, ylen, zlen / 2);
    glVertex3d(xlen / 2, ylen, -zlen / 2);

    glVertex3d(-xlen / 2, 0, -zlen / 2);
    glVertex3d(-xlen / 2, 0, zlen / 2);
    glVertex3d(-xlen / 2, ylen, zlen / 2);
    glVertex3d(-xlen / 2, ylen, -zlen / 2);

    glEnd();

    glPopMatrix();
}

