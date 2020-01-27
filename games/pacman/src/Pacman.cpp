//
// EPITECH PROJECT, 2018
// Interface
// File description:
// Interface
//

#include "Pacman.hpp"

Pacman::Pacman ()
{
	_level = 0;
}

void Pacman::Init (int level)
{
	(void) level;
	loadMap("level1", "./games/pacman/map/level1");
}

void Pacman::loadMaps ()
{
}

int Pacman::getLevel_max () const
{
	return (LEVEL_MAX);
}

int Pacman::getLevel () const
{
	return (1);
}

void Pacman::element_push_back (std::string line, int y)
{
	_map.push_back(line);
	for (int x = 0; x < (int) line.size(); x++) {
		if (line[x] == '#') {
			_elements.push_back(new Wall((float) x, (float) y));
		}
		else if (line[x] == '*') {
			_elements.push_back(
				new Wall((float) x, (float) y, 0.01));
		}
		else if (line[x] == 'o')
			_elements.push_back(new PersonagePacman(
				(float) x, (float) y, &_elements, 0));
		else if (line[x] == 'm') {
			_elements.push_back(
				new Enemy((float) x, (float) y, &_elements));
		}
		else if (line[x] == 'f' || line[x] == ' ')
			_elements.push_back(new Food((float) x, (float) y));
		else if (line[x] == 'e')
			_elements.push_back(new Energy((float) x, (float) y));
		else if ('0' <= line[x] && line[x] <= '9') {
			TeleportationPortal *portal = new TeleportationPortal(
				(float) x, (float) y, &_elements,
				line[x] - '0');
			_elements.push_back(portal);
		}
	}
}

void Pacman::loadMap (const std::string name, const std::string path)
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

std::vector<Element *> Pacman::getElements ()
{
	return (_elements);
}

void Pacman::winner ()
{
	for (int i = 0; i < (int) _elements.size(); i++) {
		if (_elements[i]->getType() == 'p') {
			_elements[i]->setLife(WINNER);
		}
	}
}

void Pacman::event (const Event &event)
{
	int end_game = 1;

	for (int i = 0; i < (int) _elements.size(); i++) {
		if (_elements[i]->getLife() == 0) {
			_elements.erase(_elements.begin() + i);
			i--;
		}
	}
	for (int i = 0; i < (int) _elements.size(); i++) {
		if (_elements[i]->getType() == 'f')
			end_game = 0;
	}
	if (end_game) {
		std::cout << "hello" << std::endl;
		winner();
	}
	if (event.getType())
		return;
}

extern "C" Game *_create ()
{
	return new Pacman();
}

extern "C" void _destroy (Game *p)
{
	delete p;
}
