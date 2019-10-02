/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"
#include "uiDraw.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>

using namespace std;


Game::Game(Point tl, Point br)
{
	this->tl = tl;
	this->br = br;
	
	

	for (int i = 0; i < 5; i++)
	{
		Rock * rock = new BigRock;
		while (getClosestDistance(ship, *rock) <= ship.getRadius() + 30)
		{
			delete rock;
			rock = new BigRock;
		}

		rocks.push_back(rock);
	}

}

int Game::advance()
{
	if (ship.getlive())
		ship.advance();
	else
		endGame();
	advanceBullets();
	advanceRocks();

	return 0;
}

void Game::advanceBullets()
{
	bool life;
	for (int i = 0; i < bullets.size(); i++)
	{
		(bullets[i]).advance();
		life = (bullets[i]).getLive();
		if (!life)
		{
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Game::advanceRocks()
{
	for (int i = 0; i < rocks.size(); i++)
	{

		rocks[i]->advance();
		if (getClosestDistance(ship, *(rocks[i])) <= ship.getRadius() + rocks[i]->getRadius())
		{
			endGame();
		}
		bool hit = false;
		for (int j = 0; j < bullets.size(); j++)
		{
			if (getClosestDistance(bullets[j], *(rocks[i])) <= rocks[i]->getRadius())
			{
				hit = true;
				bullets.erase(bullets.begin() + j);
			}
		}
		if (hit)
		{
			rocks[i]->break_apart(rocks);  //takes the vector by reference and adds the rocks
			delete rocks[i];
			rocks.erase(rocks.begin() + i);
		}
	}
}

void Game::handleInput(const Interface & ui)
{
	if (ui.isUp())
		ship.setThrust(true);
	if (ui.isLeft())
		ship.rotateCounterClockwise();
	if (ui.isRight())
		ship.rotateClockwise();
	if (ui.isSpace())
	{
		int count = 0;
		Bullet bullet;
		bullet.setVelocity(ship.getVelocity(), ship.getRadians());
		bullet.setPoint(ship.getPoint());

		bullets.push_back(bullet);

	}
	return;
}

void Game::draw(const Interface & ui)
{
	//draw Ship
	if (ship.getlive())
		ship.draw();  

	//draw rocks
	for (int i = 0; i < rocks.size(); i++)
	{
		rocks[i]->draw();

	}

	//draw bullets
	if (ship.getlive())
	for (int i = 0; i < bullets.size(); i++)
	{
		(bullets[i]).draw();
	}
}

void Game::endGame()
{
	ship.crash();
	Point ptext(-100, 100);
	
	drawText(ptext, "You lost, great job loser");
}


// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(FlyingObject &obj1, FlyingObject &obj2)
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getXdiff()), abs(obj1.getVelocity().getYdiff()));
   dMax = max(dMax, abs(obj2.getVelocity().getXdiff()));
   dMax = max(dMax, abs(obj2.getVelocity().getYdiff()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getXdiff() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getYdiff() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getXdiff() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getYdiff() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}


