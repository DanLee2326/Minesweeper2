#include "Menu.h"

Menu::Menu(float posX, float posY)
{
	if (!style.loadFromFile("arial.ttf"))
	{
		std::cout << "Load Error!" << std::endl;
	}

	texture.loadFromFile("background (1).png");

	whichScreen = 0;

	for (int i = 0; i < 8; i++) 
	{
		options[i].setFont(style);
		options[i].setColor(sf::Color::White);
		options[i].setCharacterSize(25);
		options[i].setStyle(sf::Text::Style::Bold);

		switch (i) 
		{
		case 0:
			options[i].setString("Play");
			options[i].setPosition(posX / 2.5, posY * 0.5);
			boxes[i].setSize(sf::Vector2f(60, 30));
			boxes[i].setPosition(posX / 2.5, posY * 0.5);
			break;
		case 1:
			options[i].setString("Scoreboard");
			options[i].setPosition(posX / 2.5, posY * 0.6);
			boxes[i].setSize(sf::Vector2f(165, 30));
			boxes[i].setPosition(posX / 2.5, posY * 0.6);
			break;
		case 2:
			options[i].setString("Exit");
			options[i].setPosition(posX / 2.5, posY * 0.7);
			boxes[i].setSize(sf::Vector2f(60, 30));
			boxes[i].setPosition(posX / 2.5, posY * 0.7);
			break;
		case 3:
			options[i].setString("9x9");
			options[i].setPosition(posX * 0.20, posY * 0.45);
			boxes[i].setSize(sf::Vector2f(50, 30));
			boxes[i].setPosition(posX * 0.20, posY * 0.45);
			break;
		case 4:
			options[i].setString("16x16");
			options[i].setPosition(posX * 0.425, posY * 0.45);
			boxes[i].setSize(sf::Vector2f(85, 30));
			boxes[i].setPosition(posX * 0.425, posY * 0.45);
			break;
		case 5:
			options[i].setString("24x24");
			options[i].setPosition(posX * 0.675, posY * 0.45);
			boxes[i].setSize(sf::Vector2f(85, 30));
			boxes[i].setPosition(posX * 0.675, posY * 0.45);
			break;
		case 6:
			options[i].setString("Back");
			options[i].setPosition(5, 5);
			boxes[i].setSize(sf::Vector2f(60, 30));
			boxes[i].setPosition(5, 5);
			break;
		case 7:
			options[i].setString("Back");
			options[i].setPosition(5, 5);
			boxes[i].setSize(sf::Vector2f(60, 30));
			boxes[i].setPosition(5, 5);
			break;
		}
	}
}

void Menu::testMouse(int mouseX, int mouseY, bool onMenu, int preset, sf::RenderWindow& window)
{
	bool clickedOnBox = false;
	int whichBox = 0;

	for (int i = 0; i < 8; i++) 
	{
		if (mouseX > boxes[i].getPosition().x &&
			mouseX < boxes[i].getPosition().x + boxes[i].getSize().x &&
			mouseY > boxes[i].getPosition().y &&
			mouseY < boxes[i].getPosition().y + boxes[i].getSize().y) 
		{ 
			
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //activated
			{
				clickedOnBox = true;
				whichBox = i;
				if (i == 6 && whichScreen == 1) 
				{

					break;

				}
				if (i == 7 && whichScreen == 2) 
				{

					break;

				}
			}
			else //glow up
			{
				options[i].setCharacterSize(30);
				options[i].setColor(sf::Color::Blue);
			}
		}
		else //normal
		{
			
			options[i].setCharacterSize(25);
			options[i].setColor(sf::Color::Black);
			
			/*if (i < 6)
			{
				options[i].setCharacterSize(25);
				options[i].setColor(sf::Color::Black);
				
			}
			if (i == 6 || i == 7)
			{
				options[i].setCharacterSize(25);
				options[i].setColor(sf::Color::White);
			}*/
			
		}
	}

	if (clickedOnBox) 
	{
		switch (whichBox) 
		{
		case 0:
			//enter presets
			if (whichScreen == 0) 
			{
				whichScreen = 1;
			}
			break;
		case 1:
			//enter scoreboard
			if (whichScreen == 0) 
			{
				whichScreen = 2;
			}
			break;
		case 2:
			//close window
			if (whichScreen == 0)
			{
				window.close();
			}
			break;
		case 3:
			//start the game with 9x9 preset
			if (whichScreen == 1)
			{
				whichScreen = 3;
			}
			preset = 1;
			onMenu = false;
			break;
		case 4:
			//start with 16x16
			if (whichScreen == 1)
			{
				whichScreen = 4;
			}
			preset = 2;
			onMenu = false;
			break;
		case 5:
			//start with 24x24
			if (whichScreen == 1)
			{
				whichScreen = 5;
			}
			preset = 3;
			onMenu = false;
			break;
		case 6:
			//go back to main menu
			if (whichScreen == 1) 
			{
				whichScreen = 0;
			}
			break;
		case 7:
			//go back from scoreboard
			if (whichScreen == 2)
			{
				whichScreen = 0;
			}
			break;
		}
	}
}

