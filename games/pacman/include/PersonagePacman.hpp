/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#ifndef PERSONAGEPACMAN_HPP
# define PERSONAGEPACMAN_HPP

#include <vector>
#include "../../common/include/Personage.hpp"

class PersonagePacman : public Personage
{
public:
	~PersonagePacman();
	PersonagePacman(const float x, const float y,
			std::vector <Element *> *elements, int game);
	virtual char getType() const;
	virtual float getX() const;
	virtual float getY() const;
	void setLife(int life);
	virtual void handleEvent(const Event &event);
	virtual t_Color getColor() const;

protected:
	int _game;
	Event::Key _rl;
	Event::Key _ud;
	std::vector <Element *> *_elements;
};

#endif /* !PERSONAGEPACMAN_HPP! */
