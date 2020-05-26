#include "shooting.h"



Shooting::Shooting(sf::RenderWindow &window, sf::Texture *texture, int pozX, int pozY)
{
    this->single_shot.setTexture(*texture);
    this->single_shot.setPosition(pozX, pozY);
}

Shooting::~Shooting(){}

void Shooting::bullet_move(sf::RenderWindow &window)
{
    this->single_shot.move(0, -20);
}

int Shooting::shot_pos_x(sf::RenderWindow &window)
{
    return single_shot.getPosition().x;
}

int Shooting::shot_pos_y(sf::RenderWindow &window)
{
    return single_shot.getPosition().y;
}

int Shooting::shot_global_x(sf::RenderWindow &window)
{
    return single_shot.getGlobalBounds().width;
}

void Shooting::draw_shot(sf::RenderWindow &window)
{
    window.draw(single_shot);
}
