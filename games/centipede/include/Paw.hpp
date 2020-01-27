//
// EPITECH PROJECT, 2018
// Wall
// File description:
// Wall
//

#ifndef PAW_HPP_
# define PAW_HPP_

#include "../../common/include/ElementGame.hpp"

class Paw : public ElementGame
{
	public:
	Paw (const float x, const float y, int length);
	virtual char getType () const;
	virtual float getX () const;
	virtual float getY () const;
	virtual void setLife (int life);
	virtual int getLength () const;
	virtual void handleEvent (const Event &event);
	virtual t_Color getColor () const;
};

#endif
