#include "Board.h"

Board::Board(int dimension, std::string type)
{

	int cellWidth = 576 / dimension;
	int cellHeight = 576 / dimension;

	if (type == "number") {
		for (int i = 0; i < dimension /*newWidth*/; i++)
		{
			vector<Cell*> temp;
			for (int j = 0; j < dimension /*newHeight*/; j++)
			{
				Cell* tempCell = new NumCell(cellWidth * i, cellHeight * j + 50, cellWidth, cellHeight);
				temp.push_back(tempCell);
			}
			cellData.push_back(temp);
		}
	}
	else if (type == "cover") {

		for (int i = 0; i < dimension /*newWidth*/; i++)
		{
			vector<Cell*> temp;
			for (int j = 0; j < dimension /*newHeight*/; j++)
			{
				Cell* tempCell = new CoverCell(cellWidth * i, cellHeight * j + 50, cellWidth, cellHeight);
				temp.push_back(tempCell);
			}
			cellData.push_back(temp);
		}

	}
}

Board::~Board() {

	for (int i = 0; i < this->getLength(); i++) {

		for (int j = 0; j < this->getLength(); j++) {

			delete cellData.at(i).at(j);

		}
	}
	cellData.clear();
}

int Board::getLength() const 
{
	return this->cellData.size();
}

Cell* Board::getCell(int xIndex, int yIndex) const
{

	return cellData.at(xIndex).at(yIndex);

}

void Board::setNewCell(int xIndex, int yIndex, Cell* newCell) {

	delete this->cellData.at(xIndex).at(yIndex);
	this->cellData.at(xIndex).at(yIndex) = newCell;

}