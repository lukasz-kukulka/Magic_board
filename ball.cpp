#include "ball.h"


Ball::Ball(sf::RenderWindow &window, sf::Texture *texture)
{
    this->top_colision = ((window.getSize().y/2) % 32) + (70);
    this->left_colision = ((window.getSize().x/2) % 32) + (66);
    this->right_colision = window.getSize().x - ((window.getSize().x % 32) + (96));
    this->ball_main.setTexture(*texture);
    this->ball_main.setPosition(( std::rand() % (window.getSize().x - 240) + 120), window.getSize().y/2);
    this->colision_change_y = 1;
    this->colision_change_x = 1;
    this->radius_colision = 0;
    this->real_speed_x = 0;
    this->real_speed_y = 0;
    this->radius = 1;
}

Ball::~Ball(){}

void Ball::move_ball(sf::RenderWindow &window, float dir_X = 1, float dir_Y = -1, float speed = 1, float level = 1)
{
    real_speed_x = speed * dir_X * level;
    real_speed_y = speed * dir_Y * level;
    if(real_speed_x > 8)
        {
            real_speed_x = 8 * dir_X;
            real_speed_y = 8 * dir_Y;
        }
    ball_main.move(real_speed_x, real_speed_y);
}

int Ball::colision_main_ball_y(sf::RenderWindow &window)
{
    if(ball_main.getPosition().y < top_colision)
        {
            ball_main.setPosition(ball_main.getPosition().x, top_colision);
            colision_change_y = colision_change_y * (-1);
            return colision_change_y;
        }
    else
        return colision_change_y;
}

int Ball::colision_main_ball_x(sf::RenderWindow &window)
{
    if(ball_main.getPosition().x < left_colision)
        {
            ball_main.setPosition(left_colision, ball_main.getPosition().y);
            colision_change_x = colision_change_x * (-1);
            return colision_change_x;
        }

    else if(ball_main.getPosition().x > right_colision)
        {
            ball_main.setPosition(right_colision, ball_main.getPosition().y);
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

float Ball::main_ball_position_x(sf::RenderWindow &window)
{
       return ball_main.getPosition().x ;
}

float Ball::main_ball_position_y(sf::RenderWindow &window)
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

void Ball::main_ball_ad_pos(sf::RenderWindow &window, int pos_x, int pos_y)
{
    ball_main.setPosition(ball_main.getPosition().x + pos_x, ball_main.getPosition().y + pos_y);
}

float Ball::main_ball_real_speed_x(sf::RenderWindow &window)
{
    return real_speed_x;
}

float Ball::main_ball_real_speed_y(sf::RenderWindow &window)
{
    return real_speed_y;
}

void Ball::error_ball(sf::RenderWindow &window, int posY)
{
    ball_main.setPosition(ball_main.getPosition().x, posY - ball_main.getGlobalBounds().height);
}

void Ball::draw_ball(sf::RenderWindow &window)
{
    window.draw(ball_main);
}
