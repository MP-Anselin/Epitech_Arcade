/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#ifndef NIBBLER_HPP
# define NIBBLER_HPP

#include <SDL2/SDL.h>
#include <dlfcn.h>
#include <vector>
#include <fstream>
#include "../../common/include/Wall.hpp"
#include "../../common/include/Personage.hpp"
#include "../../../includes/Game.hpp"
#include "Snake.hpp"
#include "Empty.hpp"

#define WINNER -100
#define LOSER -200
#define LEVEL_MAX 5

class Nibbler : public Game
{
	public:
	Nibbler ();
	virtual void Init (int level);
	virtual ~Nibbler () = default;
	virtual int getLevel_max () const;
	virtual int getLevel () const;
	std::vector<Element *> getElements ();
	virtual void event (const Event &event);
	void loadMap (const std::string name, const std::string path);
	void element_push_back (std::string line, int y);
	void wall_push_back (const char c, const int x, const int y);
	void player_push_back (const char c, const int x, const int y);
	bool hasFood (const float x, const float y) const;
	void addfood(int nbr_food, int nbr_empty);
	void newFood(int new_pos, int *nbr_empty, int i);

	protected:
	std::vector <std::string> _map;
	float _Bomber_time;
	float _Millipede_time;
	float _Spider_time;
	int _nbr_kill;
	int _Level;
	std::vector<Empty *> _empty;
};

#endif /* !NIBBLER_HPP! */
