/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#include "Centipede.hpp"

Centipede::Centipede ()
{
	_Bomber_time = 0;
	_Millipede_time = 0;
	_Spider_time = 0;
	_nbr_kill = 0;
	_Level = 0;
}

void Centipede::setLevel (int level)
{
	_Level = level;
}

int Centipede::getLevel_max () const
{
	return (LEVEL_MAX);
}

int Centipede::getLevel () const
{
	return (_Level);
}

void Centipede::Init (int step)
{
	std::string level = "level";
	std::string path = "./games/centipede/map/";
	std::string cha;
	std::string full_path;
	std::string full_level;

	setLevel(_Level += step);
	cha = std::to_string(_Level);
	full_level = level + cha;
	full_path = path + full_level;
	loadMap(full_level, full_path);
}

void Centipede::Bomber_push_back (const int x, const int y)
{
	_elements.push_back(new Bomber((float) x, (float) y, &_elements));
}

void Centipede::mushroom_push_back (const char c, const int x, const int y)
{
	if (c == MUSHROOM) {
		_elements.push_back(
			new Mushroom((float) x, (float) y, &_elements));
	}
}

void Centipede::Spider_time_push_back (const int x, const int y)
{
	_elements.push_back(new Spider((float) x, (float) y, &_elements));
}

void Centipede::millipede_push_back (const int x, const int y, int nbr)
{
	_elements.push_back(
		new Millipede((float) x, (float) y, &_elements, nbr));
}

void Centipede::player_push_back (const char c, const int x, const int y)
{
	if (c == PERSONAGE) {
		_elements.push_back(
			new Ship((float) x, (float) y, &_elements, 1));
	}
}

void Centipede::wall_push_back (const char c, const int x, const int y)
{
	if (c == '|' || c == '_') {
		_elements.push_back(new Wall((float) x, (float) y));
	}
}

void Centipede::element_push_back (std::string line, int y)
{
	int x = 0;

	_map.push_back(line);
	while (x < (int) line.size()) {
		wall_push_back(line[x], x, y);
		player_push_back(line[x], x, y);
		mushroom_push_back(line[x], x, y);
		x++;
	}
}

void Centipede::loadMap (const std::string name, const std::string path)
{
	if (name == "")
		return;
	std::ifstream file(path);
	std::string line;
	int y = 0;

	if (file) {
		while (std::getline(file, line)) {
			element_push_back(line, y);
			y++;
		}
		file.close();
	}
	else {
		std::cerr << "Can't open " << path << std::endl;
	}
}

std::vector<Element *> Centipede::getElements ()
{
	return (_elements);
}

void Centipede::spider_time ()
{
	static int var = 1;
	float spid = 0;

	_Spider_time += 0.010;
	for (int i = 0; i < (int) _elements.size(); i++) {
		if (_elements[i]->getType() == SPIDER) {
			spid++;
		}
	}
	if (_Spider_time > 4 && spid < 1 + rand() % 2) {
		if (var == 1)
			Spider_time_push_back(1, 19 + rand() % 10);
		else
			Spider_time_push_back(38, 19 + rand() % 10);
		var = 1 + (rand() % 2);
		_Spider_time = 0;
	}
}

void Centipede::bomber_time ()
{
	float bomb = 0;

	_Bomber_time += 0.015;
	for (int i = 0; i < (int) _elements.size(); i++) {
		if (_elements[i]->getType() == BOMBER) {
			bomb++;
		}
	}
	if (_Bomber_time > 3 && bomb < 1 + rand() % 4) {
		Bomber_push_back(1 + rand() % 38, 1);
		_Bomber_time = 0;
	}
}

void Centipede::millipede_time ()
{
	int x = 0;
	int y = 0;
	float milli = 0;

	_Millipede_time += 0.02;
	for (int i = 0; i < (int) _elements.size(); i++) {
		if (_elements[i]->getType() == MILLIPEDE) {
			milli++;
			y = _elements[i]->getY();
		}
	}
	if ((_Millipede_time > 20 && milli < 1) ||
	    (_Millipede_time > 20 && y > 13)) {
		x = 3 + rand() % 34;
		millipede_push_back(x, 1, 12);
		if (!(_Millipede_time > 20 && milli < 1))
			_Millipede_time = 0;
	}
}

void Centipede::winner ()
{
	for (int i = 0; i < (int) _elements.size(); i++) {
		if (_elements[i]->getType() == SHIP) {
			_elements[i]->setLife(WINNER);
		}
	}
}

void Centipede::destroy_millipede (int i)
{
	float x = _elements[i]->getX();
	float y = _elements[i]->getY();
	int length = _elements[i]->getLength();

	_elements.erase(_elements.begin() + i);
	if (length <= 2) {
		_elements.push_back(new Mushroom(x, y, &_elements));
		_nbr_kill++;
		if (_nbr_kill == 20)
			winner();
	}
	else {
		if (x + 2 < 39)
			_elements.push_back(
				new Millipede(x + 2, y, &_elements,
					      length / 2));
		if (x - (length / 3) > 0)
			_elements.push_back(
				new Millipede(x - (length / 3), y, &_elements,
					      length / 2));
		else
			_elements.push_back(
				new Millipede(x, y - 1, &_elements,
					      length / 2));
	}
}

void Centipede::event (const Event &event)
{
	if (event.getType())
		return;
	for (int i = 0; i < (int) _elements.size(); i++) {
		if (_elements[i]->getLife() == 0) {
			if (_elements[i]->getType() == MILLIPEDE)
				destroy_millipede(i);
			else
				_elements.erase(_elements.begin() + i);
			i--;
		}
	}
	millipede_time();
	if (_Level > 1 && _Level != 3)
		bomber_time();
	if (_Level > 2)
		spider_time();
}

extern "C" Game *_create ()
{
	return new Centipede();
}
