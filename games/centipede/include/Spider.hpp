/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#ifndef SPIDER_HPP
# define SPIDER_HPP

#include <vector>
#include "../../common/include/ElementGame.hpp"
#include "Mushroom.hpp"

class Spider : public ElementGame
{
	public:
	Spider (const float x, const float y,
		std::vector<Element *> *elements);
	~Spider ();
	virtual char getType () const;
	virtual float getX () const;
	virtual float getY () const;
	virtual void setLife (int life);
	virtual t_Color getColor () const;
	virtual void handleEvent (const Event &ptr);
	float collision_y (float x, float y);
	void destroy ();
	void dropping ();
	void move ();

	protected:
	std::vector<Element *> *_Elements;
	int _direc_x;
	int _direc_y;
	int _seconds;
};

#endif /* !SPIDER_HPP! */
