/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include "Spider.hpp"

Spider::Spider (const float x, const float y,
		std::vector<Element *> *elements)
{
	_x = x;
	_y = y;
	_size = 0.7;
	_Color.r = 200;
	_Color.g = 150;
	_Color.b = 200;
	_Color.a = 250;
	_Type = SPIDER;
	_Elements = elements;
	_seconds = 0;
	_destructible = true;
	_life = 1;
	_max_life = 1;
	if (_x == 1)
		_direc_x = 1;
	else if (_x == 38)
		_direc_x = -1;
	if (_y >= 25)
		_direc_y = -1;
	else if (_y <= 25)
		_direc_y = 1;
}

Spider::~Spider ()
{
}

float Spider::getX () const
{
	return (_x);
}

float Spider::getY () const
{
	return (_y);
}

char Spider::getType () const
{
	return (_Type);
}

t_Color Spider::getColor () const
{
	return (_Color);
}

void Spider::setLife (int life)
{
	_life = life;
}

float Spider::collision_y (float x, float y)
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

void Spider::destroy ()
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

void Spider::move ()
{
	if (_y < 29 && _y > rand() % 20) {
		if (1 + rand() % 2 == 2) {
			_y += _direc_y;
		}
		else {
			_y += _direc_y;
			_x += _direc_x;
		}
		if (_y < 21)
			_direc_y = 1;
		if (_y > 27)
			_direc_y = -1;
	}
}

void Spider::dropping ()
{
	float x;
	float y;
	float collision = 0;
	char type;

	for (int i = 0; i < (int) (*_Elements).size(); i++) {
		if (this != (*_Elements)[i]) {
			x = (*_Elements)[i]->getX();
			y = (*_Elements)[i]->getY();
			type = (*_Elements)[i]->getType();
			collision = collision_y(x, y);
			if (collision != 0 && type == PERSONAGE)
				destroy();
		}
	}
	if ((_x + 1 == 39 && _direc_x == 1) || (_x - 1 == 0 && _direc_x == -1))
		destroy();
	else
		move();
}

void Spider::handleEvent (const Event &event)
{
	if (_seconds == 0)
		dropping();
	_seconds += event.getDiff();
	if (_seconds > 150)
		_seconds = 0;
}