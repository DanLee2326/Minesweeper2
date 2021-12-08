#pragma once

#include "Cell.h"

class CoverCell : public Cell {

public:
	CoverCell(int posX, int posY, int sizeX, int sizeY) : Cell(posX, posY, sizeX, sizeY), 
		isCovered(true) {

		texture.loadFromFile("cover.png");
		this->setTexture(&texture);

	}

	bool getCovered() const;
	void uncover();
	void display(sf::RenderWindow& window);

private:
	bool isCovered;

};

