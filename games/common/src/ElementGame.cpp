//
// EPITECH PROJECT, 2018
// ElementGame
// File description:
// ElementGame
//

#include "../include/ElementGame.hpp"

int ElementGame::getLife () const
{
	return (_life);
}

int ElementGame::getMaxLife () const
{
	return (_max_life);
}

int ElementGame::getLength () const
{
	return (_length);
}

bool ElementGame::isDestructible () const
{
	return (_destructible);
}

bool ElementGame::hasCollision (int el)
{
	if (el == -1)
		if (_destructible)
			if (_life > 0) {
				_life--;
				_Color.a = 255.0 * (float) _life /
					   (float) _max_life;
				return (true);
			}
	return (false);
}

float ElementGame::getSize () const
{
	return (_size);
}

std::vector<Element *> ElementGame::getSubElements ()
{
	return (_sub_elements);
}

void ElementGame::setPos (float x, float y)
{
	_x = x;
	_y = y;
}
