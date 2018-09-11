
#include <Windows.h>
#include <GL/glut.h>
#include "MyVehicle.hpp"
#include "RectPrism.hpp"
#include "TriPrism.hpp"
#include "TrapPrism.hpp"
#include "Cylinder.hpp"

myVehicle::myVehicle() : Vehicle() {}

void myVehicle::draw() {
    
    glPushMatrix();

    // Body

    rectPrism base(0, 1, 0, 0, 3, 1.5, 4);
    base.draw();

    trapPrism mid(0, 2.5, 0, 0, 3, 1, 1, 4, 1);
    mid.draw();

    triPrism top(0, 3.5, 0, 0, 1, 0.707106, 45, 4);
    top.draw();


    setColor(1, 0, 0);
    setColorInGL();

    // Wheels

    glPushMatrix();

    glTranslated(1.55, 0, 1.25);

    cylinder frontLeft(0, 0, 0, 90 + steering, 0.75, 0.1);
    frontLeft.draw();

    glPopMatrix();

    glPushMatrix();

    glTranslated(-1.55, 0, 1.25);

    cylinder frontRight(0, 0, 0, 90 + steering, 0.75, 0.1);
    frontRight.draw();

    glPopMatrix();
        
    glPushMatrix();

    glTranslated(1.55, 0, -1.25);

    cylinder backLeft(0, 0, 0, 90, 0.75, 0.1);
    backLeft.draw();

    glPopMatrix();

    glPushMatrix();

    glTranslated(-1.55, 0, -1.25);

    cylinder backRight(0, 0, 0, 90, 0.75, 0.1);
    backRight.draw();

    glPopMatrix();

    glPopMatrix();

}