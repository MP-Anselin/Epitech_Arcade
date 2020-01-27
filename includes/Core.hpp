//
// EPITECH PROJECT, 2018
// Core
// File description:
// Core
//

#ifndef CORE_HPP_
# define CORE_HPP_

#include <unistd.h>
#include <dlfcn.h>
#include <map>
#include <string>
#include <iostream>
#include "Interface.hpp"
#include "Game.hpp"

#define PACMAN 0
#define CENTIPEDE 1
#define NIBBLER 2
#define NONE -1
#define WINNER -100
#define LOSER 0

class Core
{
	public:
	Core (std::string lib);
	t_InfoElement getInfoElement (std::vector<Element *> thing, int i);
	void select_game (int *play, int *var, Event event);
	void stop_game (std::vector<Element *> elements);
	void loadGameOver (const std::string path);
	void loadWinner (const std::string path);
	void loadMenu (const std::string path);
	void show_menu (int var);
	void setup_game (int play);
	void eventK_p (Event &event);
	void eventK_o (Event &event);
	void eventK_n (Event &event);
	void eventK_s (Event &event);
	void eventK_a (Event &event);
	void eventK_z (Event &event);
	void eventK_m (Event &event);
	void eventK_c (Event &event);
	void eventK_e (Event &event);
	void GameOver (int x, int y);
	void Winner (int x, int y);
	void display_game_over ();
	void display_winner ();
	void manwhile ();
	void levelUp ();
	void menu ();

	private:
	template<class TypeName>
	void loadLib (const std::string name,
		      const std::string path,
		      std::map <std::string, TypeName> &datas);
	void executeFrame (Event &event);
	std::map<std::string, Interface *> _interfaces;

	void executeFrame_next (std::vector<Element *> elements, int i,
				t_InfoElement infoElement);

	std::map<std::string, Game *> _games;
	Interface *_current_interface;
	Game *_current_game;
	std::map<Event::Key, void (Core::*) (Event &)> _fct;
	std::vector <std::string> _Menu;
	std::vector <std::string> _Winner;
	std::vector <std::string> _Game_over;
	int _Level;
	int _Acting;
	int _game_menu;
	bool _pause;
};

#endif
