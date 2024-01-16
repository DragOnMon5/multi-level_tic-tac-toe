#pragma once
#include <SFML/Graphics.hpp>
#include "tic-tac-toe_unit.h"
#include "cell.h"

//using playing_field_size = std::array<std::array<Cell, 3>, 3>;
using playing_field_size = std::array<std::array<TTTUnit, 3>, 3>;
//typedef std::array<std::array<sf::RectangleShape, 3>, 3> playing_field_size;

std::shared_ptr<playing_field_size> get_playing_field(TTTUnit&);