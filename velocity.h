#ifndef VELOCITY_H
#define VELOCITY_H


// Put your velocity class here, or overwrite this file with your own
// velocity class from the previous project
class Velocity
{
private:
	float Xdiff;
	float Ydiff;
public:
	Velocity();
	Velocity(float Xdiff, float Ydiff);

	//Getters
	float getXdiff()
	{
		return Xdiff;
	}
	float getYdiff()
	{
		return Ydiff;
	}

	//Setters
	void setXdiff(float Xdiff);
	void setYdiff(float Ydiff);
};

#endif /* velocity_h */
