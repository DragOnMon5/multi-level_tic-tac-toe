#pragma once
#include "tic-tac-toe_unit.h"

class Grid
{
private:

	Grid* lower_level;
	// layer > 2 = i -> b(i-1)
	// layer = 2 -> this.launch()
	// layer = 1 -> a.play();
	float cellX = 150;
	float cellY = 150;
	float startX = 100;
	float startY = 100;
	int playing_grid[3][3]{};
	int triplet_sum[8]{};
	int winner{};
	int turn{};
	int current_game_x{};
	int current_game_y{};
	bool unit_game_started{ 0 };
	bool end_of_game{ 0 };
	int layer{};
	void setMainLayer(int);
	void sumTriplet();
	bool endGameCheck();

public:
	std::array<std::array<Cell, 3>, 3> cell_playing_grid;
	TTTUnit* unit;
	Grid(int);
	~Grid();
	TTTUnit* get_unit();
	Grid* get_lower_level();
	bool get_end_of_game();
	int get_winner();
	//bool step(int, int);
	void check();
	void reset_variables();
	void play(sf::RenderWindow&, sf::Event&, sf::Vector2i&);
	int launch(sf::RenderWindow&, sf::Event&, sf::Vector2i&);
	void cell_pressed(sf::RenderWindow&, sf::Event&, sf::Vector2i&);
};