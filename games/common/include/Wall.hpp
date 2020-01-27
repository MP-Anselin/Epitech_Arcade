//
// EPITECH PROJECT, 2018
// Wall
// File description:
// Wall
//

#ifndef WALL_HPP_
# define WALL_HPP_

#include "ElementGame.hpp"

class Wall : public ElementGame
{
	public:
	Wall (const float x, const float y, const float size = 1);
	virtual char getType () const;
	virtual float getX () const;
	virtual float getY () const;
	virtual void setLife (int life);
	virtual void handleEvent (const Event &event);
	virtual t_Color getColor () const;
};

#endif
