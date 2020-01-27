//
// EPITECH PROJECT, 2018
// Interface
// File description:
// Interface
//

#include <iostream>

#ifndef GAME_HPP
# define GAME_HPP

#include <vector>
#include "Element.hpp"
#include "Event.hpp"

class Game
{
	public:
	Game () = default;
	virtual void Init (int level) = 0;
	virtual ~Game () = default;
	virtual int getLevel_max () const = 0;
	virtual int getLevel () const = 0;
	virtual std::vector<Element *> getElements () = 0;
	virtual void event (const Event &event) = 0;

	protected:
	std::vector<Element *> _elements;
};

#endif
