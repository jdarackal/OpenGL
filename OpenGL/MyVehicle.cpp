
#include <Windows.h>
#include <GL/glut.h>
#include "MyVehicle.hpp"
#include "RectPrism.hpp"
#include "TriPrism.hpp"
#include "TrapPrism.hpp"
#include "Cylinder.hpp"

myVehicle::myVehicle() : Vehicle() {}

void myVehicle::setRect(double x_, double y_, double z_, double rotation_, double length_, double width_, double depth_) {

    rect_x = x_;
    rect_y = y_;
    rect_z = z_;
    rect_rotation = rotation_;
    rect_length = length_;
    rect_width = width_;
    rect_depth = depth_; 

}

void myVehicle::setTri(double x_, double y_, double z_, double rotation_, double lengthA_, double lengthB_, double theta_, double depth_) {

    tri_x = x_;
    tri_y = y_;
    tri_z = z_;
    tri_rotation = rotation_;
    tri_lengthA = lengthA_;
    tri_lengthB = lengthB_;
    tri_theta = theta_;
    tri_depth = depth_; 

}

void myVehicle::setTrap(double x_, double y_, double z_, double rotation_, double lengthA_, double lengthB_, double height_, double depth_, double offset_) {

    trap_x = x_;
    trap_y = y_;
    trap_z = z_;
    trap_rotation = rotation_;
    trap_lengthA = lengthA_;
    trap_lengthB = lengthB_;
    trap_height = height_;
    trap_depth = depth_; 
    trap_offset = offset_;

}

void myVehicle::setCyl(double x_, double y_, double z_, double rotation_, double radius_, double height_) {

    cyl_x = x_;
    cyl_y = y_;
    cyl_z = z_;
    cyl_rotation = rotation_;
    cyl_radius = radius_;
    cyl_height = height_;

}

void myVehicle::draw() {

    setRect(0, 1, 0, 0, 3, 1.5, 4);
    setTrap(0, 2.5, 0, 0, 3, 1, 1, 4, 1);
    setTri(0, 3.5, 0, 0, 1, 0.707106, 45, 4);
    setCyl(1.55, 0, 1.25, 90, 0.75, 0.1);

    glPushMatrix();
    glRotated(-90, 0, 1, 0);

    glPushMatrix();
    positionInGL();
    glRotated(90, 0, 1, 0);

    // Body

    rectPrism base(rect_x, rect_y, rect_z, rect_rotation, rect_length, rect_width, rect_depth);
    base.draw();

    trapPrism mid(trap_x, trap_y, trap_z, trap_rotation, trap_lengthA, trap_lengthB, trap_height, trap_depth, trap_offset);
    mid.draw();

    triPrism top(tri_x, tri_y, tri_z, tri_rotation, tri_lengthA, tri_lengthB, tri_theta, tri_depth);
    top.draw();

    setColor(0, 0, 1);
    setColorInGL();

    // Front Left Wheel

    glPushMatrix();

    glTranslated(cyl_x, cyl_y, cyl_z);              // position
    glRotated(cyl_rotation - steering, 0, 1, 0);    // steering

    glTranslated(0, cyl_radius, 0);         //
    glRotated(angle, 0, 0, 1);              // rotation
    glTranslated(0, -cyl_radius, 0);        //

    cylinder frontLeft(0, 0, 0, 0, cyl_radius, cyl_height);
    frontLeft.draw();

    glPopMatrix();

    // Front Right Wheel

    glPushMatrix();

    glTranslated(-cyl_x, cyl_y, cyl_z);             // position
    glRotated(cyl_rotation - steering, 0, 1, 0);    // steering

    glTranslated(0, cyl_radius, 0);     //
    glRotated(angle, 0, 0, 1);          // rotation
    glTranslated(0, -cyl_radius, 0);    //

    cylinder frontRight(0, 0, 0, 0, cyl_radius, cyl_height);
    frontRight.draw();

    glPopMatrix();

    // Back Left Wheel

    glPushMatrix();

    glTranslated(cyl_x, cyl_y, -cyl_z); // position
    glRotated(cyl_rotation, 0, 1, 0);

    glTranslated(0, cyl_radius, 0);     //
    glRotated(angle, 0, 0, 1);          // rotation
    glTranslated(0, -cyl_radius, 0);    //

    cylinder backLeft(0, 0, 0, 0, cyl_radius, cyl_height);
    backLeft.draw();

    glPopMatrix();

    // Back Right Wheel

    glPushMatrix();

    glTranslated(-cyl_x, cyl_y, -cyl_z);    // position
    glRotated(cyl_rotation, 0, 1, 0);

    glTranslated(0, cyl_radius, 0);               //
    glRotated(angle, 0, 0, 1);              // rotation
    glTranslated(0, -cyl_radius, 0);              //

    cylinder backRight(0, 0, 0, 0, cyl_radius, cyl_height);
    backRight.draw();

    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    angle += speed / 0.75;
}