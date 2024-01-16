#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "shapes.h"
#include "button.h"


class Cell : public Button
{

public:
	Cell() = default;
	Cell(const Cell&);
	Cell(sf::RectangleShape );
	sf::RectangleShape& get_sf_shape();
	virtual void pressed(sf::RenderWindow&, sf::Event& , sf::Vector2i&);
};