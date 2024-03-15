#include "GridController.h"
#include "GridModel.h"
#include "GridView.h"

GridController::GridController(int layer, sf::RenderWindow& main_window) :window(main_window)
{
	this->model = new GridModel();
	set_current_layer(layer);

	std::array<float, 4>& cell_values = model->get_cell_values();
	cell_values[cellX] = 100 + model->get_current_layer() * 14;
	cell_values[cellY] = 100 + model->get_current_layer() * 14;
	cell_values[startX] = 100;
	cell_values[startY] = 100;
	if (model->get_current_layer() == 1)
	{
		std::array<std::array<TTTUnit*, 3>, 3>& units = model->get_units();
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				units[row][col] = new TTTUnit();
			}
		}
	}
	else if (model->get_current_layer() >= 2)
	{
		std::array<std::array<GridController*, 3>, 3>& grids = model->get_grids();
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				grids[row][col] = new GridController(model->get_current_layer() - 1, window);
			}
		}
	}

	std::array<std::array<Cell, 3>, 3>& cell_playing_grid = model->get_cell_playing_grid();
	//cell_playing_grid.resize(3, std::vector<Cell>(3));

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			Cell temp_cell(row, col,
				Rect(sf::Vector2f(cell_values[cellX], cell_values[cellY]),
					cell_values[startX] + cell_values[cellX] * col * 1.1,
					cell_values[startY] + cell_values[cellY] * row * 1.1,
					sf::Color(255, 255, 255)));
			
			cell_playing_grid[row][col] = temp_cell;
		}
	}
}

void GridController::set_current_layer(int layer)
{
	model->set_current_layer(layer);
}

void GridController::set_first_in_game(int first)
{
	auto& turn = model->get_model_data()[Model_data::turn];
	if (!turn)
	{
		turn = first;
	}
}

int GridController::get_winner()
{
	return model->get_model_data()[winner];
}

bool GridController::get_end_of_game()
{
	return model->get_model_data()[end_of_game];
}

void GridController::sum_triplet()
{
	auto& triplet_sum = model->get_triplet_sum();
	auto& playing_grid = model->get_playing_grid();
	for (int i = 0; i < 3; i++)
	{
		triplet_sum[i] = playing_grid[i][0] + playing_grid[i][1] + playing_grid[i][2];
		triplet_sum[3 + i] = playing_grid[0][i] + playing_grid[1][i] + playing_grid[2][i];
	}
	triplet_sum[6] = playing_grid[0][0] + playing_grid[1][1] + playing_grid[2][2];
	triplet_sum[7] = playing_grid[2][0] + playing_grid[1][1] + playing_grid[0][2];
}

void GridController::check()
{
	auto& triplet_sum = model->get_triplet_sum();
	int& winner = model->get_model_data()[Model_data::winner];
	int& end_of_game = model->get_model_data()[Model_data::end_of_game];
	for (auto i : triplet_sum)
	{
		if (i == 3)
		{
			std::cout << "1 win\n";
			winner = static_cast<int>(Winner::first);
			end_of_game = true;
			return;
		}

		if (i == -3)
		{
			std::cout << "2 win\n";
			winner = static_cast<int>(Winner::second);
			end_of_game = true;
			return;
		}
	}

	if (filled_cells == 9)
	{
		std::cout << "DRAW\n";
		winner = static_cast<int>(Winner::draw);
		end_of_game = true;
		return;
	}
}

std::array<std::array<Cell, 3>, 3>& GridController::get_cell_playing_grid()
{
	return model->get_cell_playing_grid();
}

