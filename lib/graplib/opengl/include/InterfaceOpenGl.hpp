//
// EPITECH PROJECT, 2018
// Interface
// File description:
// Interface
//

#ifndef INTERFACEOPENGL_HPP
# define INTERFACEOPENGL_HPP

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "../../../../includes/Interface.hpp"

class InterfaceOpenGl : public Interface
{
	public:
	InterfaceOpenGl ();
	virtual void Init ();
	virtual void drawSquare (t_InfoElement infoElement);
	virtual void getEvent (Event &event);
	virtual void prepareScene (int x);
	virtual void endScene ();
	virtual void draw_menu_square ();
	virtual void draw_menu (int var, float x, float y, t_Color Color);
	virtual ~InterfaceOpenGl () = default;
	virtual void DeleteInterface ();
	void rod (int var);
	void createWindow_menu ();
	void createWindow_games ();
	void getEvent_letter (SDL_Event event, Event &myevent);
	void getEventmove (SDL_Event event, Event &myevent);
	void bottomSide (float x, float y, float size, t_Color Color);
	void leftSide (float x, float y, float size, t_Color Color);
	void topFace (float x, float y, float size, t_Color Color);
	void rightSide (float x, float y, float size, t_Color Color);
	void ontopFace (float x, float y, float size, t_Color Color);
	void underSide (float x, float y, float size, t_Color Color);
};

#endif
