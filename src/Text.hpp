#include <SFML/Graphics.hpp>
#include "Data.hpp"
#pragma once

class Text {
public:
	Text(Path pathToFont) {
		font.loadFromFile(pathToFont.get());
		text.setFont(font);
		text.setCharacterSize(64);
		text.setFillColor(sf::Color::White);
	}
	void setText(std::string text) { this->text.setString(text); }
	void setOnMiddleOfWindow(sf::RenderWindow& window) {
		text.setPosition((window.getSize().x  - text.getLocalBounds().width)/ 2.f, (window.getSize().y - text.getLocalBounds().height) / 2.f);
	}
	sf::Text getText() { return this->text; }
private:
	sf::Text text;
	sf::Font font;
};