void GridController::play(sf::Event& event, sf::Vector2i& mouse_position)
{
	auto& units = model->get_units();
	auto& model_data = model->get_model_data();
	int& current_game_x = model_data[Model_data::current_game_x];
	int& current_game_y = model_data[Model_data::current_game_y];
	//int& unit_game_started = model_data[Model_data::unit_game_started];

	if (model->get_current_layer() == 1)
	{
		units[current_game_x][current_game_y]->set_first_in_game(model_data[winner_in_last_game]);
		units[current_game_x][current_game_y]->play(window, event, mouse_position);

		if (units[current_game_x][current_game_y]->get_end_of_game())
		{
			model_data[unit_game_started] = false;
			int winner = units[current_game_x][current_game_y]->get_winner();
			std::array<float, 4>& cell_values = model->get_cell_values();
			Cell temp_cell = Cell(current_game_x, current_game_y,
				Rect(sf::Vector2f(cell_values[cellX], cell_values[cellY]),
					cell_values[startX] + cell_values[cellX] * current_game_y * 1.1,
					cell_values[startY] + cell_values[cellY] * current_game_x * 1.1,
					sf::Color(0, 255 * ((winner + 1) % 3), 255 * (winner % 3))));

			int cell_value{};
			switch (winner)
			{
			case 1:
				cell_value = 1;
				break;
			case 2:
				cell_value = -1;
				break;
			case 3:
				cell_value = 10;
				break;
			}

			model->get_playing_grid()[current_game_x][current_game_y] = cell_value;
			model->get_cell_playing_grid()[current_game_x][current_game_y] = temp_cell;
		}
	}

	if (model->get_current_layer() >= 2)
	{
		auto& grids = model->get_grids();
		auto& model_data = model->get_model_data();
		int& current_game_x = model_data[Model_data::current_game_x];
		int& current_game_y = model_data[Model_data::current_game_y];


		grids[current_game_x][current_game_y]->set_first_in_game(model_data[winner_in_last_game]);
		grids[current_game_x][current_game_y]->launch(window, event, mouse_position);
		if (grids[current_game_x][current_game_y]->get_end_of_game())
		{
			model_data[unit_game_started] = false;
			int winner = grids[current_game_x][current_game_y]->get_winner();
			std::array<float, 4>& cell_values = model->get_cell_values();
			Cell temp_cell = Cell(current_game_x, current_game_y,
				Rect(sf::Vector2f(cell_values[cellX], cell_values[cellY]),
					cell_values[startX] + cell_values[cellX] * current_game_y * 1.1,
					cell_values[startY] + cell_values[cellY] * current_game_x * 1.1,
					sf::Color(0, 255 * ((winner + 1) % 3), 255 * (winner % 3))));

			int cell_value{};
			switch (winner)
			{
			case 1:
				cell_value = 1;
				break;
			case 2:
				cell_value = -1;
				break;
			case 3:
				cell_value = 10;
				break;
			}
			model->get_playing_grid()[current_game_x][current_game_y] = cell_value;
		    model->get_cell_playing_grid()[current_game_x][current_game_y] = temp_cell;


			model_data[turn]++;
			model_data[filled_cells]++;
		}
	}
	sum_triplet();
	check();

	return;
}

//O_O
void GridController::cell_pressed(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	auto& cell_playing_grid = model->get_cell_playing_grid();
	auto& playing_grid = model->get_playing_grid();
	auto& units = model->get_units();
	auto& grids = model->get_grids();
	auto& model_data = model->get_model_data();
	int& current_game_x = model_data[Model_data::current_game_x];
	int& current_game_y = model_data[Model_data::current_game_y];
	//int& winner_in_last_game = model_data[Model_data::winner_in_last_game];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cell_playing_grid[i][j].pressed(window, event, mouse_position))
			{
				if (!playing_grid[i][j])
				{
					model_data[unit_game_started] = 1;
					if (model->get_current_layer() == 1)
					{
						if (units[current_game_x][current_game_y]->get_winner() != static_cast<int>(Winner::draw))
						{
							model_data[winner_in_last_game] = units[current_game_x][current_game_y]->get_winner();
						}
					}
					else if (model->get_current_layer() >= 2)
					{
						if (grids[current_game_x][current_game_y]->get_winner() != static_cast<int>(Winner::draw))
						{
							model_data[winner_in_last_game] = grids[current_game_x][current_game_y]->get_winner();
						}
					}
					current_game_x = i;
					current_game_y = j;
				}
			}

			this->window.draw(cell_playing_grid[i][j].get_sf_shape());

		}
	}
}

int GridController::launch(sf::RenderWindow& window, sf::Event& event, sf::Vector2i& mouse_position)
{
	int unit_game_started = (model->get_model_data())[Model_data::unit_game_started];
	if (!unit_game_started)
	{
		cell_pressed(window, event, mouse_position);
	}
	else
	{
		play(event, mouse_position);
	}

	return 0;
}