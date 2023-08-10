#pragma once
#ifndef MOUSE_EVENT_HANDLER_H
#define MOUSE_EVENT_HANDLER_H

#include <SFML/Graphics.hpp>

class MouseEventHandler {
public:
	void MouseEvent(const sf::Event& event, const sf::RenderWindow& window);
private:
	void mouseButtonPressed(const sf::Event::MouseButtonEvent& event, const sf::RenderWindow& window);
	void mouseButtonReleased(const sf::Event::MouseButtonEvent& event);
};

#endif
