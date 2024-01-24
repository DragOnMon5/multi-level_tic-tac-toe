#pragma once
#include <array>
#include "cell.h"
#include <SFML/Graphics.hpp>

//typedef std::array<std::array<sf::RectangleShape, 3>, 3> playing_field_size;
//
//playing_field_size get_playing_field(TTTUnit);


class TTTUnit
{
private:
	float cellX = 100;
	float cellY = 100;
	float startX = 100;
	float startY = 100;
	int playing_field[3][3]{};
	int triplet_sum[8]{};
	int turn {};
	bool end_of_game{ 0 };
	int x{};
	int y{};
	int winner{};

public:
	std::array<std::array<Cell, 3>, 3> cell_playing_field;
	TTTUnit();
	bool get_end_of_game();
	int get_winner();
	bool step(int i, int j);
	void sum_triplet();
	void check();
	void reset_variables();
	void play(sf::RenderWindow&, sf::Event&, sf::Vector2i&);
	void print();
	void cell_pressed(sf::RenderWindow&, sf::Event&, sf::Vector2i&);

	//friend std::shared_ptr<std::array<std::array<TTTUnit, 3>, 3>> get_playing_field(TTTUnit&);
};

