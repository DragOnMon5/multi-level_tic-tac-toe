#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "shapes.h"
#include "button.h"


class Cell : public Button
{
	int row;
	int col;
public:
	Cell() = default;
	Cell(const Cell&);
	Cell(int, int);
	Cell(int, int, sf::RectangleShape );
	sf::RectangleShape& get_sf_shape();
	virtual bool pressed(sf::RenderWindow&, sf::Event& , sf::Vector2i&);
};