
#include <GL/glut.h>
#include "Cylinder.hpp"

cylinder::cylinder(float xyz[3]) : Shape(xyz[0], xyz[1], xyz[2]) {}

cylinder::cylinder(float xyz[3], float rgb[3], double rotation_, double radius_, double depth_, double speed_, double steering_, double roll_, bool isRolling_, bool isSteering_) : Shape(xyz[0], xyz[1], xyz[2], rotation_) {
    radius = radius_;
    depth = depth_;
    setColor(rgb[0], rgb[1], rgb[2]);
    speed = speed_;
    steering = steering_;
    roll = roll_;
    isRolling = isRolling_;
    isSteering = isSteering_;
}

void cylinder::draw() {

    GLUquadric * cylinder = gluNewQuadric();
    GLUquadric * disk1 = gluNewQuadric();
    GLUquadric * disk2 = gluNewQuadric();
    
    glPushMatrix();

    positionInGL();
    setColorInGL();

    if (isSteering) {
        glRotated(-steering * isSteering, 0, 1, 0);  // steering
    }

    if (isRolling) {
        glTranslated(0, radius, 0);                 //
        glRotated(-roll * isRolling, 0, 0, 1);      // rolling
        glTranslated(0, -radius, 0);                //
    }

    glTranslated(0, radius, -depth / 2);

    gluDisk(disk1, 0, radius, 4, 1);
    gluCylinder(cylinder, radius, radius, depth, 4, 1);

    glTranslated(0, 0, depth);

    gluDisk(disk2, 0, radius, 4, 1);

    glPopMatrix();
}