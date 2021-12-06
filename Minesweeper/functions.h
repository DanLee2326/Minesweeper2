#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <Windows.h>

#include "Cell.h"
#include "CoverCell.h"
#include "NumCell.h"
#include "Board.h"
#include "Flag.h"

using std::endl;
using std::cout;
using std::vector;

void placeRandomMines(int amount, Board& board, int originX, int originY);
void placeNeighbors(Board& board);
void uncoverEmpty(Board& numBoard, Board& coverBoard, int x, int y);
void lose(Board& numBoard, Board& coverBoard);
void reset(Board& numBoard, Board& coverBoard, int cellWidth, int cellHeight);
bool flagAtCell(int cellX, int cellY, vector<Flag*> &flags);