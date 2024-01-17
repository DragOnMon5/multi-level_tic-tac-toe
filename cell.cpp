#include <iostream>
#include "shapes.h"
#include "cell.h"


// draw(sf::RenderWindow&)
//на каждой итерации передать Event& event 
//и каждый объект будет провер€ть дл€ себ€.  ажетс€, что здесь что-то не так,
//но кардинально другого решени€ не знаю

Cell::Cell(const Cell& cell)
{
	button = cell.button;
}


Cell::Cell(int row, int col, sf::RectangleShape bt)
{
	this->row = row;
	this->col = col;
	button = bt;
}

Cell::Cell(int row, int col)
{
	this->row = row;
	this->col = col;
}

sf::RectangleShape& Cell::get_sf_shape()
{
	return button;
}

bool Cell::pressed(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (button.getGlobalBounds().contains(mouse_position.x, mouse_position.y))
			{
				std::cout << row << col << std::endl;
				return true;
			}
		}
	}
	return false;
}
