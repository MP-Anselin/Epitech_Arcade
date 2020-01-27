/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include        "Nibbler.hpp"

Nibbler::Nibbler ()
{
	_Bomber_time = 0;
	_Millipede_time = 0;
	_Spider_time = 0;
	_nbr_kill = 0;
	_Level = 0;
}

void Nibbler::Init (int step)
{
	std::string level = "level";
	std::string path = "./games/nibbler/map/";
	std::string cha;
	std::string full_path;
	std::string full_level;

	_Level = 1;
	(void) step;
	cha = std::to_string(_Level);
	full_level = level + cha;
	full_path = path + full_level;
	loadMap(full_level, full_path);
}


int Nibbler::getLevel_max () const
{
	return (LEVEL_MAX);
}

int Nibbler::getLevel () const
{
	return (_Level);
}

void Nibbler::player_push_back (const char c, const int x, const int y)
{
	if (c == PERSONAGE) {
		_elements.push_back(
			new Snake((float) x, (float) y, &_elements, 1));
	}
}

void Nibbler::wall_push_back (const char c, const int x, const int y)
{
	if (c == '#') {
		_elements.push_back(new Wall((float) x, (float) y));
	}
}


void Nibbler::element_push_back (std::string line, int y)
{
	int x = 0;

	_map.push_back(line);
	while (x < (int) line.size()) {
		wall_push_back(line[x], x, y);
		player_push_back(line[x], x, y);
		if (line[x] == ' ') {
			Empty *tmp;
			tmp = new Empty((float) x, (float) y);
			_elements.push_back(tmp);
			_empty.push_back(tmp);
		}
		x++;
	}
}

void Nibbler::loadMap (const std::string name, const std::string path)
{
	if (name == "")
		return;
	std::ifstream file(path);
	std::string line;

	if (file) {
		for(int y = 0; std::getline(file, line); y++)
			element_push_back(line, y);
		file.close();
	}
	else
		std::cerr << "Can't open " << path << std::endl;
}

std::vector<Element *> Nibbler::getElements ()
{
	return (_elements);
}

bool Nibbler::hasFood (const float x, const float y) const
{
	int i = 0;

	while (i < (int) _elements.size()) {
		if (_elements[i]->getX() == x &&
		    _elements[i]->getY() == y)
			if (_elements[i]->getType() == FOOD)
				return (true);
		i++;
	}
	return (false);
}

void Nibbler::newFood(int new_pos, int *nbr_empty, int i)
{
	if (!hasFood(_elements[i]->getX(),
		     _elements[i]->getY())) {
		if (*nbr_empty == new_pos)
			_elements.push_back(new Food(_elements[i]->getX(),
					_elements[i]->getY()));
		(*nbr_empty)++;
	}
}

void Nibbler::addfood(int nbr_food, int nbr_empty)
{
	int new_pos;

	if (nbr_food < 5) {
		new_pos = rand() % nbr_empty;
		nbr_empty = 0;
		for (int i = 0; i < (int) _elements.size(); i++)
			if (_elements[i]->getType() == EMPTY)
				newFood(new_pos, &nbr_empty, i);
	}
}

void Nibbler::event (const Event &event)
{
	(void) event;
	int nbr_food = 0;
	int nbr_empty = 0;

	for (int i = 0; i < (int) _elements.size(); i++)
		if (_elements[i]->getLife() == 0)
			_elements.erase(_elements.begin() + i);
	for (int i = 0; i < (int) _elements.size(); i++)
		if (_elements[i]->getType() == FOOD)
			nbr_food++;
	for (int i = 0; i < (int) _elements.size(); i++) {
		if (_elements[i]->getType() == EMPTY)
			if (!hasFood(_elements[i]->getX(),
				     _elements[i]->getY()))
				nbr_empty++;
	}
	addfood(nbr_food, nbr_empty);
}

extern "C" Game *_create ()
{
	return new Nibbler();
}
