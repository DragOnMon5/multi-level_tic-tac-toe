#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "tic-tac-toe_unit.h"
#include "tic-tac-toe_grid.h"
#include "game_screen.h"

int main(int argc, char* argv[])
{
	int windowWidth = 800;
	int windowHeight = 640;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");

	TTTUnit *unit = new TTTUnit();
	
	int i = 0;
	while (window.isOpen())
	{

		launch_game_screen(window, unit);
	}


	//Grid a(1);
	//TTTUnit b;
	//int a[9][9];
	//std::cout << a.launch() << std::endl;

	return 0;
}