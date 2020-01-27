//
// EPITECH PROJECT, 2018
// Interface
// File description:
// Interface
//

#include "InterfaceSDL.hpp"

InterfaceSDL::InterfaceSDL ()
{
}

void InterfaceSDL::Init ()
{
	SDL_Init(SDL_INIT_VIDEO);
}

void InterfaceSDL::createWindow_games ()
{
	createWindow_menu();
}

void InterfaceSDL::select (float x, float y, float size, int r)
{
	int length = 25;
	int b = 0;

	if (r == -1) {
		b = 255;
		r = 0;
	}
	_rec_menu = SDL_CreateRGBSurface(SDL_HWSURFACE, length * size,
					 length * 1, 32, 0, 0, 0, 0);
	_menu_position.x = length * x + (length - length * 2) / 2;
	_menu_position.y = length * y + (length - length * 1) / 2;
	SDL_FillRect(_rec_menu, NULL, SDL_MapRGB(_ecran->format, r, 0, b));
	SDL_BlitSurface(_rec_menu, NULL, _ecran, &_menu_position);
	SDL_FreeSurface(_rec_menu);
}

void InterfaceSDL::draw_menu_square ()
{
	int y_menu = 38;

	for (int i = 0; i < y_menu; i++) {
		select(0, i, 1.5, -1);
		select(58, i, 1.5, -1);
	}
	for (int i = 0; i < 59; i++) {
		select(i, 0, 1.5, -1);
		select(i, y_menu, 1.5, -1);
	}
}

void InterfaceSDL::draw_menu (int var, float x, float y, t_Color Color)
{
	int length = 25;

	_rec_menu = SDL_CreateRGBSurface(SDL_HWSURFACE, length * 1, length * 1,
					 32, 0, 0, 0, 0);
	_menu_position.x = length * x + (length - length * 1) / 2;
	_menu_position.y = length * y + (length - length * 1) / 2;
	SDL_FillRect(_rec_menu, NULL,
		     SDL_MapRGB(_ecran->format, Color.r, Color.g, Color.b));
	SDL_BlitSurface(_rec_menu, NULL, _ecran, &_menu_position);
	SDL_FreeSurface(_rec_menu);
	if (var == 0)
		select(7, 20.5, 44, 255);
	else if (var == 1)
		select(5, 28.5, 46, 255);
	else if (var == 2)
		select(5, 36.5, 46, 255);
}


void InterfaceSDL::createWindow_menu ()
{
	_ecran = SDL_SetVideoMode(735 * 2, 485 * 2, 32, SDL_HWSURFACE);
	SDL_WM_SetCaption("Arcace !", NULL);
}

void InterfaceSDL::drawSquare (t_InfoElement infoElement)
{
	int length = 30;
	float x = infoElement.x;
	float y = infoElement.y;
	t_Color Color = infoElement.Color;
	float size = infoElement.size;

	_rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, length * size,
					  length * size, 32, 0, 0, 0, 0);
	_position.x = length * x + (length - length * size) / 2;
	_position.y = length * y + (length - length * size) / 2;
	Color.r = (char) ((float) Color.r * ((float) Color.a / (float) 255.0));
	Color.g = (char) ((float) Color.g * ((float) Color.a / (float) 255.0));
	Color.b = (char) ((float) Color.b * ((float) Color.a / (float) 255.0));
	SDL_FillRect(_rectangle, NULL,
		     SDL_MapRGB(_ecran->format, Color.r, Color.g, Color.b));
	SDL_BlitSurface(_rectangle, NULL, _ecran, &_position);
	SDL_FreeSurface(_rectangle);
}

void InterfaceSDL::catch_letter (Event &myevent, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_SPACE)
		myevent.setKey(Event::K_SPACE);
	else if (event.key.keysym.sym == SDLK_o)
		myevent.setKey(Event::K_o);
	else if (event.key.keysym.sym == SDLK_n)
		myevent.setKey(Event::K_n);
	else if (event.key.keysym.sym == SDLK_s)
		myevent.setKey(Event::K_s);
	else if (event.key.keysym.sym == SDLK_p)
		myevent.setKey(Event::K_p);
	else if (event.key.keysym.sym == SDLK_a)
		myevent.setKey(Event::K_a);
	else if (event.key.keysym.sym == SDLK_z)
		myevent.setKey(Event::K_z);
	else if (event.key.keysym.sym == SDLK_m)
		myevent.setKey(Event::K_m);
	else if (event.key.keysym.sym == SDLK_e)
		myevent.setKey(Event::K_e);
	else if (event.key.keysym.sym == SDLK_c)
		myevent.setKey(Event::K_c);
	else
		myevent.setKey(Event::K_OTHER);
}

void InterfaceSDL::getEnventmove (Event &myevent, SDL_Event event)
{
	if (event.type == SDL_KEYDOWN)
		myevent.setType(Event::E_DOWN);
	else
		myevent.setType(Event::E_UP);
	if (event.key.keysym.sym == SDLK_LEFT)
		myevent.setKey(Event::K_LEFT);
	else if (event.key.keysym.sym == SDLK_RIGHT)
		myevent.setKey(Event::K_RIGHT);
	else if (event.key.keysym.sym == SDLK_UP)
		myevent.setKey(Event::K_UP);
	else if (event.key.keysym.sym == SDLK_DOWN)
		myevent.setKey(Event::K_DOWN);
	else if (event.key.keysym.sym == SDLK_RETURN)
		myevent.setKey(Event::K_RETURN);
	else
		catch_letter(myevent, event);
}

void InterfaceSDL::getEvent (Event &myevent)
{
	SDL_Event event;

	if (SDL_PollEvent(&event) == 0)
		myevent.setType(Event::E_NOTHING);
	else if (event.type == SDL_QUIT)
		myevent.setType(Event::E_QUIT);
	else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
		getEnventmove(myevent, event);
	}
}

void InterfaceSDL::prepareScene (int x)
{
	(void) x;
	SDL_FillRect(_ecran, NULL, SDL_MapRGB(_ecran->format, 0, 0, 0));
}

void InterfaceSDL::endScene ()
{
	SDL_Flip(_ecran);
}

void InterfaceSDL::DeleteInterface ()
{

}

extern "C" Interface *_create ()
{
	return new InterfaceSDL();
}

extern "C" void _destroy (Interface *p)
{
	delete p;
}
