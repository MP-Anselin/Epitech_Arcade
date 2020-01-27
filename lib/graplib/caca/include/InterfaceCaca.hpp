//
// EPITECH PROJECT, 2018
// Interface
// File description:
// Interface
//

#ifndef InterfaceCaca_HPP
# define InterfaceCaca_HPP

#include <stdlib.h>
#include <stdio.h>
#include <caca.h>
#include <inttypes.h>
#include "../../../../includes/Interface.hpp"


class InterfaceCaca : public Interface
{
	public:
	enum caca_key
	{
		CACA_KEY_UNKNOWN = 0x00,
		CACA_KEY_BACKSPACE = 0x08,
		CACA_KEY_TAB = 0x09,
		CACA_KEY_RETURN = 0x0d,
		CACA_KEY_ESCAPE = 0x1b,
		CACA_KEY_SPACE = 0x20,
		CACA_KEY_UP = 0x111,
		CACA_KEY_DOWN = 0x112,
		CACA_KEY_LEFT = 0x113,
		CACA_KEY_RIGHT = 0x114,
		CACA_KEY_A = 0x61,
		CACA_KEY_B = 0x62,
		CACA_KEY_C = 0x63,
		CACA_KEY_D = 0x64,
		CACA_KEY_E = 0x65,
		CACA_KEY_F = 0x66,
		CACA_KEY_G = 0x67,
		CACA_KEY_H = 0x68,
		CACA_KEY_I = 0x69,
		CACA_KEY_J = 0x6a,
		CACA_KEY_K = 0x6b,
		CACA_KEY_L = 0x6c,
		CACA_KEY_M = 0x6d,
		CACA_KEY_N = 0x6e,
		CACA_KEY_O = 0x6f,
		CACA_KEY_P = 0x70,
		CACA_KEY_Q = 0x71,
		CACA_KEY_R = 0x72,
		CACA_KEY_S = 0x73,
		CACA_KEY_T = 0x74,
		CACA_KEY_U = 0x75,
		CACA_KEY_V = 0x76,
		CACA_KEY_W = 0x77,
		CACA_KEY_X = 0x78,
		CACA_KEY_Y = 0x79,
		CACA_KEY_Z = 0x7a,
	};
	InterfaceCaca ();
	virtual void Init ();
	virtual void drawSquare (t_InfoElement infoElement);
	virtual void prepareScene (int x);
	virtual void getEvent (Event &event);
	virtual void endScene ();
	virtual ~InterfaceCaca () = default;
	virtual void DeleteInterface ();
	virtual void draw_menu (int var, float x, float y, t_Color Color);
	virtual void draw_menu_square ();
	void createWindow_games ();
	void createWindow_menu ();
	void getEnventmove (Event &myevent, caca_event_t *event);
	void catch_letter (Event &myevent, int key);
	void drawShit ();
	void cleanScreen ();
	void Color (t_Color Color, char type);

	private:
	caca_canvas_t *_Canvas;
	caca_display_t *_Display;
	unsigned int _width;
	unsigned int _height;
};

#endif
