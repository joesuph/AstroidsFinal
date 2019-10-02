#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include "flyingObject.h"
#include "uiDraw.h"

class Bullet : public FlyingObject
{
private:
	int life;
	bool live;

public:

	Bullet();

	bool getLive();
	void setVelocity(Velocity velocity, float radians);
	void advance();
	void draw();
};





#endif /* bullet_h */
