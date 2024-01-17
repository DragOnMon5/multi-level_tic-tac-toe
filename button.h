#pragma once
#include <SFML/Graphics.hpp>

class Button
{
protected:
	
	//
public:
	sf::RectangleShape button;
	Button() = default;
	Button(sf::RectangleShape bt);
	void set_position(sf::Vector2f pos);
	sf::Vector2f get_position();
	void set_color(sf::Color);

};