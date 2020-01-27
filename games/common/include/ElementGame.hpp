//
// EPITECH PROJECT, 2018
// ElementGame
// File description:
// ElementGame
//

#ifndef ELEMENTGAME_HPP_
#define ELEMENTGAME_HPP_

#include "../../../includes/Element.hpp"

class ElementGame : public Element
{
	public:
	virtual int getLength () const;
	virtual int getLife () const;
	virtual int getMaxLife () const;
	virtual bool isDestructible () const;
	virtual bool hasCollision (int el);
	virtual float getSize () const;
	virtual std::vector<Element *> getSubElements ();
	virtual void setPos (float x, float y);

	protected:
	bool _taken;
};


#endif
