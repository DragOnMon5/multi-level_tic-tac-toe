#include <iostream>
#include <algorithm>
#include "tic-tac-toe_unit.h"

TTTUnit::TTTUnit()
{
	cellX = 100;
	cellY = 100;
	startX = 100;
	startY = 100;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			Cell temp_cell(row, col,
				Rect(sf::Vector2f(cellX, cellY),
					startX + cellX * col * 1.1,
					startY + cellY * row * 1.1,
					sf::Color(255, 255, 255)));
			cell_playing_field[row][col] = temp_cell;
		}
	}
}

void TTTUnit::set_first_in_game(int first)
{
	if (!turn)
	{
		turn = first;
	}
}


bool TTTUnit::get_end_of_game()
{
	return end_of_game;
}

int TTTUnit::get_winner()
{
	return winner;
}

bool TTTUnit::step(int i, int j)
{
	if (!playing_field[i][j])
	{
		playing_field[i][j] = 1 - 2 * (turn % 2);
		turn++;
		filled_cells++;
		return true;
	}
	else
	{
		return false;
	}
}

void TTTUnit::sum_triplet()
{
	for (int i = 0; i < 3; i++)
	{
		triplet_sum[i] = playing_field[i][0] + playing_field[i][1] + playing_field[i][2];
		triplet_sum[3 + i] = playing_field[0][i] + playing_field[1][i] + playing_field[2][i];
	}
	triplet_sum[6] = playing_field[0][0] + playing_field[1][1] + playing_field[2][2];
	triplet_sum[7] = playing_field[2][0] + playing_field[1][1] + playing_field[0][2];
}

void TTTUnit::check()
{
	for (auto i : triplet_sum)
	{
		if (i == 3)
		{
			std::cout << "1 win\n";
			winner = static_cast<int>(Winner::first);
			end_of_game = 1;
			return;
		}
		if (i == -3)
		{
			std::cout << "2 win\n";
			winner = static_cast<int>(Winner::second);
			end_of_game = 1;
			return;
		}
	}
	if (filled_cells == 9)
	{
		std::cout << "DRAW\n";
		winner = static_cast<int>(Winner::draw);
		end_of_game = 1;
		return;
	}
}

void TTTUnit::play(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	cell_pressed(window, event, mouse_position);
	sum_triplet();
	check();
}

void TTTUnit::cell_pressed(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cell_playing_field[i][j].pressed(window, event, mouse_position))
			{
				if (step(i, j))
				{
					cell_playing_field[i][j].set_color(sf::Color(0, 255 * ((turn + 1) % 2), 255 * (turn % 2)));
				}
			}
			window.draw(cell_playing_field[i][j].get_sf_shape());
		}
	}
}