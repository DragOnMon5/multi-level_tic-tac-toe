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

sf::Color Cell::get_color()
{
	return button.getFillColor();
}

sf::Vector2f Cell::get_size()
{
	return button.getSize();
}


void Cell::set_cell(Cell& cell)
{
	this->set_position(cell.get_position());
	this->set_color(cell.get_color());
	this->button.setSize(cell.button.getSize());
	this->row = cell.row;
	this->col = cell.col;
	button = cell.button;
}

void Cell::set_size(sf::Vector2f size)
{
	button.setSize(size);
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
