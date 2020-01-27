/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#ifndef SHIP_HPP
# define SHIP_HPP

#include <vector>
#include "../../common/include/Personage.hpp"
#include "Missile.hpp"

class Ship : public Personage
{
	public:
	Ship (const float x, const float y,
	      std::vector<Element *> *elements, int game);
	~Ship ();
	virtual char getType () const;
	virtual float getX () const;
	virtual float getY () const;
	virtual void setLife (int life);
	virtual t_Color getColor () const;
	virtual void handleEvent (const Event &ptr);
	int check_one_missile ();

	protected:
	Event::Key _rl;
	Event::Key _ud;
	std::vector<Element *> *_elements;
};

#endif /* !SHIP_HPP! */
