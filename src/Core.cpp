//
// EPITECH PROJECT, 2018
// Core
// File description:
// Core
//

#include "../includes/Core.hpp"

Core::Core(std::string lib)
{
	loadLib("openGl", "lib/graplib/opengl/lib_arcade_opengl.so",
		_interfaces);
	loadLib("SDL", "lib/graplib/sdl/lib_arcade_sdl.so", _interfaces);
	loadLib("Caca", "lib/graplib/caca/lib_arcade_libcaca.so", _interfaces);
	loadMenu("./lib/graplib/files/menu");
	loadWinner("./lib/graplib/files/winner");
	loadGameOver("./lib/graplib/files/game_over");

	_current_interface = _interfaces[lib];
	_pause = false;
	_Acting = NONE;
	_Level = 4;
	_current_interface->Init();
	_current_interface->createWindow_menu();
	_fct[Event::K_p] = &Core::eventK_p;
	_fct[Event::K_o] = &Core::eventK_o;
	_fct[Event::K_n] = &Core::eventK_n;
	_fct[Event::K_s] = &Core::eventK_s;
	_fct[Event::K_a] = &Core::eventK_a;
	_fct[Event::K_z] = &Core::eventK_z;
	_fct[Event::K_m] = &Core::eventK_m;
	_fct[Event::K_c] = &Core::eventK_c;
	_fct[Event::K_e] = &Core::eventK_e;
	menu();
}

void Core::select_game(int *play, int *var, Event event)
{
	if (event.getType() == Event::E_DOWN){
		if (event.getKey() == Event::K_UP)
			*var = *var > 0 ? *var - 1 : *var;
		else if (event.getKey() == Event::K_DOWN)
			*var = *var < 2 ? *var + 1 : *var;
	}
	if (event.getKey() == Event::K_RETURN && *var == CENTIPEDE) {
		*play = CENTIPEDE;
	}
	else if (event.getKey() == Event::K_RETURN && *var == PACMAN)
		*play = PACMAN;
	else if (event.getKey() == Event::K_RETURN && *var == NIBBLER)
		*play = NIBBLER;
}

void Core::menu()
{
	Event event;
	int var = 0;

	_Acting = NONE;
	while (_Acting == NONE)
	{
		_current_interface->getEvent(event);
		if (event.getType() == Event::E_QUIT)
			exit(0);
		if (event.getType() == Event::E_DOWN){
			if (this->_fct.find(event.getKey()) != _fct.end())
				(this->*_fct[event.getKey()])(event);
		}
		select_game(&_Acting, &var, event);
		_current_interface->prepareScene(25);
		show_menu(var);
		_current_interface->endScene();
		usleep(15);
		event.updateTime();
	}
	setup_game(_Acting);
}

void Core::show_menu(int var)
{
	t_Color Color;

	Color.r = 0;
	Color.g = 255;
	Color.b = 0;
	Color.a = 255;
	for (int y = 0; y < (int)_Menu.size(); y++) {
		for (int x = 0; x < (int)_Menu[y].size(); x++) {
			if (y < 10)
				Color.b = 150;
			else if (y > 10 && y < 17)
				Color.b = 255;
			else if (y > 17)
				Color.r = 250;
			if (_Menu[y][x] != ' ')
				_current_interface->draw_menu(var, x, y, Color);
		}
	}
	_current_interface->draw_menu_square();
}

void Core::setup_game(int play)
{
	if (play == PACMAN) {
		loadLib("Pacman", "games/lib_arcade_pacman.so", _games);
		_games["Pacman"]->Init(_Level);
		_current_game = _games["Pacman"];
	}
	else if (play == CENTIPEDE) {
		loadLib("Centipede", "games/lib_arcade_centipede.so", _games);
		_games["Centipede"]->Init(_Level);
		_current_game = _games["Centipede"];
	}
	else if (play == NIBBLER) {
		loadLib("Nibbler", "games/lib_arcade_nibbler.so", _games);
		_games["Nibbler"]->Init(_Level);
		_current_game = _games["Nibbler"];
	}
	_current_interface->Init();
	_current_interface->createWindow_games();
	manwhile();
}

