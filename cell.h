#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "shapes.h"
#include "button.h"


class Cell : public Button
{
	int row{};
	int col{};
public:
	Cell() = default;
	Cell(const Cell&);
	Cell(int, int);
	Cell(int, int, sf::RectangleShape );
	sf::RectangleShape& get_sf_shape();
	sf::Color get_color();
	sf::Vector2f get_size();
	void set_cell(Cell&);
	void set_size(sf::Vector2f);
	virtual bool pressed(sf::RenderWindow&, sf::Event& , sf::Vector2i&);
};