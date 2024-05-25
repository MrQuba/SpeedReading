#include <SFML/Graphics.hpp>
#include "Data.hpp"
#pragma once
	class Window {
	public:
		sf::RenderWindow window;
		Window(sf::Vector2i Size, const char* Title, int framerate, sfml::Style style) {
			window.create(sfml::VideoMode(Size).get(), Title, style);
			window.setFramerateLimit(framerate);
		}
	};