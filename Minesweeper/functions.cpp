#include "functions.h"

void placeRandomMines(int amount, Board& board, int originX, int originY) {

	srand(time(NULL));

	for (int i = 0; i < amount; i++) {

		bool repeat = true;
		while (repeat == true) {

			int mineX = rand() % board.getLength();
			int mineY = rand() % board.getLength();
			if ((dynamic_cast <NumCell*>(board.getCell(mineX, mineY)))->getValue() != -1 &&
                 sqrt((mineX - originX) * (mineX - originX) + (mineY - originY) * (mineY - originY)) > 2) {
			
				repeat = false;
				(dynamic_cast <NumCell*>(board.getCell(mineX, mineY)))->setValue(-1);
			
			}
		}
	}
}

void placeNeighbors(Board& board) {

    int neighbors[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };

    for (int i = 0; i < board.getLength(); i++) {
        for (int j = 0; j < board.getLength(); j++) {

            //if the current cell is not a mine, start the mine count
            int mineCount = 0;
            if ((dynamic_cast <NumCell*>(board.getCell(i, j)))->getValue() != -1) {

                //loop through the neighboring index array
                for (int k = 0; k < 8; k++) {

                    //tests to see if the current neighbor index is out of bounds to avoid errors
                    if (i + neighbors[k][0] >= 0 && i + neighbors[k][0] < board.getLength() &&
                        j + neighbors[k][1] >= 0 && j + neighbors[k][1] < board.getLength()) {
                        //if the neighbor is a mine, add to the mine count value
                        if ((dynamic_cast <NumCell*>(board.getCell(i + neighbors[k][0], j + neighbors[k][1])))->getValue() == -1) {

                            mineCount++;

                        }
                    }
                }
                (dynamic_cast <NumCell*>(board.getCell(i, j)))->setValue(mineCount);
            }
        }
    }
}

void uncoverEmpty(Board& numBoard, Board& coverBoard, int x, int y) {

    int neighbors[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} };
    for (int k = 0; k < 8; k++) {

        //tests to see if the current neighbor index is out of bounds to avoid errors
        if (x + neighbors[k][0] >= 0 && x + neighbors[k][0] < numBoard.getLength() &&
            y + neighbors[k][1] >= 0 && y + neighbors[k][1] < numBoard.getLength()) {

            //uncover the neighbor cell, and if the cell is empty recursively call this function again.
            if ((dynamic_cast <CoverCell*>(coverBoard.getCell(x + neighbors[k][0], y + neighbors[k][1])))->getCovered()) {

                (dynamic_cast <CoverCell*>(coverBoard.getCell(x + neighbors[k][0], y + neighbors[k][1])))->uncover();
                if ((dynamic_cast <NumCell*>(numBoard.getCell(x + neighbors[k][0], y + neighbors[k][1])))->getValue() == 0) {
                 
                    uncoverEmpty(numBoard, coverBoard, x + neighbors[k][0], y + neighbors[k][1]);
                }
            }
        }
    }
}

void lose(Board& numBoard, Board& coverBoard) {

    for (int i = 0; i < numBoard.getLength(); i++) {

        for (int j = 0; j < numBoard.getLength(); j++) {

            if ((dynamic_cast <NumCell*> (numBoard.getCell(i, j)))->getValue() == -1 &&
                (dynamic_cast <CoverCell*> (coverBoard.getCell(i, j)))->getCovered()) {

                (dynamic_cast <CoverCell*> (coverBoard.getCell(i, j)))->uncover();

            }
        }
    }
}

void reset(Board& numBoard, Board& coverBoard, int cellWidth, int cellHeight) {

    for (int i = 0; i < numBoard.getLength(); i++) {

        for (int j = 0; j < numBoard.getLength(); j++) {

            (dynamic_cast <NumCell*> (numBoard.getCell(i, j)))->setValue(0);
            Cell* newCover = new CoverCell(cellWidth * i, cellHeight * j + 50, cellWidth, cellHeight);
            coverBoard.setNewCell(i, j, newCover);

        }
    }
}

bool flagAtCell(int cellX, int cellY, vector<Flag*> &flags) {

    for (int i = 0; i < flags.size(); i++) {

        if (flags.at(i)->getPositionX() == cellX && flags.at(i)->getPositionY() == cellY) {

            return true;

        }
    }
    return false;
}