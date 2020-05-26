#include "credits.h"
#include <iostream>

Credits::Credits(sf::RenderWindow &window, sf::Font *font, std::string subtitles = "none", int text_size = 11, int distance = 100)
{
    this->text_size = window.getSize().x/text_size;
    space_betwen = space_betwen + distance;
    this->credits_text.setFont(*font);
    this->credits_text.setCharacterSize(window.getSize().x/text_size);
    this->credits_text.setFillColor(sf::Color(255, 255, 255));
    this->credits_text.setString(subtitles);
    this->credits_text.setOutlineThickness(2);
    this->credits_text.setOutlineColor(sf::Color(0, 0, 0));
    this->credits_text.setPosition(window.getSize().x/2 - credits_text.getGlobalBounds().width/2, window.getSize().y + space_betwen);
}

Credits::~Credits(){}

void Credits::move_text(sf::RenderWindow &window)
{
    credits_text.move(0, -1);
    if(credits_text.getPosition().y <= 0 - credits_text.getGlobalBounds().height*2 )
        {
            this->credits_text.setPosition(window.getSize().x/2 - credits_text.getGlobalBounds().width/2, space_betwen - credits_text.getGlobalBounds().height*2);
        }
}

void Credits::inaccessible(sf::RenderWindow &window, int index)
{
    if(index == 0)
        {
            this->credits_text.setCharacterSize(0);
            this->credits_text.setOutlineThickness(0);
        }

    else if(index == 1)
        {
            this->credits_text.setCharacterSize(text_size);
            this->credits_text.setOutlineThickness(2);
        }
}

void Credits::draw_credits(sf::RenderWindow &window)
{
    window.draw(credits_text);
}

