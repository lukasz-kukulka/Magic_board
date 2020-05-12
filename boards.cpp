#include "boards.h"



Boards::Boards(sf::RenderWindow &window, sf::Texture *texture, int size_board, float radius, int position)
{
    this->change_move_speed_x = 1.0;
    this->change_move_speed_y = 1.0;
    this->radius = radius;
    this->board_sprite.setTexture(*texture);
    this->board_sprite.setPosition(position + board_sprite.getGlobalBounds().width * size_board, window.getSize().y/8*7);

}

Boards::~Boards(){}

void Boards::move_board_left(sf::RenderWindow &window)
{
    board_sprite.move(-20 * change_move_speed_x, 0 * change_move_speed_y);
}

void Boards::move_board_right(sf::RenderWindow &window)
{
    board_sprite.move(20 * change_move_speed_x, 0 * change_move_speed_y);
}

void Boards::move_board_stop(sf::RenderWindow &window)
{
    board_sprite.move(0 * change_move_speed_x, 0 * change_move_speed_y);
}

int Boards::move_board_check_right(sf::RenderWindow &window)
{
    return board_sprite.getPosition().x - (window.getSize().x - (((window.getSize().x/2) % 32) + 80));
}

int Boards::move_board_check_left(sf::RenderWindow &window)
{
    return (((window.getSize().x/2) % 32) + 70) - board_sprite.getPosition().x;
}

void Boards::move_board_reset_right(sf::RenderWindow &window, int minus_size)
{
    board_sprite.setPosition(board_sprite.getPosition().x - minus_size, board_sprite.getPosition().y);
}

void Boards::move_board_reset_left(sf::RenderWindow &window, int minus_size)
{
    board_sprite.setPosition(board_sprite.getPosition().x + minus_size, board_sprite.getPosition().y);
}

int Boards::move_board_position_x(sf::RenderWindow &window)
{
       return board_sprite.getPosition().x;
}

int Boards::move_board_position_y(sf::RenderWindow &window)
{
       return board_sprite.getPosition().y;
}

int Boards::move_board_global_bounds_h(sf::RenderWindow &window)
{
       return board_sprite.getGlobalBounds().height;
}

int Boards::move_board_global_bounds_w(sf::RenderWindow &window)
{
       return board_sprite.getGlobalBounds().width;
}

void Boards::change_board_speed(sf::RenderWindow &window, bool low_on)
{
    if(low_on == true)
        {
            change_move_speed_x = change_move_speed_x * 0.5;
        }

    else
        {
            change_move_speed_x = 1;
        }
    change_move_speed_x = change_move_speed_x * 0.5;
}

float Boards::move_board_radius(sf::RenderWindow &window)
{
       return radius;
}

void Boards::draw_board(sf::RenderWindow &window)
{
    window.draw(board_sprite);
}