void Core::manwhile()
{
	Event event;

	while (1) {
		_current_interface->getEvent(event);
		if (event.getType() == Event::E_QUIT)
			exit(0);
		if (event.getType() == Event::E_DOWN){
			if (this->_fct.find(event.getKey()) != _fct.end())
				(this->*_fct[event.getKey()])(event);
		}
		if (_pause != true){
			executeFrame(event);
		}
	}
	menu();
}

void Core::Winner(int x, int y)
{
	t_InfoElement infoElement;
	int rd;

	infoElement.Color.r = 0;
	infoElement.Color.g = 255;
	infoElement.Color.b = 0;
	infoElement.Color.a = 255;
	if (y > 25){
		rd = rand()%2;
		if (rd == 0)
			y += 1;
		else
			y -= 1;
	}
	infoElement.x = x;
	infoElement.y = y;
	infoElement.size = 1;
	_current_interface->drawSquare(infoElement);
}

void Core::display_winner()
{
	float time = 0;
	Event event;

	_current_interface->endScene();
	while (time < 15) {
		_current_interface->getEvent(event);
		if (event.getType() == Event::E_QUIT)
			exit(0);
		else if (time > 3 && event.getType() != Event::E_NOTHING)
			time = 21;
		_current_interface->prepareScene(25);
		for (int y = 0; y < (int) _Winner.size(); y++) {
			for (int x = 0; x < (int) _Winner[y].size(); x++) {
				if (_Winner[y][x] != ' ')
					Winner(x, y);
			}
		}
		_current_interface->endScene();
		time += 0.01;
	}
	menu();
}

void Core::GameOver(int x, int y)
{
	t_InfoElement infoElement;
	int rd;

	infoElement.Color.r = 255;
	infoElement.Color.g = 0;
	infoElement.Color.b = 0;
	infoElement.Color.a = 255;
	if (y > 25){
		rd = rand()%2;
		if (rd == 0)
			y += 1;
		else
			y -= 1;
	}
	infoElement.x = x;
	infoElement.y = y;
	infoElement.size = 1;
	_current_interface->drawSquare(infoElement);
}

void Core::display_game_over()
{
	float time = 0;
	Event event;

	_current_interface->endScene();
	while (time < 15) {
		_current_interface->getEvent(event);
		if (event.getType() == Event::E_QUIT)
			exit(0);
		else if (time > 3 && event.getType() != Event::E_NOTHING)
			time = 21;
		_current_interface->prepareScene(25);
		for (int y = 0; y < (int) _Game_over.size(); y++) {
			for (int x = 0; x < (int) _Game_over[y].size(); x++) {
				if (_Game_over[y][x] != ' ')
					GameOver(x, y);
			}
		}
		_current_interface->endScene();
	time += 0.01;
	}
	menu();
}

void Core::levelUp()
{
	int level_max = 0;

	_Level = _current_game->getLevel();
	level_max = _current_game->getLevel_max();
	if (_Level < level_max) {
		_Level += 1;
		setup_game(_Acting);
	}
	else {
		_Level = 1;
		display_winner();
	}

}

void Core::stop_game(std::vector <Element *> elements)
{
	for(int i = 0; i < (int)elements.size(); i++){
		if ((elements[i]->getType() == SHIP ||
		     elements[i]->getType() == PERSONAGE)) {
			if (elements[i]->getLife() == WINNER)
				levelUp();
			else if (elements[i]->getLife() == LOSER) {
				_Level = 1;
				display_game_over();
			}
		}
	}
}

t_InfoElement Core::getInfoElement(std::vector <Element *> thing, int i)
{
	t_InfoElement infoElement;

	infoElement.x = thing[i]->getX();
	infoElement.y = thing[i]->getY();
	infoElement.size = thing[i]->getSize();
	infoElement.Color = thing[i]->getColor();
	infoElement.type = thing[i]->getType();
	return (infoElement);
}

