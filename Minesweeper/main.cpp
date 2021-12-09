#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Cell.h"
#include "CoverCell.h"
#include "NumCell.h"
#include "Board.h"
#include "functions.h"
#include "Flag.h"
#include "Menu.h"
#include "Timer.h"
#include "Scores.h"

#define EASY_MINES 10
#define EASY_SIZE 9
#define MEDIUM_MINES 40
#define MEDIUM_SIZE 16
#define HARD_MINES 100
#define HARD_SIZE 24

using std::endl;
using std::cout;

int main() 
{
	sf::RenderWindow window(sf::VideoMode(576, 626), "Minesweeper", sf::Style::Close);
    /*sf::RectangleShape titleBar(sf::Vector2f(720, 50));
    titleBar.setFillColor(sf::Color::Black);
    titleBar.setPosition(0, 0);*/

    Menu select(window.getSize().x, window.getSize().y);
    //select.addScore2(64, 1);

    //board size variable
    int preset = 1;
    int mineAmount;
    int boardSize;
    switch (preset) 
    {

    case 1:
        mineAmount = EASY_MINES;
        boardSize = EASY_SIZE;
        break;
    case 2:
        mineAmount = MEDIUM_MINES;
        boardSize = MEDIUM_SIZE;
        break;
    case 3:
        mineAmount = HARD_MINES;
        boardSize = HARD_SIZE;
        break;
    }

    int cellWidth = window.getSize().x / boardSize;
    int cellHeight = (window.getSize().y - 50) / boardSize;
    Board grid(boardSize, "number");
    Board coverGrid(boardSize, "cover");
    vector<Flag*> flags;

    bool clicked = false;
    bool lost = false;
   
    sf::Clock clock;
    sf::Text text;
    sf::Font font;

    bool onMenu = true;

    while (window.isOpen()) 
    {
        font.loadFromFile("arial.ttf");
        const unsigned int seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
        std::string time = std::to_string(seconds);
        text.setFont(font);
        text.setString(time);
        text.setColor(sf::Color::White);
        text.setCharacterSize(25);
        text.setPosition(window.getSize().x / 2, 10);

        //menu loop
        /*while (onMenu) {

            select.testMouse(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, onMenu, preset, window);
            select.display(window);
            if (onMenu == false) 
            {

                switch (preset) 
                {

                case 1:
                    mineAmount = EASY_MINES;
                    boardSize = EASY_SIZE;
                    break;
                case 2:
                    mineAmount = MEDIUM_MINES;
                    boardSize = MEDIUM_SIZE;
                    break;
                case 3:
                    mineAmount = HARD_MINES;
                    boardSize = HARD_SIZE;
                    break;
                }

                cellWidth = window.getSize().x / boardSize;
                cellHeight = (window.getSize().y - 50) / boardSize;

            }
        }*/

        if (lost) 
        {
            Sleep(5000);
            lost = false;
            clicked = false;
            reset(grid, coverGrid, cellWidth, cellHeight);
        }

        //checks for the window closed event
        sf::Event evnt;
        while (window.pollEvent(evnt)) 
        {
            switch (evnt.type) 
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:

                if (sf::Mouse::getPosition(window).x < window.getSize().x && sf::Mouse::getPosition(window).x > 0 &&
                    sf::Mouse::getPosition(window).y < window.getSize().y && sf::Mouse::getPosition(window).y > 50) 
                {
                    //finds the cell clicked
                    int cellX = sf::Mouse::getPosition(window).x / cellWidth;
                    int adjustedMouseY = sf::Mouse::getPosition(window).y - 50;
                    int cellY = adjustedMouseY / cellHeight;

                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
                    {
                        //first click setup, makes sure you always press an empty space
                        if (clicked == false) {

                            clicked = true;
                            placeRandomMines(mineAmount, grid, cellX, cellY);
                            placeNeighbors(grid);

                        }

                        //if the cell is covered and there isnt a flag, uncover the sell
                        if ((dynamic_cast <CoverCell*>(coverGrid.getCell(cellX, cellY)))->getCovered() &&
                            !flagAtCell(cellX, cellY, flags)) 
                        {
                            (dynamic_cast <CoverCell*>(coverGrid.getCell(cellX, cellY)))->uncover();
                            //if the cell is blank, run the recursion, if it's a mine, lose the game
                            if ((dynamic_cast <NumCell*>(grid.getCell(cellX, cellY)))->getValue() == 0) 
                            {
                                uncoverEmpty(grid, coverGrid, cellX, cellY);
                            }
                            else if ((dynamic_cast <NumCell*>(grid.getCell(cellX, cellY)))->getValue() == -1) 
                            {
                                lose(grid, coverGrid);
                                flags.clear();
                                lost = true;
                            }
                        }
                    }
                    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) 
                    {
                        //flag operations, cellX and cellY are the grid coordinates of the click
                        if ((dynamic_cast <CoverCell*>(coverGrid.getCell(cellX, cellY)))->getCovered() && clicked) 
                        {
                            //if there isnt a flag already at the cell, add one
                            if (!flagAtCell(cellX, cellY, flags)) 
                            {
                                flags.push_back(new Flag(cellX * cellWidth, cellY * cellHeight + 50, cellWidth, cellHeight, cellX, cellY));
                            }
                            //else, delete the flag already there
                            else 
                            {
                                for (int i = 0; i < flags.size(); i++) 
                                {
                                    if (flags.at(i)->getPositionX() == cellX && flags.at(i)->getPositionY() == cellY) 
                                    {
                                        delete flags.at(i);
                                        flags.erase(flags.begin() + i);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        //display everything
        window.clear();
        
        //window.draw(titleBar);
        /*for (int i = 0; i < boardSize; i++) 
        {

            for (int j = 0; j < boardSize; j++) 
            {

                grid.getCell(i, j)->display(window);
                coverGrid.getCell(i, j)->display(window);

            }
        }
        for (int i = 0; i < flags.size(); i++) 
        {

            flags.at(i)->display(window);

        }*/

        //window.draw(text);

        select.testMouse(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, onMenu, preset, window);
        select.display(window);

        window.display();
    }

	return 0;
}