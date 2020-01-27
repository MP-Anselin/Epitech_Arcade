//
// EPITECH PROJECT, 2018
// Interface
// File description:
// Interface
//

#include "InterfaceCaca.hpp"

InterfaceCaca::InterfaceCaca ()
{
}

void InterfaceCaca::cleanScreen ()
{
	unsigned int x = 0;
	unsigned int y = 0;

	caca_set_color_ansi(_Canvas, CACA_LIGHTGREEN, CACA_BLACK);
	while (y < _height) {
		x = 0;
		while (x < _width) {
			caca_put_str(_Canvas, x, y, " ");
			x++;
		}
		++y;
	}
}

void InterfaceCaca::Init ()
{
	if (_Canvas == NULL) {
		_Canvas = caca_create_canvas(150, 70);
		_Display = caca_create_display(_Canvas);
		if (_Display) {
			_Canvas = caca_get_canvas(_Display);
			caca_set_display_title(_Display, "ARCARDE");
			_width = caca_get_canvas_width(_Canvas);
			_height = caca_get_canvas_height(_Canvas);
		}
	}
}

void InterfaceCaca::createWindow_games ()
{
	createWindow_menu();
}


void InterfaceCaca::draw_menu_square ()
{
	unsigned int w = caca_get_canvas_width(_Canvas);
	unsigned int h = caca_get_canvas_height(_Canvas);
	caca_set_color_ansi(_Canvas, CACA_LIGHTGREEN, CACA_BLACK);
	caca_draw_box(_Canvas, 0, 0, w, h, ' ');
	caca_draw_box(_Canvas, 1, 1, w - 2, h - 2, ' ');
}

void InterfaceCaca::draw_menu (int var, float x, float y, t_Color Color)
{
	x += (_width / 4) + 7;
	y += (_height / 4);
	caca_draw_thin_line(_Canvas, x, y, x, y);
	if (var == 0)
		caca_draw_line(_Canvas, 50, 37, 93, 37, '_');
	else if (var == 1)
		caca_draw_line(_Canvas, 50, 45, 90, 45, '_');
	else if (var == 2)
		caca_draw_line(_Canvas, 53, 53, 88, 53, '_');
	(void) Color;
}


void InterfaceCaca::createWindow_menu ()
{
}

void InterfaceCaca::Color (t_Color Color, char type)
{
	caca_set_color_ansi(_Canvas, CACA_LIGHTGREEN, CACA_LIGHTRED);
	(void) Color;
	if (type == WALL)
		caca_set_color_ansi(_Canvas, CACA_CYAN, CACA_GREEN);
	else if (type == PERSONAGE || type == SHIP)
		caca_set_color_ansi(_Canvas, CACA_CYAN, CACA_LIGHTMAGENTA);
	else if (type == MISSILE)
		caca_set_color_ansi(_Canvas, CACA_CYAN, CACA_WHITE);
	else if (type == MILLIPEDE || type == ENEMY)
		caca_set_color_ansi(_Canvas, CACA_GREEN, CACA_RED);
	else if (type == FOOD)
		caca_set_color_ansi(_Canvas, CACA_LIGHTMAGENTA, CACA_DEFAULT);
	else if (type == MUSHROOM)
		caca_set_color_ansi(_Canvas, 0x05, CACA_BROWN);
	else if (type == BOMBER)
		caca_set_color_ansi(_Canvas, CACA_RED, CACA_YELLOW);
	else if (type == TAIL)
		caca_set_color_ansi(_Canvas, CACA_BROWN, CACA_LIGHTGRAY);
	else if (type == SPIDER)
		caca_set_color_ansi(_Canvas, CACA_BLUE, CACA_LIGHTCYAN);
	else
		caca_set_color_ansi(_Canvas, CACA_BLUE, CACA_CYAN);

}

void InterfaceCaca::drawSquare (t_InfoElement infoElement)
{
	infoElement.x += 50;
	infoElement.y += 20;
	if (infoElement.type) {
		Color(infoElement.Color, infoElement.type);
		if (infoElement.type == FOOD)
			caca_put_str(_Canvas, infoElement.x,
				     infoElement.y, "*");
		else
			caca_put_str(_Canvas, infoElement.x,
				     infoElement.y, " ");
	}
}

void InterfaceCaca::catch_letter (Event &myevent, int key)
{
	if (key == CACA_KEY_SPACE)
		myevent.setKey(Event::K_SPACE);
	else if (key == CACA_KEY_O)
		myevent.setKey(Event::K_o);
	else if (key == CACA_KEY_N)
		myevent.setKey(Event::K_n);
	else if (key == CACA_KEY_S)
		myevent.setKey(Event::K_s);
	else if (key == CACA_KEY_P)
		myevent.setKey(Event::K_p);
	else if (key == CACA_KEY_A)
		myevent.setKey(Event::K_a);
	else if (key == CACA_KEY_Z)
		myevent.setKey(Event::K_z);
	else if (key == CACA_KEY_M)
		myevent.setKey(Event::K_m);
	else if (key == CACA_KEY_C)
		myevent.setKey(Event::K_c);
	else if (key == CACA_KEY_E)
		myevent.setKey(Event::K_e);
	else
		myevent.setKey(Event::K_OTHER);
}

void InterfaceCaca::getEnventmove (Event &myevent, caca_event_t *event)
{
	int key = caca_get_event_key_ch(event);

	if (caca_get_event_type(event) == CACA_EVENT_KEY_PRESS)
		myevent.setType(Event::E_DOWN);
	else
		myevent.setType(Event::E_UP);
	if (key == CACA_KEY_LEFT)
		myevent.setKey(Event::K_LEFT);
	else if (key == CACA_KEY_RIGHT)
		myevent.setKey(Event::K_RIGHT);
	else if (key == CACA_KEY_UP)
		myevent.setKey(Event::K_UP);
	else if (key == CACA_KEY_DOWN)
		myevent.setKey(Event::K_DOWN);
	else if (key == CACA_KEY_RETURN) {
		myevent.setKey(Event::K_RETURN);
	}
	else
		catch_letter(myevent, key);
}

void InterfaceCaca::getEvent (Event &myevent)
{
	caca_event_t event;

	caca_get_event(_Display, CACA_EVENT_ANY, &event, 0);
	if (caca_get_event_type(&event) == CACA_EVENT_NONE)
		myevent.setType(Event::E_NOTHING);
	else if (caca_get_event_type(&event) == CACA_EVENT_QUIT)
		myevent.setType(Event::E_QUIT);
	else if (caca_get_event_type(&event) == CACA_EVENT_KEY_PRESS ||
		 caca_get_event_type(&event) == CACA_EVENT_KEY_RELEASE)
		getEnventmove(myevent, &event);
}

void InterfaceCaca::prepareScene (int x)
{
	(void) x;
	cleanScreen();
}

void InterfaceCaca::endScene ()
{
	caca_refresh_display(_Display);
}

void InterfaceCaca::DeleteInterface ()
{
}

extern "C" Interface *_create ()
{
	return new InterfaceCaca();
}

extern "C" void _destroy (Interface *p)
{
	delete p;
}