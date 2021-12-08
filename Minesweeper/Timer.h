#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Timer : public sf::Text
{
public:
    Timer(int posX, int posY)
    {
        font.loadFromFile("arial.ttf");
        const unsigned int seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
        std::cout << clock.getElapsedTime().asSeconds() << std::endl;
        time = std::to_string(seconds);
        //std::cout << time << std::endl;

        this->setFont(font);
        this->setString(time);
        this->setColor(sf::Color::White);
        this->setCharacterSize(25);
        this->setPosition(posX / 2, 10);
    }

    std::string getScore() const
    {
        return this->time;
    }
    void display(sf::RenderWindow& window)
    {
        window.draw(*this);
    }

private:
    sf::Clock clock;
    sf::Font font;
    std::string time;
    //sf::Text text;
};

