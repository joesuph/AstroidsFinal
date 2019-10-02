#include "flyingObject.h"
#include <math.h>
#include <iostream>
using namespace std;

/*******************************
* Replaces the velocity variable
********************************/
void FlyingObject::setVelocity(Velocity velocity)
{
	this->velocity = velocity;
}

/*******************************
* Replaces the point variable
********************************/
void FlyingObject::setPoint(Point point)
{
	this->point = point;
}

void FlyingObject::advance()
{
	point.setX(point.getX() + velocity.getXdiff());
	point.setY(point.getY() + velocity.getYdiff());

	if (point.getX() > 200)
		point.setX(-200);
	if (point.getX() < -200)
		point.setX(200);
	if (point.getY() > 200)
		point.setY(-200);
	if (point.getY() < -200)
		point.setY(200);
}

/*******************************
* Replaces the angle variable
********************************/
void FlyingObject::setRotation(int rotation)
{
	this->rotation = rotation;
}


// Put your FlyingObject method bodies here
