#pragma once
#include <array>
#include "cell.h"
#include <SFML/Graphics.hpp>

//typedef std::array<std::array<sf::RectangleShape, 3>, 3> playing_field_size;
//
//playing_field_size get_playing_field(TTTUnit);


class TTTUnit : public Cell
{
private:
	int playing_field[3][3]{};
	int triplet_sum[8]{};
	int turn = {};
	bool end_of_game{ 0 };
	int x{};
	int y{};
	int winner{};

public:
	TTTUnit() = default;
	TTTUnit(Cell&);
	void step(int i, int j);
	void sumTriplet();
	void check();
	void resetVariables();
	int play();
	void print();
	void pressed(sf::RenderWindow&, sf::Event&, sf::Vector2i&) override;

	friend std::shared_ptr<std::array<std::array<TTTUnit, 3>, 3>> get_playing_field(TTTUnit&);
};

//void qwe()
//{
//	TTTUnit a;
//
//}