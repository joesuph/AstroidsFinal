#include "velocity.h"

Velocity::Velocity()
{
	Xdiff = 0;
	Ydiff = 0;
}

/******************************************
*
*******************************************/
Velocity::Velocity(float Xdiff, float Ydiff)
{
	this->Xdiff = Xdiff;
	this->Ydiff = Ydiff;

}

// Put your velocity methods here
/*****************************************
* Set the x difference in pixels per frame
*****************************************/
void Velocity::setXdiff(float Xdiff)
{
	this->Xdiff = Xdiff;
}

/*****************************************
* Set the y difference in pixels per frame
*****************************************/
void Velocity::setYdiff(float Ydiff)
{
	this->Ydiff = Ydiff;
}