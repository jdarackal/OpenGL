#include "Wheels.hpp"
#include <Windows.h>
#include <GL/glut.h>
#include "MyVehicle.hpp"
#include "RectPrism.hpp"
#include "TriPrism.hpp"
#include "TrapPrism.hpp"
#include "Cylinder.hpp"
#include "Vehicle.hpp"

Wheel::Wheel() : Shape() {}

Wheel::Wheel()
{
    addShape(new cylinder());
    addShape(new rectPrism(0.05, 0.0, 0.5));
    dynamic_cast<cylinder*>(shapes[0])->set_radius(0.75);
    dynamic_cast<cylinder*>(shapes[0])->set_y(1.0);
    dynamic_cast<rectPrism*>(shapes[1])->set_x(2.0);
    dynamic_cast<rectPrism*>(shapes[1])->set_y(2.4);
    dynamic_cast<rectPrism*>(shapes[1])->set_z(3.2);
    
    wheel_rotation = 0;
}
