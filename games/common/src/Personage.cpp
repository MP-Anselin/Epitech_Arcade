/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include "../include/Personage.hpp"

Personage::Personage (const float x, const float y,
		      std::vector<Element *> *elements, int game)
{
	_x = x;
	_y = y;
	_speed = 10;
	_elements = elements;
	_game = game;
	_life = 1;
	_max_life = 1;
	_destructible = false;
	_invincible = false;
	_Type = PERSONAGE;
	_l_k = Event::K_NOTHING;
}

Personage::~Personage ()
{
}

void Personage::setLife (int life)
{
	_life = life;
}

float Personage::getX () const
{
	return (_x);
}

float Personage::getY () const
{
	return (_y);
}

char Personage::getType () const
{
	return (_Type);
}

float Personage::collision_y (float x, float y)
{
	if ((x <= _x && _x < x + 1) ||
	    (x < _x + 1 && _x + 1 <= x + 1)) {
		if (y <= _y && _y < y + 1)
			return (1);
		if (y < _y + 1 && _y + 1 <= y + 1)
			return (-1);
	}
	return (0.0);
}

float Personage::collision_x (float x, float y)
{
	if ((y <= _y && _y < y + 1) ||
	    (y < _y + 1 && _y + 1 <= y + 1)) {
		if (x <= _x && _x < x + 1)
			return (1);
		if (x < _x + 1 && _x + 1 <= x + 1 && (_x - 1 > 0))
			return (-1);
	}
	return (0.0);
}

void Personage::collision_move_x(char type, float x, float colx)
{
	if (type != MILLIPEDE && type != FOOD &&
	    type != ENERGY
	    && !(0 <= type && type <= 9)) {
		if (_l_k != Event::K_RIGHT &&
		    _l_k != Event::K_LEFT)
			_rl = Event::K_NOTHING;
		_x = x + colx;
	}
}

int Personage::Xcollison(char type, int i, float x, float colx)
{
	if (colx) {
		if (_invincible && type == ENEMY) {
			_elements->erase(_elements->begin() + i);
			return (1);
		}
		if (type == ENEMY || type == MILLIPEDE ||
		    type == BOMBER || type == SPIDER) {
			(*_elements)[i]->setLife(LOSER);
			return (1);
		}
		if (type == FOOD)
			(*_elements)[i]->hasCollision(-1);
		_invincible = (type == ENERGY) ? true : _invincible;
		collision_move_x(type, x, colx);
	}
	return (0);
}

void Personage::collision_move_y(char type, float y, float coly)
{
	if (type != MILLIPEDE && type != FOOD && type != ENERGY
	    && !(0 <= type && type <= 9)) {
		_y = y + coly;
		if (_l_k != Event::K_UP &&
		    _l_k != Event::K_DOWN)
			_ud = Event::K_NOTHING;
	}
}

int Personage::Ycollison(char type, int i, float y, float coly)
{
	if (coly) {
		if (_invincible && type == ENEMY) {
			_elements->erase(_elements->begin() + i);
			return (1);
		}
		if (type == ENEMY || type == MILLIPEDE ||
		    type == BOMBER || type == SPIDER) {
			_life = 0;
			return (1);
		}
		if (type == FOOD)
			(*_elements)[i]->hasCollision(-1);
		_invincible = (type == ENERGY) ? true : _invincible;
		collision_move_y(type, y, coly);
	}
	return (0);
}

void Personage::collision (int var)
{
	float x;
	float y = (float) var;
	float coly = 0;
	float colx = 0;
	char type;

	for (int i = 0; i < (int) (*_elements).size(); i++) {
		if (this != (*_elements)[i]) {
			x = (*_elements)[i]->getX();
			y = (*_elements)[i]->getY();
			type = (*_elements)[i]->getType();
			coly = var != 0 ? collision_y(x, y) : 0;
			colx = var != 1 ? collision_x(x, y) : 0;
			if (Ycollison(type, i, y, coly) == 1)
				return;
			if (Xcollison(type, i, x, colx) == 1)
				return;
		}
	}
}

void Personage::do_action_ud (float x, float y, float length)
{
	if (_ud == Event::K_UP)
		y = y - length;
	else if (_ud == Event::K_DOWN)
		y = y + length;
	_x = x;
	_y = y;
}

void Personage::Coordinates(float *x, float *y, const Event event)
{
	float seconds = (float) event.getDiff() / 1000.0;
	float length = _speed * seconds;

	if (_rl == Event::K_RIGHT)
		*x = *x + length;
	if (_rl == Event::K_LEFT)
		*x = *x - length;
	if (_ud == Event::K_UP)
		*y = *y - length;
	if (_ud == Event::K_DOWN)
		*y = *y + length;
}

void Personage::do_action (const Event &event)
{
	float x = _x;
	float y = _y;

	Coordinates(&x, &y, event);
	if ((int) _x != (int) x) {
		if (x > _x)
			x = (float) ((int) x);
		else if ((float) (int) _x != _x)
			x = (float) (((int) x) + 1);
	}
	if ((int) _y != (int) y) {
		if (y > _y)
			y = (float) ((int) y);
		else if ((float) (int) _y != _y)
			y = (float) (((int) y) + 1);
	}
	if (_game == 1 && y < 23) {
		y = 23;
	}
	_x = x;
	collision(0);
	_y = y;
	collision(1);
}

void Personage::catch_action_ud (const Event &event)
{
	if (event.getKey() == Event::K_UP)
		_l_k = _ud = Event::K_UP;
	else if (event.getKey() == Event::K_DOWN)
		_l_k = _ud = Event::K_DOWN;
}

void Personage::catch_action (const Event &event)
{
	if (event.getType() == Event::E_DOWN) {
		_taken = false;
		if (event.getKey() == Event::K_RIGHT)
			_l_k = _rl = Event::K_RIGHT;
		else if (event.getKey() == Event::K_LEFT)
			_l_k = _rl = Event::K_LEFT;
		else
			catch_action_ud(event);
	}
}

void Personage::handleEvent (const Event &event)
{
	if (_game != 0 && event.getType() == Event::E_UP) {
		if (event.getKey() == _rl)
			_l_k = _rl = Event::K_NOTHING;
		if (event.getKey() == _ud)
			_l_k = _ud = Event::K_NOTHING;
	}
	catch_action(event);
	do_action(event);
	if (_invincible) {
		_start_invincible += event.getDiff();
		if (_start_invincible > 10000) {
			_start_invincible = 0;
			_invincible = false;
		}
	}
}

std::vector<Element *> Personage::getSubElements ()
{
	return (_sub_elements);
}

void Personage::setPos (float x, float y)
{
	if (_taken == false) {
		_x = x;
		_y = y;
		_taken = true;
	}

}
