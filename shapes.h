#pragma once
#include <SFML/Graphics.hpp>

sf::RectangleShape Rect(
	sf::Vector2f v2f = sf::Vector2f(10, 10),
	float posX = 0, float posY = 0,
	sf::Color color = sf::Color(255, 255, 255));

