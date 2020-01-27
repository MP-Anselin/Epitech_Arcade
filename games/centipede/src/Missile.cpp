/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include "Missile.hpp"

Missile::Missile (const float x, const float y,
		  std::vector<Element *> *elements)
{
	_x = x;
	_y = y;
	_nbr_kill = 0;
	_size = 1;
	_Type = MISSILE;
	_Color.r = 100;
	_Color.g = 150;
	_Color.b = 250;
	_Color.a = 255;
	_Elements = elements;
	_destructible = false;
	_life = 1;
	_max_life = 1;
}

Missile::~Missile ()
{
}

float Missile::getX () const
{
	return (_x);
}

float Missile::getY () const
{
	return (_y);
}

t_Color Missile::getColor () const
{
	return (_Color);
}

char Missile::getType () const
{
	return (_Type);
}

int Missile::getLength () const
{
	return (_length);
}

void Missile::setLife (int life)
{
	_life = life;
}

float Missile::collision_y (float x, float y)
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

void Missile::explosion (float collision)
{
	if (collision) {
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
}

int Missile::kill_millipede (int el)
{
	if ((*_Elements)[el]->getLife() == 0 || 1) {
		(*_Elements)[el]->setLife(0);
		return (1);
	}
	return (0);
}

void Missile::collisonSubElement (int el)
{
	std::vector < Element * > sub_elements;
	int collision;
	float x = 0;
	float y = 0;

	sub_elements = (*_Elements)[el]->getSubElements();
	for (int i = 0; i < (int) sub_elements.size(); i++) {
		x = sub_elements[i]->getX();
		y = sub_elements[i]->getY();
		collision = collision_y(x, y);
		if (collision) {
			explosion(collision);
			(*_Elements)[el]->hasCollision(i);
			if (kill_millipede(el) == 1)
				break;
		}
	}
}

void Missile::collison ()
{
	float x;
	float y;
	float collision = 0;

	for (int i = 0; i < (int) (*_Elements).size(); i++) {
		if (this != (*_Elements)[i]) {
			x = (*_Elements)[i]->getX();
			y = (*_Elements)[i]->getY();
			collision = collision_y(x, y);
			if (collision) {
				explosion(collision);
				(*_Elements)[i]->hasCollision(-1);
				if ((*_Elements)[i]->getLife() == 0 &&
				    (*_Elements)[i]->getType() != MILLIPEDE) {
					_Elements->erase(
						_Elements->begin() + i);
				}
			}
			collisonSubElement(i);
		}
	}
}

void Missile::handleEvent (const Event &event)
{
	float seconds;
	float length;

	seconds = (float) event.getDiff() / 1000.0;
	length = 15 * seconds;
	_y = _y - length;
	collison();
}
