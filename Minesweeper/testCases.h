#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;
using std::string;

class testCases
{
public:
	void testFileSize();
	void testWinCondition();
	void testLoseCondition();
	void testRandomMines();
	void testNeighborCells();
};
