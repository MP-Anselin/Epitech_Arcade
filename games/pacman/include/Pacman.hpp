//
// EPITECH PROJECT, 2018
// Interface
// File description:
// Interface
//

#ifndef PACMAN_HPP
# define PACMAN_HPP

#include <SDL2/SDL.h>
#include <dlfcn.h>
#include <vector>
#include <fstream>
#include "../../common/include/Wall.hpp"
#include "../../common/include/Personage.hpp"
#include "PersonagePacman.hpp"
#include "Enemy.hpp"
#include "Food.hpp"
#include "TeleportationPortal.hpp"
#include "Energy.hpp"
#include "../../../includes/Game.hpp"

#define WINNER -100
#define LOSER -200
#define LEVEL_MAX 1

class Pacman : public Game
{
public:
	Pacman();
	virtual void Init(int level);
	void loadMaps();
	void loadMap(const std::string name, const std::string path);
	void element_push_back(std::string line, int y);
	virtual int getLevel_max() const;
	virtual int getLevel() const;
	void winner();
	virtual ~Pacman() = default;
	std::vector <Element *> getElements();
	void event(const Event &event);
private:
	std::vector <std::string> _map;
	int _level;
};

#endif
