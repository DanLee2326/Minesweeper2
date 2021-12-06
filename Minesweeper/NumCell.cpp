#include "NumCell.h"

int NumCell::getValue() const {

	return value;

}
void NumCell::setValue(int newValue) {

	value = newValue;
	switch (value) {

	case -1:
		texture.loadFromFile("mine.png");
		break;
	case 0:
		texture.loadFromFile("0.png");
		break;
	case 1:
		texture.loadFromFile("1.png");
		break;
	case 2:
		texture.loadFromFile("2.png");
		break;
	case 3:
		texture.loadFromFile("3.png");
		break;
	case 4:
		texture.loadFromFile("4.png");
		break;
	case 5:
		texture.loadFromFile("5.png");
		break;
	case 6:
		texture.loadFromFile("6.png");
		break;
	case 7:
		texture.loadFromFile("7.png");
		break;
	case 8:
		texture.loadFromFile("8.png");
		break;

	}
	setTexture(&texture);
}
void NumCell::display(sf::RenderWindow& window) {

	window.draw(*this);

}
