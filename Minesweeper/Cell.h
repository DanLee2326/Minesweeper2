#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Cell : public sf::RectangleShape {

public:
	Cell(int posX, int posY, int sizeX, int sizeY) : sf::RectangleShape(sf::Vector2f(sizeX, sizeY)) {
	
		this->setPosition(posX, posY);
	
	};

	virtual void display(sf::RenderWindow& window) = 0;

protected:
	sf::Texture texture;

};

