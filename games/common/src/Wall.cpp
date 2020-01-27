//
// EPITECH PROJECT, 2018
// Wall
// File description:
// Wall
//

#include "../include/Wall.hpp"

Wall::Wall (const float x, const float y, const float size)
{
	_size = size;
	_x = x;
	_y = y;
	_Type = WALL;
	_Color.r = 0;
	_Color.g = 0;
	_Color.b = 255;
	_Color.a = 255;
	_destructible = false;
	_life = 1;
	_max_life = 1;
}

float Wall::getX () const
{
	return (_x);
}

float Wall::getY () const
{
	return (_y);
}

char Wall::getType () const
{
	return (_Type);
}

void Wall::setLife (int life)
{
	_life = life;
}


void Wall::handleEvent (const Event &event)
{
	if (event.getType())
		return;
}

t_Color Wall::getColor () const
{
	return (_Color);
}
