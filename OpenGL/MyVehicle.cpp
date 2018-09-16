
#include <Windows.h>
#include <GL/glut.h>
#include "MyVehicle.hpp"
#include "RectPrism.hpp"
#include "TriPrism.hpp"
#include "TrapPrism.hpp"
#include "Cylinder.hpp"

myVehicle::myVehicle() {};

myVehicle::myVehicle(VehicleModel vm_) : Vehicle() {

    vm = vm_;
    c = 0;

};

void myVehicle::draw() {

    int rollcount = 0;

    glPushMatrix();
    positionInGL();
    
    for (int i = 0; i < vm.shapes.size(); i++, c++) {

        switch (vm.shapes[i].type) {

            case UNKNOWN_SHAPE: break;

            case RECTANGULAR_PRISM:
                {
                    addShape(new rectPrism(vm.shapes[i].xyz, vm.shapes[i].rgb, vm.shapes[i].rotation, vm.shapes[i].params.rect.xlen, vm.shapes[i].params.rect.ylen, vm.shapes[i].params.rect.zlen));
                    dynamic_cast<rectPrism*>(shapes[i])->draw();
                    break;
                }

            case TRIANGULAR_PRISM:
                {
                    addShape(new triPrism(vm.shapes[i].xyz, vm.shapes[i].rgb, vm.shapes[i].rotation, vm.shapes[i].params.tri.alen, vm.shapes[i].params.tri.blen, vm.shapes[i].params.tri.angle, vm.shapes[i].params.tri.depth));
                    dynamic_cast<triPrism*>(shapes[i])->draw();
                    break;
                }

            case TRAPEZOIDAL_PRISM:
                {
                    addShape(new trapPrism(vm.shapes[i].xyz, vm.shapes[i].rgb, vm.shapes[i].rotation, vm.shapes[i].params.trap.alen, vm.shapes[i].params.trap.blen, vm.shapes[i].params.trap.height, vm.shapes[i].params.trap.depth, vm.shapes[i].params.trap.aoff));
                    dynamic_cast<trapPrism*>(shapes[i])->draw();
                    break;
                }

            case CYLINDER:
                {
                    if (c < vm.shapes.size()) {
                        roll.push_back(speed / vm.shapes[i].params.cyl.radius);
                    } else {
                        roll[rollcount] += speed / vm.shapes[i].params.cyl.radius;
                    }
                
                    addShape(new cylinder(vm.shapes[i].xyz, vm.shapes[i].rgb, vm.shapes[i].rotation, vm.shapes[i].params.cyl.radius, vm.shapes[i].params.cyl.depth, speed, steering, roll[rollcount], vm.shapes[i].params.cyl.isRolling, vm.shapes[i].params.cyl.isSteering));
                    dynamic_cast<cylinder*>(shapes[i])->draw();

                    rollcount++;
                
                    break;
                }

        }

    }

    shapes.clear();
    
    glPopMatrix();

}