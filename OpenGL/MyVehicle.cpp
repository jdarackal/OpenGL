
#include "MyVehicle.hpp"

myVehicle::myVehicle(VehicleModel vm_) : Vehicle() {

    vm = vm_;

    for (int i = 0; i < vm.shapes.size(); i++) {

        switch (vm.shapes[i].type) 
        {

            case UNKNOWN_SHAPE: break;

            case RECTANGULAR_PRISM:
            {
                addShape(new rectPrism(vm.shapes[i].xyz, vm.shapes[i].rgb, vm.shapes[i].rotation, vm.shapes[i].params.rect.xlen, vm.shapes[i].params.rect.ylen, vm.shapes[i].params.rect.zlen));
                break;
            }

            case TRIANGULAR_PRISM:
            {
                addShape(new triPrism(vm.shapes[i].xyz, vm.shapes[i].rgb, vm.shapes[i].rotation, vm.shapes[i].params.tri.alen, vm.shapes[i].params.tri.blen, vm.shapes[i].params.tri.angle, vm.shapes[i].params.tri.depth));
                break;
            }

            case TRAPEZOIDAL_PRISM:
            {
                addShape(new trapPrism(vm.shapes[i].xyz, vm.shapes[i].rgb, vm.shapes[i].rotation, vm.shapes[i].params.trap.alen, vm.shapes[i].params.trap.blen, vm.shapes[i].params.trap.height, vm.shapes[i].params.trap.depth, vm.shapes[i].params.trap.aoff));
                break;
            }

            case CYLINDER:
            {
                addShape(new cylinder(vm.shapes[i].xyz, vm.shapes[i].rgb, vm.shapes[i].rotation, vm.shapes[i].params.cyl.radius, vm.shapes[i].params.cyl.depth, speed, steering, vm.shapes[i].params.cyl.isRolling, vm.shapes[i].params.cyl.isSteering));
                break;
            }

        }

    }

};

void myVehicle::draw() {

    glPushMatrix();
    positionInGL();

    for (int i = 0; i < vm.shapes.size(); i++) {

        switch (vm.shapes[i].type) 
        {

        case UNKNOWN_SHAPE: break;

        case RECTANGULAR_PRISM:
        {
            dynamic_cast<rectPrism*>(shapes[i])->draw();
            break;
        }

        case TRIANGULAR_PRISM:
        {
            dynamic_cast<triPrism*>(shapes[i])->draw();
            break;
        }

        case TRAPEZOIDAL_PRISM:
        {
            dynamic_cast<trapPrism*>(shapes[i])->draw();
            break;
        }

        case CYLINDER:
        {
            dynamic_cast<cylinder*>(shapes[i])->draw();
            break;
        }

        }

    } 

    glPopMatrix();

}