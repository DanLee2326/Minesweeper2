#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Scores.h"

class Menu : public sf::RectangleShape
{
public:
	Menu(float posX, float posY);

	void testMouse(int mouseX, int mouseY, bool onMenu, int preset, sf::RenderWindow& window);
	void display(sf::RenderWindow& window);
	void addScore2(int newScore, int boardType);

private:
	sf::Text options[8];
	sf::Font style;
	sf::RectangleShape boxes[8];
	sf::Texture texture;

	int whichScreen;
	Scores scores;
};