/*
** EPITECH PROJECT, 2018
** Documents
** File description:
** Created by MP,
*/

#ifndef Centipede_HPP
# define Centipede_HPP

#include <SDL2/SDL.h>
#include <dlfcn.h>
#include <vector>
#include <fstream>
#include "../../common/include/Wall.hpp"
#include "../../common/include/Personage.hpp"
#include "../../../includes/Game.hpp"
#include "Mushroom.hpp"
#include "Ship.hpp"
#include "Millipede.hpp"
#include "Bomber.hpp"
#include "Spider.hpp"

#define WINNER -100
#define LOSER -200
#define LEVEL_MAX 5

class Centipede : public Game
{
	public:
	Centipede ();
	virtual void Init (int level);
	void loadMaps ();
	void loadMap (const std::string name, const std::string path);
	void element_push_back (std::string line, int y);
	virtual ~Centipede () = default;
	std::vector<Element *> getElements ();
	virtual void event (const Event &event);
	void player_push_back (const char c, const int x, const int y);
	void wall_push_back (const char c, const int x, const int y);
	void mushroom_push_back (const char c, const int x, const int y);
	void Bomber_push_back (const int x, const int y);
	void millipede_push_back (const int x, const int y, int nbr);
	void Spider_time_push_back (const int x, const int y);
	void destroy_millipede (int i);
	virtual int getLevel_max () const;
	virtual int getLevel () const;
	void winner ();
	void setLevel (int more);
	void millipede_time ();
	void bomber_time ();
	void spider_time ();

	protected:
	std::vector <std::string> _map;
	float _Bomber_time;
	float _Millipede_time;
	float _Spider_time;
	int _nbr_kill;
	int _Level;
};

#endif /* !CENTIPEDE_HPP! */
