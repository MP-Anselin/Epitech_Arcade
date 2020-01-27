//
// EPITECH PROJECT, 2018
// Interface
// File description:
// Interface
//

//#include <dlfcn.h>

#ifndef INTERFACE_HPP
# define INTERFACE_HPP

#include <vector>
#include <fstream>
#include "Element.hpp"
#include "Event.hpp"

class Interface
{
	public:
	Interface () = default;
	virtual void Init () = 0;
	virtual void createWindow_menu () = 0;
	virtual void createWindow_games () = 0;
	virtual void draw_menu (int var, float x, float y, t_Color Color) = 0;
	virtual void drawSquare (t_InfoElement infoElement) = 0;
	virtual void getEvent (Event &event) = 0;
	virtual void prepareScene (int x) = 0;
	virtual void draw_menu_square () = 0;
	virtual void endScene () = 0;
	virtual ~Interface () = default;
	virtual void DeleteInterface () = 0;
};

#endif
