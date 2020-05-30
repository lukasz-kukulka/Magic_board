#include "lifes.h"



Lifes::Lifes(sf::RenderWindow &window, sf::Texture *texture, int posX, int posY, int repeat_x, int repeat_y)
{
    this->life_yes_no = life_yes_no;
    this->life_sprite.setScale(window.getSize().x/1600.0, window.getSize().x/1600.0);
    this->life_sprite.setTexture(*texture);
    this->life_sprite.setPosition(posX+ (life_sprite.getGlobalBounds().width + 2) * repeat_x, posY - life_sprite.getGlobalBounds().height + (life_sprite.getGlobalBounds().height * repeat_y));
}

Lifes::~Lifes(){}

void Lifes::life_change(sf::RenderWindow &window, bool life_yes_no)
{
    if(life_yes_no == true)
        {
            this->life_sprite.setScale(window.getSize().x/1600.0, window.getSize().x/1600.0);
        }

    else
        {
            this->life_sprite.setScale(0, 0);
        }
}

int Lifes::life_check(sf::RenderWindow &window)
{
    return life_yes_no;
}

void Lifes::draw_life(sf::RenderWindow &window)
{
    window.draw(life_sprite);
}
