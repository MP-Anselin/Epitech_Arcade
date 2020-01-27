/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include "Ship.hpp"

Ship::Ship (const float x, const float y,
	    std::vector<Element *> *elements, int game) :
	Personage(x, y, elements, game)
{
	_x = x;
	_y = y;
	_Type = SHIP;
	_size = 1;
	_elements = elements;
	_Color.r = 200;
	_Color.g = 0;
	_Color.b = 0;
	_Color.a = 255;
	_destructible = false;
}

float Ship::getX () const
{
	return (_x);
}

float Ship::getY () const
{
	return (_y);
}

char Ship::getType () const
{
	return (_Type);
}

t_Color Ship::getColor () const
{
	return (_Color);
}

void Ship::setLife (int life)
{
	_life = life;
}

int Ship::check_one_missile ()
{
	int nbr_ship = 0;
	int nbr_missile = 0;

	for (int i = 0; i < (int) (*_elements).size(); i++) {
		if ((*_elements)[i]->getType() == SHIP)
			nbr_ship++;
		if (this != (*_elements)[i]) {
			if ((*_elements)[i]->getType() == MISSILE)
				nbr_missile++;
		}
	}
	if (nbr_ship == nbr_missile)
		return 1;
	return 0;
}

void Ship::handleEvent (const Event &event)
{
	Personage::handleEvent(event);
	if (event.getType() == Event::E_DOWN) {
		if (check_one_missile() == 0 &&
		    event.getKey() == Event::K_SPACE) {
			(*_elements).push_back(new Missile(_x, _y - 1,
							   _elements));
		}
	}

}
