#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "tic-tac-toe_unit.h"
#include "tic-tac-toe_grid.h"
#include "GridController.h"
#include "game_screen.h"


int main(int argc, char* argv[])
{
	int windowWidth = 800;
	int windowHeight = 640;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
	//Grid* grid = new Grid(2);
	
	GridController* gridController = new GridController(2, window);

	while (window.isOpen())
	{

		launch_game_screen(window, gridController);
	}

	return 0;
}