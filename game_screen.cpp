#include <iostream>
#include <SFML/Graphics.hpp>
#include "tic-tac-toe_unit.h"
#include "shapes.h"
#include "game_field.h"

void draw_objects(sf::RenderWindow& window, TTTUnit* unit)
{
	for (auto i : unit->cell_playing_field)
	{
		for (auto j : i)
		{
			window.draw(j.get_sf_shape());
		}
	}
}

void launch_game_screen(sf::RenderWindow & window, TTTUnit* unit)
{
	window.clear();
	//draw_objects(window, unit);
	window.display();
	
}