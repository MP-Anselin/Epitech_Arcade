//
// EPITECH PROJECT, 2018
// Interface
// File description:
// Interface
//

#include "InterfaceOpenGl.hpp"

InterfaceOpenGl::InterfaceOpenGl ()
{
}

void InterfaceOpenGl::Init ()
{
	SDL_Init(SDL_INIT_VIDEO);
	atexit(SDL_Quit);
}

void InterfaceOpenGl::createWindow_games ()
{
	createWindow_menu();
}

void InterfaceOpenGl::prepareScene (int x)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-x, 25, 25, -x, 15, 0, 0, 0, 1);
}

void InterfaceOpenGl::underSide (float x, float y, float size, t_Color Color)
{
	glColor4ub(Color.r, Color.g, Color.b - 75, Color.a);
	glVertex3d(size + x, size + y, -size);
	glVertex3d(size + x, -size + y, -size);
	glVertex3d(-size + x, -size + y, -size);
	glVertex3d(-size + x, size + y, -size);
}

void InterfaceOpenGl::ontopFace (float x, float y, float size, t_Color Color)
{
	glColor4ub(Color.r, Color.g, Color.b - 100, Color.a);
	glVertex3d(size + x, -size + y, size);
	glVertex3d(size + x, size + y, size);
	glVertex3d(-size + x, size + y, size);
	glVertex3d(-size + x, -size + y, size);
}

void InterfaceOpenGl::rightSide (float x, float y, float size, t_Color Color)
{
	glColor4ub(Color.r, Color.g, Color.b - 55, Color.a);
	glVertex3d(-size + x, size + y, size);
	glVertex3d(-size + x, size + y, -size);
	glVertex3d(-size + x, -size + y, -size);
	glVertex3d(-size + x, -size + y, size);
}

void InterfaceOpenGl::topFace (float x, float y, float size, t_Color Color)
{
	glColor4ub(Color.r, Color.g, Color.b - 20, Color.a);
	glVertex3d(-size + x, -size + y, size);
	glVertex3d(-size + x, -size + y, -size);
	glVertex3d(size + x, -size + y, -size);
	glVertex3d(size + x, -size + y, size);
}

void InterfaceOpenGl::leftSide (float x, float y, float size, t_Color Color)
{
	glColor4ub(Color.r, Color.g, Color.b - 5, Color.a);
	glVertex3d(size + x, -size + y, size);
	glVertex3d(size + x, -size + y, -size);
	glVertex3d(size + x, size + y, -size);
	glVertex3d(size + x, size + y, size);
}

void InterfaceOpenGl::bottomSide (float x, float y, float size, t_Color Color)
{
	glColor4ub(Color.r, Color.g, Color.b, Color.a);
	glVertex3d(size + x, size + y, size);
	glVertex3d(size + x, size + y, -size);
	glVertex3d(-size + x, size + y, -size);
	glVertex3d(-size + x, size + y, size);
}

void InterfaceOpenGl::drawSquare (t_InfoElement infoElement)
{
	float x = infoElement.x;
	float y = infoElement.y;
	t_Color Color = infoElement.Color;
	float size = infoElement.size;

	size = size / 2;
	x = -x;
	glBegin(GL_QUADS);
	bottomSide(x, y, size, Color);
	leftSide(x, y, size, Color);
	topFace(x, y, size, Color);
	rightSide(x, y, size, Color);
	ontopFace(x, y, size, Color);
	underSide(x, y, size, Color);
}

void InterfaceOpenGl::rod (int var)
{
	t_InfoElement infoElement;
	float save_x = 6;
	float save_y = 13.5;
	int lenght = 50;

	if (var == 1) {
		save_y = 21.5;
		save_x = 4.5;
	}
	else if (var == 2) {
		save_y = 29;
		save_x = 8.5;
		lenght = 44;
	}
	infoElement.Color.r = 255;
	infoElement.Color.g = 0;
	infoElement.Color.b = 0;
	infoElement.Color.a = 255;
	infoElement.size = 0.5;
	infoElement.y = save_y;
	infoElement.x = save_x;
	for (; save_x < lenght; save_x++) {
		infoElement.x = save_x;
		drawSquare(infoElement);
	}
}

void InterfaceOpenGl::draw_menu (int var, float x, float y, t_Color Color)
{
	t_InfoElement infoElement;

	infoElement.x = x;
	infoElement.y = y - 7;
	infoElement.size = 1;
	infoElement.Color = Color;
	drawSquare(infoElement);
	rod(var);
}

void InterfaceOpenGl::createWindow_menu ()
{
	SDL_WM_SetCaption("Opengl Acarde", NULL);
	SDL_SetVideoMode(900 * 2, 480 * 2, 32, SDL_OPENGL);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double) 800 / 480, 1, 1000);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void InterfaceOpenGl::draw_menu_square ()
{
}

void InterfaceOpenGl::getEvent_letter (SDL_Event event, Event &myevent)
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
	else if (event.key.keysym.sym == SDLK_c)
		myevent.setKey(Event::K_c);
	else if (event.key.keysym.sym == SDLK_e)
		myevent.setKey(Event::K_e);
	else
		myevent.setKey(Event::K_OTHER);
}

void InterfaceOpenGl::getEventmove (SDL_Event event, Event &myevent)
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
		getEvent_letter(event, myevent);
}

void InterfaceOpenGl::getEvent (Event &myevent)
{
	SDL_Event event;

	if (SDL_PollEvent(&event) == 0)
		myevent.setType(Event::E_NOTHING);
	else if (event.type == SDL_QUIT)
		myevent.setType(Event::E_QUIT);
	else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
		getEventmove(event, myevent);
	}
}

void InterfaceOpenGl::endScene ()
{
	glEnd();
	glFlush();
	SDL_GL_SwapBuffers();
}

void InterfaceOpenGl::DeleteInterface ()
{
}

extern "C" Interface *_create ()
{
	return new InterfaceOpenGl();
}

extern "C" void _destroy (Interface *p)
{
	delete p;
}
