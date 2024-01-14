#include <iostream>
#include <SFML/Graphics.hpp>


// draw(sf::RenderWindow&)
//на каждой итерации передать Event& event 
//и каждый объект будет провер€ть дл€ себ€.  ажетс€, что здесь что-то не так,
//но кардинально другого решени€ не знаю
class Button
{};
class Cell : public Button
{};