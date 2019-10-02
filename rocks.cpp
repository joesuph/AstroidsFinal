
#include "rocks.h"
#include <math.h>

#define PI 3.14159265359
// Put your Rock methods here
Rock::Rock()
{

}

void Rock::advance()
{
	FlyingObject::advance();
	rotation += spin;
}

void Rock::setLive(bool live)
{
	this->live = live;
}

SmallRock::SmallRock(Point point,Velocity velocity)
{
	spin = SMALL_ROCK_SPIN;
	id = "smallRock";
	radius = SMALL_ROCK_SIZE;
	this->point = point;
	this->velocity = velocity;

}

MediumRock::MediumRock(Point point, Velocity velocity)
{
	spin = MEDIUM_ROCK_SPIN;
	id = "mediumRock";
	radius = MEDIUM_ROCK_SIZE;
	this->point = point;
	this->velocity = velocity;
	
}

BigRock::BigRock()
{
	spin = BIG_ROCK_SPIN;
	id = "bigRock";
	radius = BIG_ROCK_SIZE;
	float x = random(-200, 200);
	float y = random(-200, 200);
	Point npoint(x, y);
	setPoint(npoint);
	live = false;
	float speed = 1;
	float angle = random(0, 360);
	float radians = (angle / 360.0) * 2 * PI;
	float Xdiff = speed * cos(radians);
	float Ydiff = speed * sin(radians);
	Velocity nvelocity(Xdiff, Ydiff);
	setVelocity(nvelocity);
}

void SmallRock::break_apart(std::vector<Rock*> & rocks)
{

}

void MediumRock::break_apart(std::vector<Rock*> & rocks)
{
	Velocity smallVelocity1 = getVelocity();
	Velocity smallVelocity2 = getVelocity();

	smallVelocity1.setXdiff(smallVelocity1.getXdiff() + 3);
	smallVelocity2.setXdiff(smallVelocity2.getXdiff() - 3);

	Rock * rock1 = new SmallRock(getPoint(), smallVelocity1);
	Rock * rock2 = new SmallRock(getPoint(), smallVelocity2);

	rocks.push_back(rock1);
	rocks.push_back(rock2);
}

void BigRock::break_apart(std::vector<Rock*> & rocks)
{
	Velocity smallVelocity = getVelocity();
	Velocity mediumVelocity1 = getVelocity();
	Velocity mediumVelocity2 = getVelocity();

	smallVelocity.setXdiff(smallVelocity.getXdiff() + 2);
	mediumVelocity1.setYdiff(mediumVelocity1.getYdiff() + 1);
	mediumVelocity2.setYdiff(mediumVelocity2.getYdiff() - 1);

	Rock * rock1 = new SmallRock(getPoint(), smallVelocity);
	Rock * rock2 = new MediumRock(getPoint(), mediumVelocity1);
	Rock * rock3 = new MediumRock(getPoint(), mediumVelocity2);

	rocks.push_back(rock1);
	rocks.push_back(rock2);
	rocks.push_back(rock3);
}


void SmallRock::draw()
{

	drawSmallAsteroid(point, rotation);
	//drawCircle(point, SMALL_ROCK_SIZE);
}


void MediumRock::draw()
{

	drawMediumAsteroid(point, rotation);
	//drawCircle(point, MEDIUM_ROCK_SIZE);
}

void BigRock::draw()
{

	drawLargeAsteroid(point, rotation);
	//drawCircle(point, BIG_ROCK_SIZE);

}