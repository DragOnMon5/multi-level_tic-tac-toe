#include "GridView.h"

void GridView::draw_cell(sf::RenderWindow&  window, Cell* cell)
{
	window.draw(cell->get_sf_shape());
}
