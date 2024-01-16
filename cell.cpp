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
Cell::Cell(sf::RectangleShape bt)
{
	button = bt;
}
sf::RectangleShape& Cell::get_sf_shape()
{
	return button;
}

void Cell::pressed(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (button.getGlobalBounds().contains(mouse_position.x, mouse_position.y))
			std::cout << 2;
		}
	}
}
