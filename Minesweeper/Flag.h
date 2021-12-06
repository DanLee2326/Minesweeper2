#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Flag : public sf::RectangleShape
{
public:
	Flag(int posX, int posY, int sizeX, int sizeY, int newCellPosX,
		int newCellPosY) : sf::RectangleShape(sf::Vector2f(sizeX, sizeY)),
		cellPosX(newCellPosX), cellPosY(newCellPosY)
	{
		this->setPosition(posX, posY);
		texture.loadFromFile("flag.png");
		this->setTexture(&texture);
	}

	int getPositionX() const;
	int getPositionY() const;
	void display(sf::RenderWindow& window);

private:
	sf::Texture texture;
	int cellPosX;
	int cellPosY;
};