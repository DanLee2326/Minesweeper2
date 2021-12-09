#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using std::vector;
using std::string;

class Scores
{
public:
	Scores();

	void addScore(int newScore, int boardType);
	void read(int boardType);
	void writeFile(int boardType);

	vector<int> getScores9() const;
	vector<int> getScores16() const;
	vector<int> getScores24() const;

private:
	vector<int> List9;
	vector<int> List16;
	vector<int> List24;
	int score;
	std::fstream infile1;
	std::fstream infile2;
	std::fstream infile3;
};

