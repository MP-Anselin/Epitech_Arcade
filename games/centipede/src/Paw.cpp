//
// EPITECH PROJECT, 2018
// Wall
// File description:
// Wall
//

#include "../include/Paw.hpp"

Paw::Paw (const float x, const float y, int length)
{
	_size = 1.0;
	_x = x;
	_y = y;
	_Type = TAIL;
	_Color.r = 0;
	_Color.g = 255;
	_Color.b = 0;
	_Color.a = 255;
	_destructible = false;
	_length = length;
	_life = 1;
	_max_life = 1;
}

float Paw::getX () const
{
	return (_x);
}

float Paw::getY () const
{
	return (_y);
}

void Paw::setLife (int life)
{
	_life = life;
}

char Paw::getType () const
{
	return (_Type);
}

int Paw::getLength () const
{
	return (_length);
}

void Paw::handleEvent (const Event &event)
{
	if (event.getType())
		return;
}

t_Color Paw::getColor () const
{
	return (_Color);
}
