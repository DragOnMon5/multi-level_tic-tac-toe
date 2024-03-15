#pragma once
#include "tic-tac-toe_unit.h"

class GridModel;
class GridView;

class GridController //управление всем оркестром. Считываем ввод польователя и определяем дальнейшее действие
{
	GridModel* model;
	GridView* view;
	sf::RenderWindow& window;
	void set_current_layer(int);
	void sum_triplet();
	void check();
	void cell_pressed(sf::Event&, sf::Vector2f&);
	void play(sf::Event&, sf::Vector2f&);
public:
	GridController(int, sf::RenderWindow&);
	void set_first_in_game(int);
	int get_winner();
	bool get_end_of_game();
	std::array<std::array<Cell,3>,3>& get_cell_playing_grid();
	int launch(sf::Event&, sf::Vector2f&);
};