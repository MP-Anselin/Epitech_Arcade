/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#ifndef BOMBER_HPP
# define BOMBER_HPP

#include <vector>
#include "../../common/include/ElementGame.hpp"
#include "Mushroom.hpp"

class Bomber : public ElementGame
{
	public:
	Bomber (const float x, const float y,
		std::vector<Element *> *elements);
	~Bomber ();
	virtual char getType () const;
	virtual float getX () const;
	virtual float getY () const;
	virtual t_Color getColor () const;
	virtual void setLife (int life);
	virtual void handleEvent (const Event &ptr);
	float collision_y (float x, float y);
	void dropping (int is_ok);
	void destroy ();

	protected:
	int _Impact;
	int _seconds;
	std::vector<Element *> *_Elements;
};

#endif /* !BOMBER_HPP! */
