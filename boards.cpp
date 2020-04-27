#include "boards.h"



Boards::Boards(sf::RenderWindow &window, sf::Texture *texture, int size_board)
{
    this->speed_move_right = 30;
    this->board_sprite.setTexture(*texture);
    this->board_sprite.setPosition(window.getSize().x/2 + board_sprite.getGlobalBounds().width * size_board, window.getSize().y/8*7);

}

Boards::~Boards(){}

void Boards::move_board_left(sf::RenderWindow &window)
{
    board_sprite.move(-30, 0);
}

void Boards::move_board_right(sf::RenderWindow &window)
{
    board_sprite.move(30, 0);
}

void Boards::move_board_stop(sf::RenderWindow &window)
{
    board_sprite.move(0, 0);
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

int Boards::move_board_position(sf::RenderWindow &window)
{
       return board_sprite.getPosition().x;
}

void Boards::draw_board(sf::RenderWindow &window)
{
    window.draw(board_sprite);
}