void Core::executeFrame_next(std::vector <Element *> elements, int i,
			     t_InfoElement infoElement)
{
	std::vector <Element *> sub_elements = elements[i]->getSubElements();

	for(int i = 0; i < (int)sub_elements.size(); i++){
		infoElement = getInfoElement(sub_elements, i);
		_current_interface->drawSquare(infoElement);
	}
}

void Core::executeFrame(Event &event)
{
	std::vector <Element *> elements;
	t_InfoElement infoElement;

	_current_interface->prepareScene(15);
	elements = _current_game->getElements();
	stop_game(elements);
	_current_game->event(event);
	for(int i = 0; i < (int)elements.size(); i++){
		elements[i]->handleEvent(event);
		if (elements[i]->getType() != 'V') {
			infoElement = getInfoElement(elements, i);
			_current_interface->drawSquare(infoElement);
		}
		executeFrame_next(elements, i, infoElement);
	}
	_current_interface->endScene();
	usleep(15);
	event.updateTime();
}

void Core::loadGameOver(const std::string path)
{
	std::ifstream file(path);
	std::string line;

	if (file) {
		for (int y = 0; std::getline(file, line); y++)
			_Game_over.push_back(line);
		file.close();
	} else {
		std::cerr << "Can't open " << path << std::endl;
	}
}

void Core::loadWinner(const std::string path)
{
	std::ifstream file(path);
	std::string line;

	if (file) {
		for (int y = 0; std::getline(file, line); y++)
			_Winner.push_back(line);
		file.close();
	} else {
		std::cerr << "Can't open " << path << std::endl;
	}
}

void Core::loadMenu(const std::string path)
{
	std::ifstream file(path);
	std::string line;

	if (file) {
		for (int y = 0; std::getline(file, line); y++)
			_Menu.push_back(line);
		file.close();
	} else {
		std::cerr << "Can't open " << path << std::endl;
	}
}

template <class TypeName>
void Core::loadLib(const std::string name,
		   const std::string path,
		   std::map<std::string, TypeName> &datas)
{
	TypeName (*_create)();
	void* handle = dlopen(path.c_str(), RTLD_LAZY);
	TypeName interface;

	if (!handle){
		std::cerr << "Can't open " << path << std::endl;
		exit(0);
        }
	_create = (TypeName(*)())dlsym(handle, "_create");
	if (!_create){
		std::cerr << "Can't find function _create" << std::endl;
		exit(0);
	}
	interface = _create();
	if (!interface){
		std::cerr << "Can't create Interface" << std::endl;
		exit(0);
        }
	datas[name] = interface;
}

void Core::eventK_p(Event &event)
{
	_pause = !_pause;
	event = Event();
}

void Core::eventK_n(Event &event)
{
	(void)event;
	_current_interface-> DeleteInterface();
	_current_interface->Init();
	_current_interface->createWindow_games();
}

void Core::eventK_m(Event &event)
{
	executeFrame(event);
	event = Event();
	menu();
}

void Core::eventK_o(Event &event)
{
	_current_interface-> DeleteInterface();
	_current_interface = _interfaces["openGl"];
	_current_interface->Init();
	_current_interface->createWindow_games();
	(void)event;
}

void Core::eventK_c(Event &event)
{
	_current_interface-> DeleteInterface();
	_current_interface = _interfaces["Caca"];
	(void)event;
}

void Core::eventK_s(Event &event)
{
	_current_interface-> DeleteInterface();
	_current_interface = _interfaces["SDL"];
	_current_interface->Init();
	_current_interface->createWindow_games();
	(void)event;
}

void Core::eventK_a(Event &event)
{
	if (_current_game != _games["Pacman"]){
		_Acting = PACMAN;
		setup_game(_Acting);
	}
	(void)event;
}

void Core::eventK_z(Event &event)
{
	if (_current_game != _games["Centipede"]){
		_Acting = CENTIPEDE;
		setup_game(_Acting);
	}
	(void)event;
}

void Core::eventK_e(Event &event)
{
	if (_current_game != _games["Nibbler"]){
		_Acting = NIBBLER;
		setup_game(_Acting);
	}
	(void)event;
}

