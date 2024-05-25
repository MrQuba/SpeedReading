#include <SFML/Graphics.hpp>
#pragma once
class Event {
public:
    sf::Event event;
    void Loop(sf::RenderWindow& window) {
        switch (window.pollEvent(event)) {
        case sf::Event::Closed:
            //window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            break;
        }
    }

};