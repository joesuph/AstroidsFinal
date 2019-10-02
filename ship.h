#ifndef ship_h
#define ship_h



#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#define PI 3.14159265359


#include "uiDraw.h"
#include "flyingObject.h"

// Put your Ship class here
class Ship : public FlyingObject
{
private:

	bool alive;
	bool thrust;

public:
	Ship();

	//Getters
	float getRotation()
	{
		return rotation;
	}

	bool getThrust()
	{
		return thrust;
	}
	float getRadians()
	{
		return ((rotation + 90) / 360.0) * 2 * PI;
	}
	float getRadius()
	{
		return SHIP_SIZE;
	}
	void crash()
	{
		alive = false;
	}
	bool getlive()
	{
		return alive;
	}

	//Setters
	void setRotation(float rotation);
	void setThrust(bool thrust);

	void rotateClockwise();
	void rotateCounterClockwise();
	void draw();
	void advance();
};

#endif /* ship_h */
