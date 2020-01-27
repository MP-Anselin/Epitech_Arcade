/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include "Snake.hpp"

Snake::Snake (const float x, const float y,
	      std::vector<Element *> *elements, int game) :
	Personage(x, y, elements, game)
{
	_x = x;
	_y = y;
	_speed = 3;
	_Type = SNAKE;
	_size = 1;
	_elements = elements;
	_Color.r = 200;
	_Color.g = 200;
	_Color.b = 0;
	_Color.a = 255;
	_game = 2;
	_destructible = false;
	_last_move = 0;
	_last_key_down = Event::K_LEFT;
	_current_key = Event::K_LEFT;
	_have_food = false;
	Paw *tmp;
	for (int i = 0; i < 4; i++) {
		tmp = new Paw(_x + 1 + i, _y, 1);
		_sub_elements.push_back(tmp);
		_paws.push_back(tmp);
	}
}

float Snake::getX () const
{
	return (_x);
}

float Snake::getY () const
{
	return (_y);
}

char Snake::getType () const
{
	return (_Type);
}

t_Color Snake::getColor () const
{
	return (_Color);
}

void Snake::setLife (int life)
{
	_life = life;
}

void Snake::life_death(float x, float y)
{
	for (int i = 0; i < (int) _sub_elements.size(); i++) {
		if (this != (_sub_elements)[i]) {
			x = (_sub_elements)[i]->getX();
			y = (_sub_elements)[i]->getY();
			if (_x == x && _y == y)
				_life = 0;
		}
	}
}

void Snake::collisions (const Event &event)
{
	(void) event;
	float x = 0;
	float y = 0;

	for(int i = 0; i < (int) _elements->size(); i++) {
		if (this != (*_elements)[i]) {
			x = (*_elements)[i]->getX();
			y = (*_elements)[i]->getY();
			if (_x == x && _y == y) {
				if ((*_elements)[i]->getType() == FOOD) {
					_have_food = true;
					(*_elements)[i]->hasCollision(-1);
				}
				else if ((*_elements)[i]->getType() != EMPTY)
					_life = 0;
			}
		}
	}
	life_death(x, y);
}

void Snake::move_paw(float x, float y)
{
	Paw *tmp = new Paw(x, y, 1);

	_sub_elements.push_back(tmp);
	_paws.push_back(tmp);
}

void Snake::move_coordinates()
{
	_y = (_last_key_down == Event::K_UP) ? _y - 1 : _y;
	_y = (_last_key_down == Event::K_DOWN) ? _y + 1 : _y;
	_x = (_last_key_down == Event::K_RIGHT) ? _x + 1 : _x;
	_x = (_last_key_down == Event::K_LEFT) ? _x - 1 : _x;
}

void Snake::managePaw(const Event &event)
{
	float x = _x;
	float y = _y;
	bool have_food = _have_food;
	float save_x = 0;
	float save_y = 0;
	bool save_have_food = 0;

	_current_key = _last_key_down;
	move_coordinates();
	_have_food = (_have_food) ? false : _have_food;
	for (int i = 0; i < (int) _paws.size(); i++) {
		save_x = _paws[i]->getX();
		save_y = _paws[i]->getY();
		save_have_food = _paws[i]->getHaveFood();
		_paws[i]->setPos(x, y);
		_paws[i]->setHaveFood(have_food);
		have_food = save_have_food;
		x = save_x;
		y = save_y;
	}
	if (save_have_food)
		move_paw(save_x, save_y);
	collisions(event);
	_last_move = 0;
}

void Snake::handleEvent (const Event &event)
{
	_last_move += event.getDiff();
	if (event.getType() == Event::E_DOWN) {
		_speed = (event.getKey() == Event::K_SPACE) ? 10 : _speed;
		if (event.getKey() == Event::K_UP &&
		    _current_key != Event::K_DOWN)
			_last_key_down = event.getKey();
		if (event.getKey() == Event::K_DOWN &&
		    _current_key != Event::K_UP)
			_last_key_down = event.getKey();
		if (event.getKey() == Event::K_LEFT &&
		    _current_key != Event::K_RIGHT)
			_last_key_down = event.getKey();
		if (event.getKey() == Event::K_RIGHT &&
		    _current_key != Event::K_LEFT)
			_last_key_down = event.getKey();
	}
	if (event.getType() == Event::E_UP)
		_speed = (event.getKey() == Event::K_SPACE) ? 3 : _speed;
	if (_last_move > 1000 / _speed)
		managePaw(event);
}
