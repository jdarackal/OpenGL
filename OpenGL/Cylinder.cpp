
#include <GL/glut.h>
#include "Cylinder.hpp"

cylinder::cylinder() : Shape() {}

cylinder::cylinder(double x_, double y_, double z_) : Shape(x_, y_, z_) {}

cylinder::cylinder(double x_, double y_, double z_, double rotation_, double radius_, double height_) : Shape(x_, y_, z_, rotation_) {
    radius = radius_;
    height = height_;
}

void cylinder::draw() {

    GLUquadric * cylinder = gluNewQuadric();
    GLUquadric * disk1 = gluNewQuadric();
    GLUquadric * disk2 = gluNewQuadric();

    
    glPushMatrix();

    positionInGL();

    glTranslated(0, radius, -height / 2);

    gluDisk(disk1, 0, radius, 200, 1);
    gluCylinder(cylinder, radius, radius, height, 200, 1);

    glTranslated(0, 0, height);

    gluDisk(disk2, 0, radius, 200, 1);

    glPopMatrix();

}