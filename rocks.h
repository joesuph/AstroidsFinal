#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 18
#define MEDIUM_ROCK_SIZE 12
#define SMALL_ROCK_SIZE 8

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"
#include "uiDraw.h"
#include <string>
#include <vector>
#include <iostream>
#include "drawasteroids.h"



// Define the following classes here:
//   Rock
class Rock : public FlyingObject
{
protected:
	float radius;
	bool live;
	int spin;
	std::string id;

public:
	Rock();
	float getRadius()
	{
		return radius;
	}
	bool getLive()
	{
		return live;
	}
	std::string getId()
	{
		return id;
	}
	void setLive(bool live);
	virtual void draw() = 0;
	virtual void break_apart(std::vector<Rock*> & rocks) = 0;
	void advance();
};

//   BigRock
class BigRock : public Rock
{

public:
	BigRock();
	void draw();
	void break_apart(std::vector<Rock*> & rocks);
};


//   MediumRock
class MediumRock : public Rock
{
public:
	MediumRock(Point point, Velocity velocity);
	void draw();
	void break_apart(std::vector<Rock*> & rocks);
};
//   SmallRock
class SmallRock : public Rock
{
public:
	SmallRock(Point point, Velocity velocity);
	void draw();
	void break_apart(std::vector<Rock*> & rocks);
};


#endif /* rocks_h */
