#include "text_ini.h"

Text_ini::Text_ini(sf::RenderWindow &window, sf::Font *font, std::string string_text, int line)
{
    this->color_a = 200;
    this->color_r = 255;
    this->color_g = 255;
    this->color_b = 0;
    this->text.setFont(*font);
    this->text.setCharacterSize(window.getSize().x/27);
    this->text.setStyle(sf::Text::Bold);
    this->text.setFillColor(sf::Color(color_r, color_g, color_b, color_a));
    this->text.setOutlineColor(sf::Color(0, 0, 0, color_a));
    this->text.setOutlineThickness(1);
    this->text.setString(string_text);
    this->text.setPosition(window.getSize().x/2 - text.getGlobalBounds().width/2, window.getSize().y/3 + (text.getGlobalBounds().height + text.getGlobalBounds().height * (line+1)));
}

Text_ini::Text_ini(sf::RenderWindow &window, sf::Font *font, std::string string_points, std::string text_score, int posX, int posY)
{
    this->string_points = string_points;
    this->text_point.setFont(*font);
    this->text_point.setCharacterSize(window.getSize().x/60);
    this->text_point.setFillColor(sf::Color(255, 255, 255, 255));
    this->text_point.setOutlineColor(sf::Color(0, 0, 0, 255));
    this->text_point.setOutlineThickness(1);
    this->text_point.setString(text_score);
    this->text_point.setPosition(posX - text_point.getGlobalBounds().width/2, posY - 2 - text_point.getGlobalBounds().height*2);

    this->score.setFont(*font);
    this->score.setCharacterSize(window.getSize().x/40);
    this->score.setStyle(sf::Text::Bold);
    this->score.setFillColor(sf::Color(255, 255, 255, 255));
    this->score.setOutlineColor(sf::Color(0, 0, 0, 255));
    this->score.setOutlineThickness(1);
    this->score.setString(string_points);
    this->score.setPosition(posX - score.getGlobalBounds().width/2, posY - score.getGlobalBounds().height/2);
}

Text_ini::~Text_ini(){}


int Text_ini::animation_text(sf::RenderWindow &window)
{
    this->color_a = color_a - 1;
    this->text.setFillColor(sf::Color(color_r, color_g, color_b, color_a));
    this->text.setOutlineColor(sf::Color(0, 0, 0, color_a));
    return this->color_a;
}

void Text_ini::points_update(sf::RenderWindow &window, int points)
{
    string_points  = std::to_string(points);
    while(string_points.size() < 8)
        {
            string_points = "0" + string_points;
        }

    this->score.setString(string_points);
}

int Text_ini::posX(sf::RenderWindow &window)
{
    return score.getPosition().x;
}

void Text_ini::move_up(sf::RenderWindow &window)
{
    text.setPosition(text.getPosition().x, text.getPosition().y - text.getGlobalBounds().height);
}

int Text_ini::posY(sf::RenderWindow &window)
{
    return score.getPosition().y;
}

void Text_ini::draw_text(sf::RenderWindow &window)
{
    window.draw(text);
    window.draw(text_point);
    window.draw(score);
}
