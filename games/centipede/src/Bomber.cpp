/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include "Bomber.hpp"

Bomber::Bomber (const float x, const float y,
		std::vector<Element *> *elements)
{
	_x = x;
	_y = y;
	_size = 0.8;
	_Color.r = 10;
	_Color.g = 150;
	_Color.b = 250;
	_Color.a = 255;
	_Type = BOMBER;
	_Impact = 1;
	_seconds = 0;
	_Elements = elements;
	_destructible = true;
	_life = 1;
	_max_life = 1;
}

Bomber::~Bomber ()
{
}

float Bomber::getX () const
{
	return (_x);
}

float Bomber::getY () const
{
	return (_y);
}

char Bomber::getType () const
{
	return (_Type);
}

t_Color Bomber::getColor () const
{
	return (_Color);
}

void Bomber::setLife (int life)
{
	_life = life;
}

float Bomber::collision_y (float x, float y)
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

void Bomber::destroy ()
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

void Bomber::dropping (int is_ok)
{
	float x;
	float y;
	float collision = 0;
	int stop = 0;
	char type;

	for (int i = 0; i < (int) (*_Elements).size(); i++) {
		if (this != (*_Elements)[i]) {
			x = (*_Elements)[i]->getX();
			y = (*_Elements)[i]->getY();
			type = (*_Elements)[i]->getType();
			collision = collision_y(x, y);
			if (collision != 0 && type == PERSONAGE)
				destroy();
			else if (is_ok == 3 && collision == 0 && stop == 0
				 && _y < 28 && _y > 2) {
				stop = 1;
				(*_Elements).push_back(new Mushroom(_x, _y - 1,
								    _Elements));
			}
		}
	}
	if (_y + 1 == 29)
		destroy();
	else
		_y += 1;

}

void Bomber::handleEvent (const Event &event)
{
	static int is_ok = 0;

	if (_seconds == 0) {
		dropping(is_ok);
		if (is_ok > 4)
			is_ok = rand() % 3;
		is_ok++;
	}
	_seconds += event.getDiff();
	if (_seconds > 200)
		_seconds = 0;
}