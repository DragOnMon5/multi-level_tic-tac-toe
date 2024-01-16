#include <iostream>
#include <algorithm>
#include "tic-tac-toe_unit.h"

TTTUnit::TTTUnit(Cell& cell)
{
	button = cell.button;
}

void TTTUnit::step(int i, int j)
{
	//static int turn = 0;

	i--;
	j--;
	if (!playing_field[i][j])
	{
		playing_field[i][j] = 1 - 2 * (turn % 2);
		//check() was here;
		turn++;
		//std::cout << turn << "\n";
	}
}

void TTTUnit::sumTriplet()
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
}

void TTTUnit::resetVariables()
{
	for (int i = 0; i < 3; i++)
	{
		playing_field[0][i] = playing_field[1][i] = playing_field[2][i] = 0;
	}
	for (int i = 0; i < 8; i++)
	{
		triplet_sum[i] = 0;
	}
	turn = 0;
	end_of_game = 0;
	
}

int TTTUnit::play()
{
	resetVariables();
	while (!end_of_game) {
		std::cin >> x;
		std::cin >> y;
		step(x, y);
		print();
		sumTriplet();
		check();
	}
	return winner;
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

void TTTUnit::pressed(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position) 
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