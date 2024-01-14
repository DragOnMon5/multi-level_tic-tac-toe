#include "shapes.h"

sf::RectangleShape Rect(sf::Vector2f v2f, float posX, float posY, sf::Color color)
{
	sf::RectangleShape temp(v2f);
	temp.setPosition(posX, posY);
	temp.setFillColor(color);
	return temp;
}

