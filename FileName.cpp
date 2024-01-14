#include <SFML/Graphics.hpp>

int main() {
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode(800, 460), "Svetoch");
    // Загружаем текстуры
    sf::Texture texture1, texture2, texture3;
    texture1.loadFromFile("image1.jpg");
    texture2.loadFromFile("image2.jpg");
    texture3.loadFromFile("image3.jpg");
    // Создаем спрайты для отображения текстур
    sf::Sprite sprite(texture1);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            // Обработка нажатий клавиш
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num1)  // Клавиша "1"
                    sprite.setTexture(texture1);
                else if (event.key.code == sf::Keyboard::Num2)  // Клавиша "2"
                    sprite.setTexture(texture2);
                else if (event.key.code == sf::Keyboard::Num3)  // Клавиша "3"
                    sprite.setTexture(texture3);
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
