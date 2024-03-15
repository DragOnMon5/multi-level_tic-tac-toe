#pragma once
#include "GridController.h"


class GridView
{
public:
	void clear_window(sf::RenderWindow&, sf::Color);
	void draw_cell(sf::RenderWindow&, Cell*);
};
