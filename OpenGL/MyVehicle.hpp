
#ifndef MYVEHICLE_H
#define MYVEHICLE_H

#include "Vehicle.hpp"

class myVehicle : public Vehicle {

public:
    myVehicle();

    void draw();

    double angle = 0;
};
#endif

