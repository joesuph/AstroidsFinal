#include "bullet.h"
#include <iostream>
using namespace std;

Bullet::Bullet()
{
	life = 0;
}


void Bullet::advance()
{
	life++;
	FlyingObject::advance();
}

bool Bullet::getLive()
{
	if (life >= BULLET_LIFE)
		return false;
	else
		return true;
}



void Bullet::setVelocity(Velocity velocity, float radians)
{

	float Xdiff = BULLET_SPEED * cos(radians); 
	float Ydiff = BULLET_SPEED * sin(radians);
	Velocity nvelocity(velocity.getXdiff() + Xdiff, velocity.getYdiff() + Ydiff);
	this->velocity = nvelocity;

}


void Bullet::draw()
{
	drawDot(point);
}

// Put your bullet methods here
