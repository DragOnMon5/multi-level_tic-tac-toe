#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "tic-tac-toe_unit.h"
#include "tic-tac-toe_grid.h"


Grid::Grid(int layer)
{
	setMainLayer(layer);
	cellX = 100+layer*14;
	cellY = 100+layer*14;
	if (layer == 1)
	{
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				unit[row][col] = new TTTUnit();
			}
		}
	}
	else if (layer >= 2)
	{
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				grid[row][col] = new Grid(layer - 1);
			}
		}
	}

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
		}
	}
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

bool Grid::get_end_of_game()
{
	return end_of_game;
}

int Grid::get_winner()
{
	return winner;
}

std::array<std::array<Cell, 3>, 3>& Grid::get_cell_playing_grid()
{
	return cell_playing_grid;
}

void Grid::check()
{
	for (auto i : triplet_sum)
	{
		if (i == 3)
		{
			std::cout << "1 win\n";
			winner = static_cast<int>(Winner::first);
			end_of_game = true;
			return;
		}

		if (i == -3)
		{
			std::cout << "2 win\n";
			winner = static_cast<int>(Winner::second);
			end_of_game = true;
			return;
		}
	}

	if (turn == 9)
	{
		std::cout << "DRAW\n";
		winner = static_cast<int>(Winner::draw);
		end_of_game = true;
		return;
	}
}

void Grid::play(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	if (layer == 1)
	{
		unit[current_game_x][current_game_y]->play(window, event, mouse_position);

		if (unit[current_game_x][current_game_y]->get_end_of_game())
		{
			unit_game_started = false;
			int t = unit[current_game_x][current_game_y]->get_winner();
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
		}
	}

	if (layer >= 2)
	{
		grid[current_game_x][current_game_y]->launch(window, event, mouse_position);
		if (grid[current_game_x][current_game_y]->get_end_of_game())
		{
			unit_game_started = false;
			int t = grid[current_game_x][current_game_y]->get_winner();
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

			turn++;
			cell_playing_grid[current_game_x][current_game_y] = temp_cell;
		}
	}
	sumTriplet();
	check();

	return;
}

int Grid::launch(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	if (!unit_game_started)
	{
		cell_pressed(window, event, mouse_position);
	}
	else 
	{
		play(window, event, mouse_position);
	}
	
	return 0;
}

void Grid::cell_pressed(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
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
			}
			window.draw(cell_playing_grid[i][j].get_sf_shape());
		}
	}
}

