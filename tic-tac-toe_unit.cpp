#include <iostream>
#include <algorithm>
#include "tic-tac-toe_unit.h"

TTTUnit::TTTUnit()
{

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
			std::cout << row << col << ' ';
		}
		std::cout << std::endl;
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
			winner = 1;
			end_of_game = 1;
			return;
		}
		if (i == -3)
		{
			std::cout << "2 win\n";
			winner = 2;
			end_of_game = 1;
			return;
		}
	}
	if (turn == 9)
	{
		std::cout << "DRAW\n";
		winner = 3;
		end_of_game = 1;
		return;
	}
}

void TTTUnit::reset_variables()
{
	/*for (int i = 0; i < 3; i++)
	{
		playing_field[0][i] = playing_field[1][i] = playing_field[2][i] = 0;
	}*/
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			playing_field[i][j] = 0;
			cell_playing_field[i][j].set_color(sf::Color(255, 255, 255));
		}
	}
	for (int i = 0; i < 8; i++)
	{
		triplet_sum[i] = 0;
	}
	turn = 0;
	end_of_game = 0;

}

void TTTUnit::play(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	//resetVariables();
	//cell_pressed(window, event, mouse_position);

	cell_pressed(window, event, mouse_position);
	sum_triplet();
	check();

	/*while (!end_of_game) {
		std::cin >> x;
		std::cin >> y;
		step(x, y);
		print();
		sumTriplet();
		check();
	}*/
}

void TTTUnit::print()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << playing_field[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void TTTUnit::cell_pressed(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	std::pair<int, int> temp{};
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