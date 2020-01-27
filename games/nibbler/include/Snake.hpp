/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#ifndef SNAKE_HPP
# define SNAKE_HPP

#include <vector>
#include "../../common/include/Personage.hpp"
#include "Paw.hpp"
#include "Food.hpp"

class Snake : public Personage
{
	public:
	Snake (const float x, const float y,
	       std::vector<Element *> *elements, int game);
	~Snake ();
	virtual char getType () const;
	virtual float getX () const;
	virtual float getY () const;
	virtual void setLife (int life);
	virtual t_Color getColor () const;
	virtual void handleEvent (const Event &ptr);
	void collisions (const Event &ptr);
	void life_death(float x, float y);
	void move_paw(float x, float y);
	void move_coordinates();
	void managePaw(const Event &event);

	protected:
	Event::Key _current_key;
	Event::Key _last_key_down;
	int _last_move;
	bool _have_food;
	std::vector<Element *> *_elements;
	std::vector<Paw *> _paws;
};

#endif /* !SNAKE_HPP! */
