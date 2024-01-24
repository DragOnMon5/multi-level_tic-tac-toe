#include <iostream>
#include <SFML/Graphics.hpp>
#include "shapes.h"
#include "game_screen.h"

//#include "game_field.h"

void grid_play(Grid* grid, sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	if (!grid->get_end_of_game())
	{
		grid->launch(window, event, mouse_position);
	}
	else
	{
		grid->reset_variables();
		
	}
	
	/*if (!(grid->get_unit()->get_end_of_game()))
	{
		grid->launch(window, event, mouse_position);
	}
	else
	{
		grid->get_unit()->resetVariables();
	}*/
}

void launch_game_screen(sf::RenderWindow& window, Grid* grid)
{

	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
	//sf::Vector2f mouse_position = window.mapPixelToCoords(mousePos1);
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

	}

	window.clear();
	
	grid_play(grid, window, event, mouse_position);

	window.display();
	
}

//delete
void launch_game_screen(sf::RenderWindow & window, TTTUnit* unit)
{
	
		sf::Vector2i mousePos1 = sf::Mouse::getPosition(window);
		sf::Vector2f mousePos = window.mapPixelToCoords(mousePos1);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}

		window.clear();
		
		
		if (!unit->get_end_of_game())
		{
		unit->play(window, event, mousePos1);
		}
		else
		{
			unit->reset_variables();
		}
		/*for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				unit->cell_playing_field[i][j].pressed(window, event, mousePos1);
				window.draw(unit->cell_playing_field[i][j].get_sf_shape());
			}
		}*/

		window.display();
	//}
}