#include "backgroud_game.h"


Backgroung_game::Backgroung_game(sf::RenderWindow &window, sf::Texture *left, sf::Texture *middle, sf::Texture *right, int pozX, int pozY, int scale)
{
    this->left_sprite.setTexture(*left);
    this->middle_sprite1.setTexture(*middle);
    this->middle_sprite1.setScale(scale, 1);
    this->right_sprite.setTexture(*right);
    this->middle_sprite1.setPosition(pozX - middle_sprite1.getGlobalBounds().width/2, pozY - middle_sprite1.getGlobalBounds().height/2);
    this->left_sprite.setPosition(middle_sprite1.getPosition().x - left_sprite.getGlobalBounds().width, middle_sprite1.getPosition().y);
    this->right_sprite.setPosition(middle_sprite1.getPosition().x + middle_sprite1.getGlobalBounds().width, left_sprite.getPosition().y);
}

Backgroung_game::Backgroung_game(sf::RenderWindow &window, sf::Texture *connector, int pozX, int pozY, int rotation)
{
    this->connector_sprite.setTexture(*connector);
    if(rotation == 0)
        {
            this->connector_sprite.setPosition(pozX - connector_sprite.getGlobalBounds().width/2, pozY );
        }
    else
        {
            this->connector_sprite.setPosition(pozX , pozY - connector_sprite.getGlobalBounds().width/2);
            this->connector_sprite.setRotation(rotation);
        }
}

Backgroung_game::Backgroung_game(sf::Texture *corner, int rotation, int pozX, int pozY)
{
    this->corner_sprite.setTexture(*corner);
    this->corner_sprite.setPosition(pozX , pozY);
    this->corner_sprite.setRotation(rotation);
}

Backgroung_game::Backgroung_game(sf::Texture *quad, int pozX, int pozY)
{
    this->quad_sprite.setTexture(*quad);
    this->quad_sprite.setPosition(pozX, pozY + 37 - quad_sprite.getGlobalBounds().height/2);
}

Backgroung_game::Backgroung_game(sf::Texture *square, int pozX, int pozY, int rotation, sf::RenderWindow &window)
{
    this->square_sprite.setTexture(*square);
    this->square_sprite.setPosition(pozX, pozY);
    this->square_sprite.setRotation(rotation);
    this->square_sprite.setColor(sf::Color(255, 255, 255, 222));
}

Backgroung_game::~Backgroung_game(){}

int Backgroung_game::posX_middle(sf::RenderWindow &window)
{
    return middle_sprite1.getPosition().x;
}

int Backgroung_game::global_X_middle(sf::RenderWindow &window)
{
    return middle_sprite1.getGlobalBounds().width;
}

int Backgroung_game::posY_middle(sf::RenderWindow &window)
{
    return middle_sprite1.getPosition().y;
}

int Backgroung_game::global_Y_middle(sf::RenderWindow &window)
{
    return middle_sprite1.getGlobalBounds().height;
}

void Backgroung_game::draw_backgroud_game(sf::RenderWindow &window)
{
    window.draw(left_sprite);
    window.draw(middle_sprite1);
    window.draw(right_sprite);
}

void Backgroung_game::draw_backgroud_connector(sf::RenderWindow &window)
{
    window.draw(connector_sprite);
}

void Backgroung_game::draw_backgroud_corners(sf::RenderWindow &window)
{
    window.draw(corner_sprite);

}
void Backgroung_game::draw_backgroud_quads(sf::RenderWindow &window)
{
    window.draw(quad_sprite);
}

void Backgroung_game::draw_backgroud_square(sf::RenderWindow &window)
{
    window.draw(square_sprite);
}
