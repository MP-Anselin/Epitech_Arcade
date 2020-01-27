/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#ifndef MILLIPEDE_HPP_
# define MILLIPEDE_HPP_

#include <vector>
#include <algorithm>
#include "Paw.hpp"
#include "../../common/include/Personage.hpp"
#include "Mushroom.hpp"

class Millipede : public Personage
{
	public:
	Millipede (const float x, const float y,
		   std::vector<Element *> *elements, int nbr);
	~Millipede ();
	virtual char getType () const;
	virtual float getX () const;
	virtual float getY () const;
	virtual void setLife (int life);
	virtual t_Color getColor () const;
	void follow (float y, float x);
	virtual void handleEvent (const Event &ptr);
	void push_back_paw (float x, float y, int length);
	void move ();
	void destroy ();
	int canUp ();
	int canDown ();
	int canLeft ();
	int canRight ();
	bool hasCollision (int el);

	protected:
	std::vector<Element *> *_elements;
	int _num;
	float _direc_x;
	int _seconds;
};

#endif /* !MILLIPEDE_HPP */
