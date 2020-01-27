//
// EPITECH PROJECT, 2018
// Wall
// File description:
// Wall
//

#include "../include/TeleportationPortal.hpp"


TeleportationPortal::TeleportationPortal (const float x, const float y,
					  std::vector<Element *> *elements,
					  const int nbr)
{
	_size = 0.25;
	_x = x;
	_y = y;
	_Type = nbr;
	_Color.r = (nbr * 100) % 256;
	_Color.g = (nbr * 50) % 256;
	_Color.b = (nbr * 75) % 256;
	_Color.a = 255;
	_destructible = true;
	_life = 1;
	_max_life = 1;
	_nbr = nbr;
	_elements = elements;
}

float TeleportationPortal::getX () const
{
	return (_x);
}

float TeleportationPortal::getY () const
{
	return (_y);
}

char TeleportationPortal::getType () const
{
	return (_Type);
}

void TeleportationPortal::setLife (int life)
{
	_life = life;
}

void TeleportationPortal::teleportElement (const int index)
{
	int i = 0;

	while (i < (int) _elements->size()) {
		if (this != (*_elements)[i]) {
			if ((*_elements)[i]->getType() == _Type) {
				(*_elements)[index]->setPos(
					(*_elements)[i]->getX(),
					(*_elements)[i]->getY());
			}
		}
		i++;
	}
}

void TeleportationPortal::handleEvent (const Event &event)
{
	_size = 0.75 + 0.25 * cos((float) event.getTime() / 200);
	int i = 0;
	float x;
	float y;

	while (i < (int) _elements->size()) {
		if (this != (*_elements)[i]) {
			x = (*_elements)[i]->getX();
			y = (*_elements)[i]->getY();
			if (_x == x && _y == y) {
				teleportElement(i);
			}
		}
		i++;
	}
}

t_Color TeleportationPortal::getColor () const
{
	return (_Color);
}
