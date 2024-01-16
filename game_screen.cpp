#include <iostream>
#include <SFML/Graphics.hpp>
#include "tic-tac-toe_unit.h"
#include "shapes.h"
#include "game_field.h"


void launch_game_screen(sf::RenderWindow & window)
{
	//TTTUnit* a = new TTTUnit();
	TTTUnit a;
	//std::array<std::array<sf::RectangleShape, 3>, 3> playing_field = get_playing_field(a);
	std::shared_ptr<playing_field_size> playing_field = get_playing_field(a);
	//sf::RectangleShape button = Rect(sf::Vector2f(200, 200), 200, 200, sf::Color(127,255,127));
	//button.setPosition(200, 200);
	//while (window.isOpen())
	//{
		sf::Vector2i mousePos1 = sf::Mouse::getPosition(window);
		sf::Vector2f mousePos = window.mapPixelToCoords(mousePos1);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}

		window.clear();
		for (auto i : *playing_field)
		{
			for (auto j : i)
			{
				j.pressed(window, event, mousePos1);
				window.draw(j.get_sf_shape());
			}
		}

		window.display();
	//}
}