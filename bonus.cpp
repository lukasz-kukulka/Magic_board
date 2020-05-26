#include "bonus.h"



Bonus::Bonus(sf::RenderWindow &window, sf::Texture *texture, int posX, int posY, int speed, int random)
{
    this->speed = speed;
    this->random = random;
    this->bonus_sprite.setScale(0.6, 0.6);
    this->bonus_sprite.setTexture(*texture);
    this->bonus_sprite.setPosition(posX, posY);
}

Bonus::Bonus(sf::RenderWindow &window, sf::Texture *texture, int repeat, int pozX, int pozY, float scale)
{
    this->wall_sprite.setTexture(*texture);
    this->wall_sprite.setScale(scale, scale);
    this->wall_sprite.setPosition(pozX + wall_sprite.getGlobalBounds().width * repeat, pozY);
}


Bonus::~Bonus(){}

int Bonus::random_bonus(sf::RenderWindow &window)
{
    return random;
}

int Bonus::wall_global_x(sf::RenderWindow &window)
{
    return wall_sprite.getGlobalBounds().width;
}

int Bonus::wall_position_x(sf::RenderWindow &window)
{
    return wall_sprite.getPosition().x;
}

int Bonus::wall_position_y(sf::RenderWindow &window)
{
    return wall_sprite.getPosition().y;
}

void Bonus::move_bonus(sf::RenderWindow &window)
{
    this->bonus_sprite.setPosition(bonus_sprite.getPosition().x, bonus_sprite.getPosition().y + (1 * speed));
}

int Bonus::posX_bonus(sf::RenderWindow &window)
{
    return bonus_sprite.getPosition().x;
}

int Bonus::posY_bonus(sf::RenderWindow &window)
{
    return bonus_sprite.getPosition().y;
}

int Bonus::global_x_bonus(sf::RenderWindow &window)
{
    return bonus_sprite.getGlobalBounds().width;
}

int Bonus::global_y_bonus(sf::RenderWindow &window)
{
    return bonus_sprite.getGlobalBounds().height;
}

void Bonus::draw_bonus(sf::RenderWindow &window)
{
    window.draw(bonus_sprite);
    window.draw(wall_sprite);
}
