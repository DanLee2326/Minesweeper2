#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Cell.h"
#include "NumCell.h"
#include "CoverCell.h"

using std::vector;

class Board
{
public:
	Board(int dimension, std::string type);
	~Board();

	int getLength() const;
	Cell* getCell(int xIndex, int yIndex) const;

	void setNewCell(int xIndex, int yIndex, Cell* newCell);

private:
	vector<vector<Cell*>> cellData;
};

