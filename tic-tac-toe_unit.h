#pragma once
#include <array>
#include <SFML/Graphics.hpp>

//typedef std::array<std::array<sf::RectangleShape, 3>, 3> playing_field_size;
//
//playing_field_size get_playing_field(TTTUnit);


class TTTUnit
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
	void step(int i, int j);
	void sumTriplet();
	void check();
	void resetVariables();
	int play();
	void print();

	friend std::shared_ptr<std::array<std::array<sf::RectangleShape, 3>, 3>> get_playing_field(TTTUnit&);
};