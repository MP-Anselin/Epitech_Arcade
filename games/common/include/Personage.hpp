/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#ifndef PERSONAGE_HPP
# define PERSONAGE_HPP

#include <cmath>
#include <vector>
#include "ElementGame.hpp"
#include "../../../includes/Element.hpp"

#define WINNER -100
#define LOSER -200

class Personage : public ElementGame
{
	public:
	Personage (const float x, const float y,
		   std::vector<Element *> *elements, int game);
	~Personage ();
	virtual void handleEvent (const Event &event);
	virtual float getX () const;
	virtual float getY () const;
	virtual char getType () const;
	virtual void setLife (int life);
	virtual void setPos (float x, float y);
	virtual std::vector<Element *> getSubElements ();
	void move (const Event &event);
	void collision (int type);
	void do_action (const Event &event);
	void catch_action (const Event &event);
	void catch_action_ud (const Event &event);
	void do_action_ud (float x, float y, float length);
	float collision_y (float x, float y);
	float collision_x (float x, float y);
	void Coordinates(float *x, float *y, const Event event);
	int Ycollison(char type, int i, float y, float coly);
	int Xcollison(char type, int i, float x, float colx);
	void collision_move_x(char type, float x, float colx);
	void collision_move_y(char type, float y, float coly);

	protected:
	int _game;
	float _speed;
	Event::Key _rl;
	Event::Key _ud;
	Event::Key _l_k;
	std::vector<Element *> *_elements;
	bool _invincible;
	int _start_invincible;
};

#endif /* !PERSONAGE_HPP! */
