#include "GridView.h"

void GridView::clear_window(sf::RenderWindow& window, sf::Color = sf::Color(25, 25, 25))
{
	window.clear();
}

void GridView::draw_cell(sf::RenderWindow&  window, Cell* cell)
{
	window.draw(cell->get_sf_shape());
	/*window.display();*/
}
