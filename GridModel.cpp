#include "GridModel.h"

void GridModel::set_current_layer(int layer)
{
	this->layer = layer;
}

int GridModel::get_current_layer()
{
	return layer;
}

std::array<float, 4>& GridModel::get_cell_values()
{
	return cell_values;
}

std::array<int, 8>& GridModel::get_model_data()
{
	return model_data;
}

std::array<int, 8 >& GridModel::get_triplet_sum()
{
	return triplet_sum;
}

std::array<std::array<int, 3>, 3>& GridModel::get_playing_grid()
{
	return playing_grid;
}

std::array<std::array<Cell,3>,3>& GridModel::get_cell_playing_grid()
{
	return cell_playing_grid;
}

std::array<std::array<TTTUnit*, 3>, 3>& GridModel::get_units()
{
	return units;
}

std::array<std::array<GridController*, 3>, 3>& GridModel::get_grids()
{
	return grids;
}
