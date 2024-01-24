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
	TTTUnit* unit = new TTTUnit();
	Grid *grid = new Grid(2);
	//std::cout << grid->launch() << std::endl;
	
	int i = 0;
	/*while (window.isOpen())
	{*/
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		//sf::Vector2f mousePos = window.mapPixelToCoords(mousePos1);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}
		grid->launch(window, event, mouse_position);
		//launch_game_screen(window, unit, mouse_position);
	//}


	

	return 0;
}