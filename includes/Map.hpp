//
// EPITECH PROJECT, 2018
// Map
// File description:
// Map
//

#ifndef MAP_HPP_
# define MAP_HPP_

#include <vector>
#include "Element.hpp"

class Map
{
public:
	Map() = default;
private:
	std::vector <Element *> _elements;
};

#endif
