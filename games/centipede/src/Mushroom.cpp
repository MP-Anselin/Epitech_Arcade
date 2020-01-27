/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include "Mushroom.hpp"

Mushroom::Mushroom (const float x, const float y,
		    std::vector<Element *> *elements)
{
	_x = x;
	_y = y;
	_size = 0.6;
	_Type = MUSHROOM;
	_Color.r = 150;
	_Color.g = 125;
	_Color.b = 120;
	_Color.a = 255;
	_Impact = 5;
	_Elements = elements;
	_destructible = true;
	_life = 5;
	_max_life = 5;
}

Mushroom::~Mushroom ()
{
}

float Mushroom::getX () const
{
	return (_x);
}

float Mushroom::getY () const
{
	return (_y);
}

char Mushroom::getType () const
{
	return (_Type);
}

t_Color Mushroom::getColor () const
{
	return (_Color);
}

void Mushroom::setLife (int life)
{
	_life = life;
}

void Mushroom::destroy ()
{
	std::vector<Element *>::iterator it = std::find(
		(*_Elements).begin(),
		(*_Elements).end(),
		this);
	if ((*_Elements).end() != std::find(
		(*_Elements).begin(),
		(*_Elements).end(),
		this)) {
		(*_Elements).erase(it);
	}
}


float Mushroom::collision_y (float x, float y)
{
	if ((x <= _x && _x < x + 1) ||
	    (x < _x + 1 && _x + 1 <= x + 1)) {
		if (y <= _y && _y < y + 1) {
			return (1);
		}
		if (y < _y + 1 && _y + 1 <= y + 1) {
			return (-1);
		}
	}
	return (0.0);
}

float Mushroom::collision_x (float x, float y)
{
	if ((y <= _y && _y < y + 1) ||
	    (y < _y + 1 && _y + 1 <= y + 1)) {
		if (x <= _x && _x < x + 1) {
			return (1);
		}
		if (x < _x + 1 && _x + 1 <= x + 1 && (_x - 1 > 0)) {
			return (-1);
		}
	}
	return (0.0);
}

void Mushroom::handleEvent (const Event &event)
{
	float x = 0;
	float y = 0;
	float col1 = 0;
	float col2 = 0;
	char type;

	(void) event;
	for (int i = 0; i < (int) (*_Elements).size(); i++) {
		if (this != (*_Elements)[i]) {
			x = (*_Elements)[i]->getX();
			y = (*_Elements)[i]->getY();
			type = (*_Elements)[i]->getType();
			if (type == 'd') {
				col1 = collision_y(x, y);
				col2 = collision_x(x, y);
				if (type == 'd' && (col1 != 0 || col2 != 0))
					destroy();
			}
		}
	}
}