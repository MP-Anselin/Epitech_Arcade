/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include <unistd.h>
#include "Millipede.hpp"

Millipede::Millipede(const float x, const float y,
		     std::vector <Element *> *elements, int length)
 : Personage(x, y, elements, 1)

{
	_x = x;
	_y = y;
	_Type = MILLIPEDE;
	_length = length;
	_size = 1;
	_elements = elements;
	_Color.r = 255;
	_Color.g = 0;
	_Color.b = 0;
	_direc_x = -1;
	_destructible = true;
	_Color.a = 255;
	_life = 1;
	_max_life = 1;
	_seconds = 0;
	_taken = false;
	push_back_paw(x, y, length);
}

void Millipede::push_back_paw(float x, float y, int length)
{
	int var = rand()%2;

	_direc_x = (var == 0) ? 1 : var;
	for (int i = 0; i < _length; i++)
		_sub_elements.push_back(new Paw(x - i, y, length));
}

Millipede::~Millipede()
{
}

float Millipede::getX() const
{
	return (_x);
}

float Millipede::getY() const
{
	return (_y);
}

char Millipede::getType() const
{
	return (_Type);
}

void Millipede::setLife(int life)
{
	_life = life;
}

t_Color Millipede::getColor() const
{
	return (_Color);
}

void Millipede::destroy()
{
	std::vector <Element *>::iterator it = std::find(
		(*_elements).begin(),
		(*_elements).end(),
		this);
	if((*_elements).end() != std::find(
		(*_elements).begin(),
		(*_elements).end(),
		this)){
		(*_elements).erase(it);
	}
}

void Millipede::follow(float y, float x)
{
	if (_x < x)
		_x += _direc_x;
	else if (_y < y)
		_y += 1;
}

int Millipede::canUp()
{
        int x;
        int y;

        for (int i = 0; i < (int)(*_elements).size(); i++){
                if ((*_elements)[i]->getType() != FOOD &&
		    (*_elements)[i]->getType() != SHIP){
                        x = (*_elements)[i]->getX();
			y = (*_elements)[i]->getY();
			if (_y - 1 == y && _x == x)
                                return (0);
                }
        }
        return (1);
}

int Millipede::canDown()
{
        int x;
        int y;

        for (int i = 0; i < (int)(*_elements).size(); i++){
                if ((*_elements)[i]->getType() != FOOD &&
		    (*_elements)[i]->getType() != SHIP){
                        x = (*_elements)[i]->getX();
                        y = (*_elements)[i]->getY();
                        if (_y + 1 == y && _x == x)
                                return (0);
                }
        }
        return (1);
}

int Millipede::canLeft()
{
        int x;
	int y;

        for (int i = 0; i < (int)(*_elements).size(); i++){
                if ((*_elements)[i]->getType() != FOOD &&
		    (*_elements)[i]->getType() != SHIP){
                        x = (*_elements)[i]->getX();
                        y = (*_elements)[i]->getY();
			if (_y == y && _x - 1 == x)
                                return (0);
                }
        }
        return (1);
}

int Millipede::canRight()
{
        int x;
        int y;

        for (int i = 0; i < (int)(*_elements).size(); i++){
                if ((*_elements)[i]->getType() != FOOD &&
		    (*_elements)[i]->getType() != SHIP){
                        x = (*_elements)[i]->getX();
			y = (*_elements)[i]->getY();
                        if (_y == y && _x + 1 == x)
                                return (0);
                }
        }
        return (1);
}


void Millipede::move()
{
	if (_direc_x < 0){
		if (canLeft()){
			_x+= _direc_x;
		}
		else {
			_y++;
			_direc_x = 1;
		}
	}
	else if (_direc_x > 0){
		if (canRight()){
			_x+= _direc_x;
		}
		else {
			_y++;
			_direc_x = -1;
		}
	}
}

bool Millipede::hasCollision(int el)
{
	if (el == -1)
                if (_destructible)
                        if (_life > 0){
				_life--;
                                _Color.a = 255.0 * (float)_life /
					(float)_max_life;
                                return (true);
                        }
	return (false);
}

void Millipede::handleEvent(const Event &event)
{
	float x = _x;
	float y = _y;
	float save_x = 0;
	float save_y = 0;

	if (_seconds == 0) {
		move();
		for (int i = 0;i < (int)_sub_elements.size();i++){
			save_x = _sub_elements[i]->getX();
			save_y = _sub_elements[i]->getY();
			_sub_elements[i]->setPos(x, y);
			x = save_x;
			y = save_y;
		}
	}
	_seconds += event.getDiff();
	if (_seconds > 150)
		_seconds = 0;
	if (_y > 28){
		_life = 0;
	}
}
