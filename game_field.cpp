#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
#include "shapes.h"
#include "tic-tac-toe_unit.h"
#include "cell.h"
#include "game_field.h"




std::shared_ptr<playing_field_size> get_playing_field(TTTUnit* unit)
{
	float cellX = 100;
	float cellY = 100;
	float startX = 100;
	float startY = 100;
	//unit->cell_playing_field
	auto a = Rect();
	//Cell b(a);
	//playing_field_size *playing_field = new playing_field_size;
	std::shared_ptr<playing_field_size> playing_field(new playing_field_size);
	//sf::RectangleShape playing_field[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			/*Cell temp_cell(Rect(
				sf::Vector2f(cellX, cellY),
				startX * (j + 1) * 1.1,
				startY * (i + 1) * 1.1,
				sf::Color(255, 127, 127)));
			(*playing_field)[i][j] = TTTUnit(temp_cell);*/
		}
	}

	return playing_field;
}