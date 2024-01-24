#pragma once
class Grid
{
private:
	TTTUnit* a;
	Grid* b;
	// layer > 2 = i -> b(i-1)
	// layer = 2 -> this.launch()
	// layer = 1 -> a.play();
	int playing_grid[3][3]{};
	int triplet_sum[8]{};
	int winner{};
	int layer{};
	void setMainLayer(int);
	void sumTriplet();
	bool endGameCheck();

public:
	Grid(int);
	~Grid();
	int launch(sf::RenderWindow&, sf::Event&, sf::Vector2i&);
};