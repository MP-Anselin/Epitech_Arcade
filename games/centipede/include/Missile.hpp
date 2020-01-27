/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#ifndef MISSILE_HPP
# define MISSILE_HPP

#include <vector>
#include <algorithm>
#include "../../common/include/ElementGame.hpp"
#include "../../../includes/Element.hpp"
#include "Mushroom.hpp"
#include "Millipede.hpp"

class Missile : public ElementGame
{
	public:
	Missile (const float x, const float y,
		 std::vector<Element *> *elements);
	~Missile ();
	virtual char getType () const;
	virtual float getX () const;
	virtual float getY () const;
	virtual void setLife (int life);
	virtual int getLength () const;
	virtual t_Color getColor () const;
	virtual void handleEvent (const Event &ptr);
	void collison ();
	void collisonSubElement (int i);
	float collision_y (float x, float y);
	void explosion (float collision);
	int kill_millipede (int el);

	protected:
	std::vector<Element *> *_Elements;
};

#endif /* !MISSILE_HPP! */
