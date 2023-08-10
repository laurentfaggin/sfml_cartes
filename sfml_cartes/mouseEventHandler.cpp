#include "MouseEventHandler.h"
#include <iostream>

void MouseEventHandler::MouseEvent(const sf::Event& event, const sf::RenderWindow& window) {
    switch (event.type) {
    case sf::Event::MouseButtonPressed:
        mouseButtonPressed(event.mouseButton, window);
        break;
    case sf::Event::MouseButtonReleased:
        mouseButtonReleased(event.mouseButton);
        break;
    }
}

void MouseEventHandler::mouseButtonPressed(const sf::Event::MouseButtonEvent& event, const sf::RenderWindow& window) {
    if (event.button == sf::Mouse::Left) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        std::cout << "position clic gauche de la souris: x = " << mousePosition.x << ", y = " << mousePosition.y << std::endl;
    }
}

void MouseEventHandler::mouseButtonReleased(const sf::Event::MouseButtonEvent& event) {
    if (event.button == sf::Mouse::Left) {
        std::cout << "click gauche relache." << std::endl;
    }
}
