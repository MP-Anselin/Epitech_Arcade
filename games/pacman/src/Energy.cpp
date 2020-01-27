//
// EPITECH PROJECT, 2018
// Wall
// File description:
// Wall
//

#include "../include/Energy.hpp"

Energy::Energy (const float x, const float y)
{
	_size = 0.75;
	_x = x;
	_y = y;
	_Type = ENERGY;
	_Color.r = 255;
	_Color.g = 0;
	_Color.b = 0;
	_Color.a = 255;
	_destructible = true;
	_life = 1;
	_max_life = 1;
}

float Energy::getX () const
{
	return (_x);
}

float Energy::getY () const
{
	return (_y);
}

char Energy::getType () const
{
	return (_Type);
}

void Energy::setLife (int life)
{
	_life = life;
}


void Energy::handleEvent (const Event &event)
{
	if (event.getType())
		return;
}

t_Color Energy::getColor () const
{
	return (_Color);
}
