#include <iostream>
#include <SFML/Graphics.hpp>
#include "shapes.h"
#include "game_screen.h"
#include "GridController.h"

void grid_play(GridController* gridController, sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{

	if (!gridController->get_end_of_game())
	{
		gridController->launch(window, event, mouse_position);
	}
	else
	{
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				window.draw(gridController->get_cell_playing_grid()[row][col].get_sf_shape());
			}
		}
	}
}

void grid_play(Grid* grid, sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	if (!grid->get_end_of_game())
	{
		grid->launch(window, event, mouse_position);
	}
	else
	{
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				window.draw(grid->get_cell_playing_grid()[row][col].get_sf_shape());
			}
		}
	}
}



void launch_game_screen(sf::RenderWindow& window, GridController* gridController)
{

	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
	//sf::Vector2f mouse_position = window.mapPixelToCoords(mousePos1);
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

	}

	window.clear(sf::Color(25,25,25));
	
	grid_play(gridController, window, event, mouse_position);

	window.display();
	
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