#include "ball.h"


Ball::Ball(sf::RenderWindow &window, sf::Texture *texture)
{
    this->top_colision = ((window.getSize().y/2) % 32) + (70);
    this->left_colision = ((window.getSize().x/2) % 32) + (66);
    this->right_colision = window.getSize().x - ((window.getSize().x % 32) + (96));
    this->ball_main.setTexture(*texture);
    this->ball_main.setPosition(500, 500);
    this->colision_change_y = 1;
    this->colision_change_x = 1;
    this->radius_colision = 0;
}

Ball::~Ball(){}

void Ball::move_ball(sf::RenderWindow &window, float dir_X = 1, float dir_Y = -1, float speed = 1, float level = 1)
{
    ball_main.move(speed * dir_X * level, speed * dir_Y * level);
}

int Ball::colision_main_ball_y(sf::RenderWindow &window)
{
    if(ball_main.getPosition().y <= top_colision)
        {
            colision_change_y = colision_change_y * (-1);
            return colision_change_y;
        }
    else
        return colision_change_y;
}

int Ball::colision_main_ball_x(sf::RenderWindow &window)
{
    if(ball_main.getPosition().x <= left_colision || ball_main.getPosition().x >= right_colision)
        {
            colision_change_x = colision_change_x * (-1);
            return colision_change_x;
        }

    else
        return colision_change_x;
}

float Ball::colision_main_ball_board(sf::RenderWindow &window, float radius)
{
            colision_change_y = colision_change_y * (-1);
            return colision_change_y;
}

int Ball::colision_main_ball_board_x(sf::RenderWindow &window)
{
            colision_change_x = colision_change_x * (-1);
            return colision_change_x;
}

int Ball::main_ball_position_x(sf::RenderWindow &window)
{
       return ball_main.getPosition().x ;
}

int Ball::main_ball_position_y(sf::RenderWindow &window)
{
       return ball_main.getPosition().y;
}

int Ball::main_ball_global_bounds_h(sf::RenderWindow &window)
{
       return ball_main.getGlobalBounds().height;
}

int Ball::main_ball_global_bounds_w(sf::RenderWindow &window)
{
       return ball_main.getGlobalBounds().width;
}

void Ball::main_ball_radius_colision_in(sf::RenderWindow &window, float radius)
{
    this->radius_colision = radius;
}

float Ball::main_ball_radius_colision_out(sf::RenderWindow &window)
{
    return radius_colision;
}

void Ball::draw_ball(sf::RenderWindow &window)
{
    window.draw(ball_main);
}
