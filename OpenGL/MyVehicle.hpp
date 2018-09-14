
#ifndef MYVEHICLE_H
#define MYVEHICLE_H

#include <Windows.h>
#include <GL/glut.h>
#include "Messages.hpp"
#include "Vehicle.hpp"
#include "RectPrism.hpp"
#include "TriPrism.hpp"
#include "TrapPrism.hpp"
#include "Cylinder.hpp"

class myVehicle : public Vehicle {

public:
    myVehicle(VehicleModel vm_);

    void draw();   

protected:
    VehicleModel vm;

};
#endif

