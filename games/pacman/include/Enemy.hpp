/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include <vector>
#include <algorithm>
#include "../../common/include/ElementGame.hpp"

#ifndef ENEMY_HPP_
# define ENEMY_HPP_

class Enemy : public ElementGame
{
	enum Move
	{
		M_NOTHING,
		M_X,
		M_Y,
		M_LEFT,
		M_RIGHT,
		M_UP,
		M_DOWN
	};
public:
	Enemy(const float x, const float y, std::vector <Element *> *elements);
	~Enemy();
	virtual char getType() const;
	virtual float getX() const;
	virtual float getY() const;
	virtual t_Color getColor() const;
	virtual void setLife(int life);
	virtual void handleEvent(const Event &ptr);
	void savepath();
	void move(std::vector <Enemy::Move> moves);
	int canUp();
	int canDown();
	int canLeft();
	int canRight();
	Move _move;

protected:
	std::vector <Element *> *_elements;
	int _millisecond;
	float _speed;
	float _x1;
	float _x2;
	float _y1;
	float _y2;
};

#endif /* !MUSHROOM_HPP! */
