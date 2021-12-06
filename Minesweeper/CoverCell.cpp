#include "CoverCell.h"

bool CoverCell::getCovered() const {

	return isCovered;

}
void CoverCell::uncover() {

	isCovered = false;
	this->setFillColor(sf::Color::Transparent);
	this->setTexture(nullptr);

}
void CoverCell::display(sf::RenderWindow& window) {

	window.draw(*this);

}
