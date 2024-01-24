#pragma once
#include <SFML/Graphics.hpp>
#include "tic-tac-toe_grid.h"

void grid_play(Grid*, sf::RenderWindow&, sf::Event&, sf::Vector2i&);
void launch_game_screen(sf::RenderWindow&, Grid *);
void launch_game_screen(sf::RenderWindow&, TTTUnit*);