#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu : public sf::RectangleShape
{
public:
	Menu(float posX, float posY);

	void testMouse(int mouseX, int mouseY, bool onMenu, int preset);
	void display(sf::RenderWindow& window);

private:
	sf::Text options[8];
	sf::Font style;
	sf::RectangleShape boxes[8];

	int whichScreen;
};