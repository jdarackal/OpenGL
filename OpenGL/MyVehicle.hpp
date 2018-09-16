
#ifndef MYVEHICLE_H
#define MYVEHICLE_H

#include "Messages.hpp"
#include "Vehicle.hpp"

class myVehicle : public Vehicle {

public:
    myVehicle(VehicleModel vm_);

    void draw();   

protected:
    VehicleModel vm;
    std::vector<double> roll;
    int c;

};
#endif

