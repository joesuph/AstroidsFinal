#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"

class FlyingObject
{
protected:
	Velocity velocity;
	Point point;
	int rotation;

public:
	//Getters
	Velocity getVelocity()
	{
		return velocity;
	}
	Point getPoint()
	{
		return point;
	}
	int getRotation()
	{
		return rotation;
	}

	//Setters
	void setVelocity(Velocity velocity);
	void setPoint(Point point);
	void setRotation(int rotation);
	void advance();
};



// Put your FlyingObject class here




#endif /* flyingObject_h */
