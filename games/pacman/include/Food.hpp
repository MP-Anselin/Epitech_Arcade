//
// EPITECH PROJECT, 2018
// Wall
// File description:
// Wall
//

#ifndef FOOD_HPP_
# define FOOD_HPP_

#include "../../common/include/ElementGame.hpp"

class Food : public ElementGame
{
public:
	Food(const float x, const float y);
	virtual char getType() const;
	virtual float getX() const;
	virtual float getY() const;
	virtual void setLife(int life);
	virtual void handleEvent(const Event &event);
	virtual t_Color getColor() const;
};

#endif
