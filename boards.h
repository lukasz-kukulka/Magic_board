#ifndef BOARDS_H
#define BOARDS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Boards

{
public:

     Boards(sf::RenderWindow &window, sf::Texture *texture, int);

     ~Boards();

    void draw_board(sf::RenderWindow &window);
    void move_board_left(sf::RenderWindow &window);
    void move_board_right(sf::RenderWindow &window);
    void move_board_stop(sf::RenderWindow &window);
    int move_board_position(sf::RenderWindow &window);
    void move_board_reset_right(sf::RenderWindow &window, int);
    void move_board_reset_left(sf::RenderWindow &window, int);
    int move_board_check_right(sf::RenderWindow &window);
    int move_board_check_left(sf::RenderWindow &window);


private:
    sf::Sprite board_sprite;
    int size_board, set_position_x, speed_move_right;

};
#endif
