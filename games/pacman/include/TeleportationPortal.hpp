//
// EPITECH PROJECT, 2018
// Wall
// File description:
// Wall
//

#ifndef TELEPORTATIONPORTAL_HPP_
# define TELEPORTATIONPORTAL_HPP_

#include <cmath>
#include "../../common/include/ElementGame.hpp"

class TeleportationPortal : public ElementGame
{
public:
	TeleportationPortal(const float x, const float y,
			    std::vector <Element *> *, const int nbr);
	virtual char getType() const;
	virtual float getX() const;
	virtual float getY() const;
	virtual void setLife(int life);
	virtual void handleEvent(const Event &event);
	virtual t_Color getColor() const;
	void teleportElement(const int index);
private:
	int _nbr;
	std::vector <Element *> *_elements;
};

#endif
