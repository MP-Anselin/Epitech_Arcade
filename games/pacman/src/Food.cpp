//
// EPITECH PROJECT, 2018
// Wall
// File description:
// Wall
//

#include "../include/Food.hpp"

Food::Food (const float x, const float y)
{
	_size = 0.5;
	_x = x;
	_y = y;
	_Type = 'f';
	_Color.r = 255;
	_Color.g = 255;
	_Color.b = 0;
	_Color.a = 255;
	_destructible = true;
	_life = 1;
	_max_life = 1;
}

float Food::getX () const
{
	return (_x);
}

float Food::getY () const
{
	return (_y);
}

char Food::getType () const
{
	return (_Type);
}

void Food::setLife (int life)
{
	_life = life;
}

void Food::handleEvent (const Event &event)
{
	if (event.getType())
		return;
}

t_Color Food::getColor () const
{
	return (_Color);
}
