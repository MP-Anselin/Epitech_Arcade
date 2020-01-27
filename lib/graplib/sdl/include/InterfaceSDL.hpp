//
// EPITECH PROJECT, 2018
// Interface
// File description:
// Interface
//

#ifndef INTERFACESDL_HPP
# define INTERFACESDL_HPP

#include <SDL/SDL.h>
#include <dlfcn.h>
#include "../../../../includes/Interface.hpp"

class InterfaceSDL : public Interface
{
public:
	InterfaceSDL();
	virtual void Init();
	virtual void drawSquare(t_InfoElement infoElement);
	virtual void prepareScene(int x);
	virtual void getEvent(Event &event);
	virtual void endScene();
	virtual ~InterfaceSDL() = default;
	virtual void DeleteInterface();
	virtual void draw_menu(int var, float x, float y, t_Color Color);
	virtual void draw_menu_square();
	void select(float x, float y, float size, int r);
	void createWindow_games();
	void createWindow_menu();
	void getEnventmove(Event &myevent, SDL_Event event);
	void catch_letter(Event &myevent, SDL_Event event);

private:
	SDL_Surface *_ecran;
	SDL_Surface *_rectangle;
	SDL_Surface *_rec_menu;
	SDL_Rect _position;
	SDL_Rect _menu_position;
};

#endif
