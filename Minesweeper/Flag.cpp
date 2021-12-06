#include "Flag.h"

int Flag::getPositionX() const
{
	return this->cellPosX;
}

int Flag::getPositionY() const
{
	return this->cellPosY;
}

void Flag::display(sf::RenderWindow& window) {

	window.draw(*this);
}