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
	Scores()
	{
		read(1);
		read(2);
		read(3);
	}

	void addScore(int newScore, int boardType)
	{
		this->score = newScore;
		switch (boardType) {

		case 1:
			List9.clear();
			read(boardType);
			List9.push_back(newScore);
			std::sort(List9.begin(), List9.end());
			if (List9.size() > 10) {

				List9.pop_back();

			}
			writeFile(boardType);
			break;

		case 2:
			List16.clear();
			read(boardType);
			List16.push_back(newScore);
			std::sort(List16.begin(), List16.end());
			if (List16.size() > 10) {

				List16.pop_back();

			}
			writeFile(boardType);
			break;

		case 3:
			List24.clear();
			read(boardType);
			List24.push_back(newScore);
			std::sort(List24.begin(), List24.end());
			if (List24.size() > 10) {

				List24.pop_back();

			}
			writeFile(boardType);
			break;

		}
	}

	void read(int boardType)
	{
		char read[100];
		switch (boardType)
		{
		case 1:
			//read from file to vector
			infile1.open("9x9.txt", std::ios::in);
			infile1.getline(read, 100);
			while (infile1 >> score && !infile1.eof())
			{
				List9.push_back(score);
			}
			infile1.close();
			break;
		case 2:
			infile2.open("16x16.txt", std::ios::in);
			infile2.getline(read, 100);
			while (infile2 >> score && !infile2.eof())
			{
				List16.push_back(score);
			}
			infile2.close();
			break;
		case 3:
			infile3.open("24x24.txt", std::ios::in);
			infile3.getline(read, 100);
			while (infile3 >> score && !infile3.eof())
			{
				List24.push_back(score);
			}
			infile3.close();
			break;
		}
	}

	void writeFile(int boardType)
	{
		switch (boardType)
		{
		case 1:
			//write from vector to file
			infile1.open("9x9.txt", std::ios::out);
			infile1 << "***9x9***" << std::endl;
			for (int i = 0; i < List9.size(); i++)
			{
				infile1 << List9[i] << std::endl;
			}
			infile1.close();
			break;
		case 2:
			infile2.open("16x16.txt", std::ios::out);
			infile2 << "***16x16***" << std::endl;
			for (int i = 0; i < List16.size(); i++)
			{
				infile2 << List16[i] << std::endl;
			}
			infile2.close();
			break;
		case 3:
			infile3.open("24x24.txt", std::ios::out);
			infile3 << "***24x24***" << std::endl;
			for (int i = 0; i < List24.size(); i++)
			{
				infile3 << List24[i] << std::endl;
			}
			infile3.close();
			break;
		}
		
	}

	vector<int> getScores9() const
	{
		return this->List9;
	}
	vector<int> getScores16() const
	{
		return this->List16;
	}
	vector<int> getScores24() const
	{
		return this->List24;
	}

private:
	vector<int> List9;
	vector<int> List16;
	vector<int> List24;
	int score;
	std::fstream infile1;
	std::fstream infile2;
	std::fstream infile3;
};

