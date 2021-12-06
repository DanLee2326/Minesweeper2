#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Timer
{
public:
    Timer()
    {
        font.loadFromFile("arial.ttf");
        const unsigned int seconds = static_cast<unsigned int>(clock.getElapsedTime().asSeconds());
        std::string time = std::to_string(seconds);

        text.setFont(font);
        text.setString(time);
        text.setColor(sf::Color::White);
        text.setCharacterSize(20);
        text.setPosition(0.f, 0.f);
    }

private:
    sf::Clock clock;
    sf::Text text;
    sf::Font font;
};

