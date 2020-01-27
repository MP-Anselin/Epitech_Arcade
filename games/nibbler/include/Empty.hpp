//
// EPITECH PROJECT, 2018
// Wall
// File description:
// Wall
//

#ifndef EMPTY_HPP_
# define EMPTY_HPP_

#include "../../common/include/ElementGame.hpp"

class Empty : public ElementGame
{
	public:
	Empty (const float x, const float y);
	virtual char getType () const;
	virtual float getX () const;
	virtual float getY () const;
	virtual void setLife (int life);
	virtual void handleEvent (const Event &event);
	virtual t_Color getColor () const;
};

#endif
