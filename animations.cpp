#include "animations.h"



Animations::Animations(sf::RenderWindow &window, sf::Texture *texture, int pozX, int pozY, int color = 1)
{
    this->pozX = pozX;
    this->pozY = pozY;
    this->scale_x = 0;
    this->scale_y = 0;

    if(color == 1) //blue
        {
            animation_color.r = 0;
            animation_color.g = 128;
            animation_color.b = 255;
            animation_color.a = 255;
        }

    if(color == 2) //yellow
        {
            animation_color.r = 255;
            animation_color.g = 255;
            animation_color.b = 0;
            animation_color.a = 255;
        }

    if(color == 3) //red
        {
            animation_color.r = 255;
            animation_color.g = 55;
            animation_color.b = 0;
            animation_color.a = 255;
        }

    if(color == 4) //grey
        {
            animation_color.r = 255;
            animation_color.g = 255;
            animation_color.b = 255;
            animation_color.a = 255;
        }

    if(color == 5) //green
        {
            animation_color.r = 0;
            animation_color.g = 255;
            animation_color.b = 0;
            animation_color.a = 255;
        }

    this->animation_die.setColor(sf::Color(animation_color));
    this->animation_die.setTexture(*texture);
    this->animation_die.setScale(scale_x, scale_y);
    this->animation_die.setPosition(pozX - animation_die.getGlobalBounds().width/2, pozY - animation_die.getGlobalBounds().width/2);
}

Animations::~Animations(){}

int Animations::animation_fire(sf::RenderWindow &window)
{
    this->animation_color.a = animation_color.a - 7;
    this->scale_x = scale_x + 0.03;
    this->scale_y = scale_y + 0.03;
    this->animation_die.setScale(scale_x, scale_y);
    this->animation_die.setPosition(pozX - (100 * scale_x/2), pozY - (100 * scale_y/2));

    if(animation_color.a <= 0)
        {
            animation_color.a = 0;
            return 1;
        }
    this->animation_die.setColor(sf::Color(animation_color));

    if(scale_x >= 1.0)
        {
            this->animation_die.setScale(1, 1);
            return 1;
        }
    return 0;

}

void Animations::draw_animation_death(sf::RenderWindow &window)
{
    window.draw(animation_die);
}
