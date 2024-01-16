#include "button.h"

Button::Button(sf::RectangleShape bt)
{
	button = bt;
}

void Button::set_position(sf::Vector2f pos)
{
	button.setPosition(pos);
}

sf::Vector2f Button::get_position()
{
	return button.getPosition();
}