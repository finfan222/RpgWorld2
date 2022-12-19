#include "GameSys.h"

int main()
{
    conf::RESOLUTION = conf::Resolution::_1024;
    sf::RenderWindow window(sf::VideoMode(GetResWidth(), GetResHeight()), "SFML works!");
    conf::RESOLUTION = conf::Resolution::_1900;
    sf::RenderWindow window2(sf::VideoMode(GetResWidth(), GetResHeight()), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    logging::warn(1, "xxxx");
    logging::info(1, "xxxx");
    logging::err(1, "xxxx");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}