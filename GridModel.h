#pragma once
#include "GridController.h"

enum Cell_values {
	cellX,
	cellY,
	startX,
	startY
};

//сделать массив из этих переменных и обращаться к нему
enum Model_data {
	winner,
	winner_in_last_game,
	turn,
	filled_cells,
	current_game_x,
	current_game_y,
	unit_game_started,
	end_of_game
};

class GridModel //данные, которые могут меняться. Данные и функции для извлечения и манипуляции.
{

	std::array<float, 4> cell_values;
	std::array<int, 8> model_data;
	int layer{};
	std::array<std::array<int, 3>, 3> playing_grid;
	std::array<std::array<TTTUnit*, 3>, 3> units;
	std::array<std::array<GridController*, 3>, 3> grids;
	std::array<std::array<Cell, 3>, 3> cell_playing_grid;
	std::array<int, 8> triplet_sum;
	int winner{};
	int winner_in_last_game{};
	int turn{};
	int filled_cells{};
	int current_game_x{};
	int current_game_y{};
	bool unit_game_started{ 0 };
	bool end_of_game{ 0 };
public:
	void set_current_layer(int);
	int get_current_layer();
	std::array<float, 4>& get_cell_values();
	std::array<int, 8>& get_model_data();
	std::array<int, 8>& get_triplet_sum();
	std::array<std::array<int, 3>, 3>& get_playing_grid();
	std::array<std::array<Cell, 3>, 3>& get_cell_playing_grid();
	std::array<std::array<TTTUnit*, 3>, 3>& get_units();
	std::array<std::array<GridController*, 3>, 3>& get_grids();
};