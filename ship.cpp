#include <math.h>
#include "ship.h"
#include <iostream>
using namespace std;


// Put your ship methods here

Ship::Ship()
{
	alive = true;
	thrust = false;
	rotation = 0;
}

void Ship::setRotation(float rotation)
{
	this->rotation = rotation;
}

/*******************************
* Replaces the thrust variable
********************************/
void Ship::setThrust(bool thrust)
{
	this->thrust = thrust;
}

/**************************************
* Draws the ship at its angle and point
***************************************/
void Ship::draw()
{

	drawShip(point, rotation, thrust);
}


void Ship::rotateClockwise()
{
	rotation -= ROTATE_AMOUNT;
}

void Ship::rotateCounterClockwise()
{
	rotation += ROTATE_AMOUNT;
}
/**************************************
* Advances the ship
****************************************/
void Ship::advance()
{
	FlyingObject::advance();

	if (thrust)
	{
		float radians = ((rotation + 90) / 360.0) * 2 * PI;
		float Xdiff = THRUST_AMOUNT * cos(radians);
		float Ydiff = THRUST_AMOUNT * sin(radians);
		velocity.setXdiff(velocity.getXdiff() + Xdiff);
		velocity.setYdiff(velocity.getYdiff() + Ydiff);
	}

	if (rotation > 360)
		rotation -= 360;
	if (rotation < 0)
		rotation += 360;

	thrust = false;

}