/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include "ship.h"
#include "uiInteract.h"
#include "bullet.h"
#include "rocks.h"
#include "velocity.h"
#include <iostream>
#include <vector>

#define MAX_ROCKS 20
#define MAX_BULLETS 30

class Game
{
private:
	Point tl;
	Point br;
	Ship ship;
	std::vector<Rock*> rocks;
	std::vector<Bullet> bullets;
	
public:

	Game(Point tl, Point br);
	~Game()
	{
		for (int i = 0; i < rocks.size(); i++)
		{
			delete rocks[i];
			rocks.erase(rocks.begin() + i);
		}
	}

	void endGame();
	int advance();
	void advanceBullets();
	void advanceRocks();
	void handleInput(const Interface & ui);
	void draw(const Interface & ui);
	float getClosestDistance(FlyingObject &obj1, FlyingObject &obj2);
	
};


#endif /* GAME_H */
