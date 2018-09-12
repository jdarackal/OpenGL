
#ifndef MTRN3500_VEHICLE_H
#define MTRN3500_VEHICLE_H

#include <iostream>
#include "Shape.hpp"
#include "VectorMaths.hpp"
#include <vector>

class Vehicle : public Shape {
	friend void remoteDriver(Vehicle * vehicle, double x, double z, double r, double speed_, double steering_);

public:
	Vehicle();
	virtual ~Vehicle();

	virtual void update(double dt);
	virtual void update(double speed_, double steering_, double dt);

	virtual void draw() = 0;

    virtual void setRect(double x_, double y_, double z_, double rotation_, double length_, double width_, double depth_) = 0;
    virtual void setTri(double x_, double y_, double z_, double rotation_, double lengthA_, double lengthB_, double theta_, double depth_) = 0;
    virtual void setTrap(double x_, double y_, double z_, double rotation_, double lengthA_, double lengthB_, double height_, double depth_, double offset_) = 0;
    virtual void setCyl(double x_, double y_, double z_, double rotation_, double radius_, double height_) = 0;

    virtual void setRolling(bool isRolling_) = 0;
    virtual void setSteering(bool isSteering_) = 0;

	static const int MAX_FORWARD_SPEED_MPS = 10;
	static const int MAX_BACKWARD_SPEED_MPS = -4;
	static const int MAX_LEFT_STEERING_DEGS = 15;
	static const int MAX_RIGHT_STEERING_DEGS = -15;
	static const int VEHICLE_BOUNDS = 3;

	double getSpeed() const { return speed; }
	double getSteering() const { return steering; }

	void addShape(Shape * shape);
protected:
	double speed;     // m/s
	double steering;  // degrees

	std::vector<Shape *> shapes;
};

double clamp(double a, double n, double b);

#endif // for MTRN3500_VEHICLE_H

