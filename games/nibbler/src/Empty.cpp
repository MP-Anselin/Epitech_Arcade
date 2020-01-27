//
// EPITECH PROJECT, 2018
// Wall
// File description:
// Wall
//

#include "../include/Empty.hpp"

Empty::Empty (const float x, const float y)
{
	_size = 0;
	_x = x;
	_y = y;
	_Type = EMPTY;
	_Color.r = 255;
	_Color.g = 255;
	_Color.b = 0;
	_Color.a = 255;
	_destructible = true;
	_life = 1;
	_max_life = 1;
}

float Empty::getX () const
{
	return (_x);
}

float Empty::getY () const
{
	return (_y);
}

char Empty::getType () const
{
	return (_Type);
}

void Empty::setLife (int life)
{
	_life = life;
}

void Empty::handleEvent (const Event &event)
{
	if (event.getType())
		return;
}

t_Color Empty::getColor () const
{
	return (_Color);
}
