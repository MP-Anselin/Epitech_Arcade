/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include "../include/Enemy.hpp"

Enemy::Enemy (const float x, const float y, std::vector<Element *> *elements)
{
	_size = 1.0;
	_x = x;
	_y = y;
	_x1 = x;
	_y1 = y;
	_x2 = x;
	_y2 = y;
	_Type = 'e';
	_Color.r = 150;
	_Color.g = 125;
	_Color.b = 120;
	_Color.a = 255;
	_elements = elements;
	_destructible = true;
	_life = 3;
	_max_life = 3;
	_millisecond = 0;
	_speed = 2 + rand() % 3;
}

Enemy::~Enemy ()
{
}

float Enemy::getX () const
{
	return (_x);
}

float Enemy::getY () const
{
	return (_y);
}

char Enemy::getType () const
{
	return (_Type);
}

void Enemy::setLife (int life)
{
	_life = life;
}

t_Color Enemy::getColor () const
{
	return (_Color);
}

int Enemy::canUp ()
{
	int x;
	int y;

	for (int i = 0; i < (int) (*_elements).size(); i++) {
		if ((*_elements)[i]->getType() != 'f' &&
		    (*_elements)[i]->getType() != 'p' &&
		    (*_elements)[i]->getType() != 'E' &&
		    (*_elements)[i]->getType() != 'e') {
			x = (*_elements)[i]->getX();
			y = (*_elements)[i]->getY();
			if (_y - 1 == y && _x == x)
				return (0);
		}
	}
	return (1);
}

int Enemy::canDown ()
{
	int x;
	int y;

	for (int i = 0; i < (int) (*_elements).size(); i++) {
		if ((*_elements)[i]->getType() != 'f' &&
		    (*_elements)[i]->getType() != 'p' &&
		    (*_elements)[i]->getType() != 'E' &&
		    (*_elements)[i]->getType() != 'e') {
			x = (*_elements)[i]->getX();
			y = (*_elements)[i]->getY();
			if (_y + 1 == y && _x == x)
				return (0);
		}
	}
	return (1);
}

int Enemy::canLeft ()
{
	int x;
	int y;

	for (int i = 0; i < (int) (*_elements).size(); i++) {
		if ((*_elements)[i]->getType() != 'f' &&
		    (*_elements)[i]->getType() != 'p' &&
		    (*_elements)[i]->getType() != 'E' &&
		    (*_elements)[i]->getType() != 'e') {
			x = (*_elements)[i]->getX();
			y = (*_elements)[i]->getY();
			if (_y == y && _x - 1 == x)
				return (0);
		}
	}
	return (1);
}

int Enemy::canRight ()
{
	int x;
	int y;

	for (int i = 0; i < (int) (*_elements).size(); i++) {
		if ((*_elements)[i]->getType() != 'f' &&
		    (*_elements)[i]->getType() != 'p' &&
		    (*_elements)[i]->getType() != 'E' &&
		    (*_elements)[i]->getType() != 'e') {
			x = (*_elements)[i]->getX();
			y = (*_elements)[i]->getY();
			if (_y == y && _x + 1 == x)
				return (0);
		}
	}
	return (1);
}

void Enemy::move (std::vector <Enemy::Move> moves)
{
	float x = _x;
	float y = _y;
	float length = 1;
	if ((int) moves.size() == 0)
		return;
	Move move = moves[rand() % (int) moves.size()];

	if (move == M_UP) {
		y -= length;
	}
	else if (move == M_DOWN) {
		y += length;
	}
	else if (move == M_LEFT) {
		x -= length;
	}
	else if (move == M_RIGHT) {
		x += length;
	}
	_x2 = x;
	_y2 = y;
	_move = move;
}

void Enemy::savepath ()
{
	std::vector <Enemy::Move> moves;

	if (canUp() && _move != M_DOWN)
		moves.push_back(M_UP);
	if (canDown() && _move != M_UP)
		moves.push_back(M_DOWN);
	if (canLeft() && _move != M_RIGHT)
		moves.push_back(M_LEFT);
	if (canRight() && _move != M_LEFT)
		moves.push_back(M_RIGHT);
	if ((int) moves.size() == 0) {
		if (canUp())
			moves.push_back(M_UP);
		if (canDown())
			moves.push_back(M_DOWN);
		if (canLeft())
			moves.push_back(M_LEFT);
		if (canRight())
			moves.push_back(M_RIGHT);
	}
	move(moves);
}

void Enemy::handleEvent (const Event &event)
{
	(void) event;
	_millisecond += event.getDiff();
	if (_millisecond < 1000 / _speed) {
		_x = _x1 + (_x2 - _x1) *
			   ((float) _millisecond / (1000 / _speed));
		_y = _y1 + (_y2 - _y1) *
			   ((float) _millisecond / (1000 / _speed));
		return;
	}
	_x = _x2;
	_y = _y2;
	_x1 = _x;
	_y1 = _y;
	_millisecond = 0;
	savepath();
}