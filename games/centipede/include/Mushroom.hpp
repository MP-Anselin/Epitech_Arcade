/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include <vector>
#include <algorithm>
#include "../../common/include/ElementGame.hpp"
#include "../../../includes/Element.hpp"

#ifndef MUSHROOM_HPP_
#define MUSHROOM_HPP_

class Mushroom : public ElementGame
{
	public:
	Mushroom (const float x, const float y,
		  std::vector<Element *> *elements);
	~Mushroom ();
	virtual char getType () const;
	virtual float getX () const;
	virtual float getY () const;
	virtual void setLife (int life);
	virtual t_Color getColor () const;
	virtual void handleEvent (const Event &ptr);
	float collision_y (float x, float y);
	float collision_x (float x, float y);
	void destroy ();

	protected:
	int _Impact;
	std::vector<Element *> *_Elements;
};

#endif /* !MUSHROOM_HPP! */
