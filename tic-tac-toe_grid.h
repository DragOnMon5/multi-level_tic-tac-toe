#pragma once
#include "tic-tac-toe_unit.h"

class Grid
{
private:
	float cellX{};
	float cellY{};
	float startX = 100;
	float startY = 100;
	int layer{};
	int playing_grid[3][3]{};
	//data
	std::array<std::array<TTTUnit*, 3>, 3> unit;
	std::array<std::array<Grid*, 3>, 3> grid;
	std::array<std::array<Cell, 3>, 3> cell_playing_grid;
	int triplet_sum[8]{};
	//obrabotka
	int winner{};
	int winner_in_last_game{};
	int turn{};
	int filled_cells{};
	int current_game_x{};
	int current_game_y{};
	bool unit_game_started{ 0 };
	bool end_of_game{ 0 };
	void setMainLayer(int);
	void sumTriplet();
	void check();
	void cell_pressed(sf::RenderWindow&, sf::Event&, sf::Vector2i&);
	void play(sf::RenderWindow&, sf::Event&, sf::Vector2i&);

public:
	Grid(int);
	~Grid();
	void set_first_in_game(int);
	bool get_end_of_game();
	int get_winner();
	std::array<std::array<Cell, 3>, 3>& get_cell_playing_grid();
	int launch(sf::RenderWindow&, sf::Event&, sf::Vector2i&);
};