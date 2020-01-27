#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>

#include "../includes/Core.hpp"

void ta_lib (char *str)
{
	std::vector <std::string> list_libs;
	std::vector <std::string> stock;
	std::string lib = str;

	list_libs.push_back("/lib_arcade_opengl.so");
	list_libs.push_back("/lib_arcade_sdl.so");
	list_libs.push_back("/lib_arcade_libcaca.so");
	stock.push_back("openGl");
	stock.push_back("SDL");
	stock.push_back("Caca");
	for (int i = 0; i < (int) list_libs.size(); i++) {
		std::size_t found = lib.find(list_libs[i]);
		if (found != std::string::npos)
			Core core(stock[i]);
	}
}

int main (int ac, char **av)
{
	if (ac != 2)
		return (1);
	ta_lib(av[1]);
	return (0);
}
