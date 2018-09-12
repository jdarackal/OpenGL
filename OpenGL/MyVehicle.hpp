
#ifndef MYVEHICLE_H
#define MYVEHICLE_H

#include <Windows.h>
#include <GL/glut.h>
#include "Vehicle.hpp"
#include "RectPrism.hpp"
#include "TriPrism.hpp"
#include "TrapPrism.hpp"
#include "Cylinder.hpp"

class myVehicle : public Vehicle {

public:
    myVehicle();

    void setRect(double x_, double y_, double z_, double rotation_, double length_, double width_, double depth_);
    void setTri(double x_, double y_, double z_, double rotation_, double lengthA_, double lengthB_, double theta_, double depth_);
    void setTrap(double x_, double y_, double z_, double rotation_, double lengthA_, double lengthB_, double height_, double depth_, double offset_);
    void setCyl(double x_, double y_, double z_, double rotation_, double radius_, double height_);

    void setRolling(bool isRolling_);
    void setSteering(bool isSteering_);

    void draw();    

protected:
    double angle = 0;
    
    double rect_x;
    double rect_y;
    double rect_z;
    double rect_rotation;
    double rect_length;
    double rect_width;
    double rect_depth;

    double tri_x;
    double tri_y;
    double tri_z;
    double tri_rotation;
    double tri_lengthA;
    double tri_lengthB;
    double tri_theta;
    double tri_depth;

    double trap_x;
    double trap_y;
    double trap_z;
    double trap_rotation;
    double trap_lengthA;
    double trap_lengthB;
    double trap_height;
    double trap_depth;
    double trap_offset;

    double cyl_x;
    double cyl_y;
    double cyl_z;
    double cyl_rotation;
    double cyl_radius;
    double cyl_height;

    bool isRolling;
    bool isSteering;

};
#endif

