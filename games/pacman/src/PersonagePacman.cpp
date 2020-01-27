/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include "../include/PersonagePacman.hpp"

PersonagePacman::PersonagePacman (const float x, const float y,
				  std::vector<Element *> *elements, int game) :
	Personage(x, y, elements, game)
{
	_size = 1;
	_x = x;
	_y = y;
	_Type = 'p';
	_game = 0;
	_elements = elements;
	_Color.r = 0;
	_Color.g = 200;
	_Color.b = 0;
	_Color.a = 255;
	_taken = false;
}

char PersonagePacman::getType () const
{
	return (_Type);
}

float PersonagePacman::getX () const
{
	return (_x);
}

float PersonagePacman::getY () const
{
	return (_y);
}

void PersonagePacman::setLife (int life)
{
	_life = life;
}


t_Color PersonagePacman::getColor () const
{
	return (_Color);
}

void PersonagePacman::handleEvent (const Event &event)
{
	int a = 155 / 2;

	if (_invincible) {
		_Color.r = 100 + a + (int) ((float) a *
					    cos((float) event.getTime() /
						100.0));
		_Color.g = 0;
		_Color.b = 0;
	}
	else {
		_Color.r = 0;
		_Color.g = 200;
		_Color.b = 0;
		_Color.a = 255;
	}
	Personage::handleEvent(event);
}