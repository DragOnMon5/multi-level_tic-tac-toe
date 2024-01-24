#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "tic-tac-toe_unit.h"
#include "tic-tac-toe_grid.h"


Grid::Grid(int layer)
{
	unit = new TTTUnit();
	setMainLayer(layer);
	/*float cellX = 150;
	float cellY = 150;
	float startX = 100;
	float startY = 100;*/
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			Cell temp_cell(row, col,
				Rect(sf::Vector2f(cellX, cellY),
					startX + cellX * col * 1.1,
					startY + cellY * row * 1.1,
					sf::Color(255, 255, 255)));

			cell_playing_grid[row][col] = temp_cell;
			//std::cout << row << col << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "Grid Constructor " << layer << std::endl;
}

Grid::~Grid()
{
	std::cout << "Grid Destructor " << layer << std::endl;
}

void Grid::setMainLayer(int layer)
{
	this->layer = layer;
}

void Grid::sumTriplet()
{
	for (int i = 0; i < 3; i++)
	{
		triplet_sum[i] = playing_grid[i][0] + playing_grid[i][1] + playing_grid[i][2];
		triplet_sum[3 + i] = playing_grid[0][i] + playing_grid[1][i] + playing_grid[2][i];
	}
	triplet_sum[6] = playing_grid[0][0] + playing_grid[1][1] + playing_grid[2][2];
	triplet_sum[7] = playing_grid[2][0] + playing_grid[1][1] + playing_grid[0][2];
}

bool Grid::endGameCheck()
{
	for (auto i : triplet_sum)
	{
		if (i == 3)
		{
			std::cout << "1 win\n";
			winner = 1;
			//end_of_game = 1;
			return 1;
		}
		if (i == -3)
		{
			std::cout << "2 win\n";
			winner = 2;
			//end_of_game = 1;
			return 1;
		}

	}
	return 0;
}

TTTUnit* Grid::get_unit()
{
	return unit;
}

Grid* Grid::get_lower_level()
{
	if (layer >= 1)
	{
		return lower_level;
	}
	else
	{
		return this;
	}
}

bool Grid::get_end_of_game()
{
	return end_of_game;
}

int Grid::get_winner()
{
	return winner;
}


void Grid::check()
{
	for (auto i : triplet_sum)
	{
		if (i == 3)
		{
			std::cout << "1 win\n"; //first
			winner = 1;
			end_of_game = true;
			return;
		}
		if (i == -3)
		{
			std::cout << "2 win\n"; //second
			winner = 2;
			end_of_game = true;
			return;
		}
		if (i == 30)
		{
			std::cout << "DRAW\n"; //draw
			winner = 3;
			end_of_game = true;
			return;
		}
	}
	if (turn == 9)
	{
		std::cout << "DRAW\n"; //draw
		winner = 3;
		end_of_game = true;
		return;
	}
}

void Grid::reset_variables()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			playing_grid[i][j] = 0;
			cell_playing_grid[i][j].set_color(sf::Color(255, 255, 255));
		}
	}
	for (int i = 0; i < 8; i++)
	{
		triplet_sum[i] = 0;
	}
	turn = 0;
	end_of_game = 0;

}

void Grid::play(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	if (layer == 1)
	{
		unit->play(window, event, mouse_position);

		if (unit->get_end_of_game())
		{
			unit_game_started = false;
			int t = unit->get_winner();
			Cell temp_cell = Cell(0, 0,
				Rect(sf::Vector2f(cellX, cellY),
					startX + cellX * current_game_y * 1.1,
					startY + cellY * current_game_x * 1.1,
					sf::Color(0, 255 * ((t + 1) % 3), 255 * (t % 3))));

			switch (t)
			{
			case 1:
				playing_grid[current_game_x][current_game_y] = 1;
				break;
			case 2:
				playing_grid[current_game_x][current_game_y] = -1;
				break;
			case 3:
				playing_grid[current_game_x][current_game_y] = 10;
				break;
			}

			cell_playing_grid[current_game_x][current_game_y] = temp_cell;
			//window.draw(cell_playing_grid[current_game_x][current_game_y].get_sf_shape());
			unit->reset_variables();
		}

		sumTriplet();
		check();
	}
	/*else if (layer >= 2)
	{
		low_level = new Grid(layer - 1);
		low_level->launch(window, event, mouse_position);
		if (low_level->get_winner())
		{

		}
	}*/

	return;
}

int Grid::launch(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	if (!unit_game_started)
	{
		cell_pressed(window, event, mouse_position);
	}
	else if (!unit->get_end_of_game())
	{
		//unit->play(window, event, mouse_position);
		play(window, event, mouse_position);
	}


	//if (!unit->get_end_of_game())
	//{
	//	unit->play(window, event, mouse_position);
	//	sumTriplet();
	//	check();
	//}
	//else
	//{
	//	//return winner
	//	unit->resetVariables();
	//	unit_game_started = 0;
	//}

	//if (layer == 1)
	//{
	//	a = new TTTUnit();
	//	//return a->play();
	//}
	//else if (layer >= 2)
	//{

	//	for (int i : {0, 1, 2})
	//	{
	//		for (int j : {0, 1, 2})
	//		{
	//			b = new Grid(layer - 1);
	//			playing_grid[i][j] = b->launch();
	//			delete b;
	//			sumTriplet();
	//			//check();
	//			if (endGameCheck())
	//			{
	//				return winner;
	//			}
	//		}
	//	}

	//}
	/*else if (layer > 2)
	{
		b = new Grid(layer-1);
		b->launch();

	}*/
	return 0;
}

void Grid::cell_pressed(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	//std::pair<int, int> temp{};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cell_playing_grid[i][j].pressed(window, event, mouse_position))
			{
				if (!playing_grid[i][j])
				{
					unit_game_started = 1;
					current_game_x = i;
					current_game_y = j;
				}
				//if (step(i, j))
				//{
				//	//cell_playing_grid[i][j].set_color(sf::Color(0, 255 * (( + 1) % 2), 255 * (turn % 2)));
				//}
			}
			window.draw(cell_playing_grid[i][j].get_sf_shape());
		}
	}

	//delete this
	/*if (event.type == sf::Event::MouseButtonPressed)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (button.getGlobalBounds().contains(mouse_position.x, mouse_position.y))
				std::cout << 2;
		}
	}*/
}

