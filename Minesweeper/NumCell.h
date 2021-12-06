#pragma once
#include "Cell.h"

class NumCell : public Cell {

public:
	NumCell(int posX, int posY, int sizeX, int sizeY) : Cell(posX, posY, sizeX, sizeY), value(0) {
	
		texture.loadFromFile("0.png");
		this->setTexture(&texture);
	
	}

	int getValue() const;
	void setValue(int newValue);
	void display(sf::RenderWindow& window);

private:
	int value; //-1 is mine, 0 is blank, 1-8 are how many adjacent mines

};

