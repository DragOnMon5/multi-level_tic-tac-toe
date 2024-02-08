#pragma once
#include <array>
#include "cell.h"
#include <SFML/Graphics.hpp>

enum class Winner
{
	first = 1,
	second = 2,
	draw = 3
};

class TTTUnit
{
private:
	float cellX{};
	float cellY{};
	float startX{};
	float startY{};
	int playing_field[3][3]{};
	std::array<std::array<Cell, 3>, 3> cell_playing_field;
	int triplet_sum[8]{};
	int turn {};
	int filled_cells{};
	bool end_of_game{};
	int winner{};

public:
	TTTUnit();
	void set_first_in_game(int);
	bool get_end_of_game();
	int get_winner();
	bool step(int i, int j);
	void sum_triplet();
	void check();
	void play(sf::RenderWindow&, sf::Event&, sf::Vector2i&);
	void cell_pressed(sf::RenderWindow&, sf::Event&, sf::Vector2i&);
};