void Menu::display(sf::RenderWindow& window)
{
	sf::Sprite background(texture);
	sf::Text j;
	j.setFont(style);
	j.setFillColor(sf::Color::White);
	j.setCharacterSize(50);
	j.setStyle(sf::Text::Style::Bold);

	if (whichScreen == 0) 
	{
		window.draw(background);
		j.setString("Minesweeper");
		j.setPosition(135, 150);
		j.setOutlineColor(sf::Color::Black);
		j.setOutlineThickness(2);
		window.draw(j);
		for (int i = 0; i < 3; i++)
		{
			
			window.draw(options[i]);
		}
	}
	else if (whichScreen == 1) 
	{
		window.draw(background);
		j.setString("Select the board size:");
		j.setPosition(110, 150);
		j.setCharacterSize(35);
		j.setOutlineColor(sf::Color::Black);
		j.setOutlineThickness(2);
		window.draw(j);
		for (int i = 3; i < 7; i++)
		{
			
			window.draw(options[i]);
		}

	}
	else if (whichScreen == 2)
	{
		window.draw(background);
		window.draw(options[7]);

		j.setCharacterSize(35);
		
		j.setString("Highscores");
		j.setPosition(193, 55);
		j.setOutlineColor(sf::Color::Black);
		j.setOutlineThickness(2);
		window.draw(j);
		j.setString("---------------------------------");
		j.setPosition(85, 85);
		j.setOutlineColor(sf::Color::Black);
		j.setOutlineThickness(2);
		window.draw(j);

		j.setCharacterSize(25);

		vector<int> a = scores.getScores9();
		j.setFillColor(sf::Color::Black);
		j.setString("9x9");
		j.setPosition(96, 125);
		j.setOutlineThickness(0);
		window.draw(j);

		for (int i = 0; i < a.size(); i++)
		{
			j.setString(std::to_string(a.at(i)));
			j.setPosition(101, 175 + (40 * i));
			j.setFillColor(sf::Color::Red);
			window.draw(j);
		}

		a = scores.getScores16();
		j.setFillColor(sf::Color::Black);
		j.setString("16x16");
		j.setPosition(238, 125);
		window.draw(j);

		for (int i = 0; i < a.size(); i++)
		{
			j.setString(std::to_string(a.at(i)));
			j.setPosition(258, 175 + (40 * i));
			j.setFillColor(sf::Color::Cyan);
			window.draw(j);
		}

		a = scores.getScores24();
		j.setFillColor(sf::Color::Black);
		j.setString("24x24");
		j.setPosition(400, 125);
		window.draw(j);

		for (int i = 0; i < a.size(); i++)
		{
			j.setString(std::to_string(a.at(i)));
			j.setPosition(420, 175 + (40 * i));
			j.setFillColor(sf::Color::Green);
			window.draw(j);
		}
	}
}

void Menu::addScore2(int newScore, int boardType)
{
	scores.addScore(newScore, boardType);
}