#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "tic-tac-toe_unit.h"
#include "tic-tac-toe_grid.h"


Grid::Grid(int layer)
{
	setMainLayer(layer);
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

int Grid::launch()
{
	if (layer == 1)
	{
		a = new TTTUnit();
		return a->play();
	}
	else if (layer >= 2)
	{

		for (int i : {0, 1, 2})
		{
			for (int j : {0, 1, 2})
			{
				b = new Grid(layer - 1);
				playing_grid[i][j] = b->launch();
				delete b;
				sumTriplet();
				//check();
				if (endGameCheck())
				{
					return winner;
				}
			}
		}

	}
	/*else if (layer > 2)
	{
		b = new Grid(layer-1);
		b->launch();

	}*/
}

