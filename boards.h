#ifndef BOARDS_H
#define BOARDS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Boards

{
public:

     Boards(sf::RenderWindow &window, sf::Texture *texture, int, float, int);

     ~Boards();

    void draw_board(sf::RenderWindow &window);
    void move_board_left(sf::RenderWindow &window);
    void move_board_right(sf::RenderWindow &window);
    void move_board_stop(sf::RenderWindow &window);
    int move_board_position_x(sf::RenderWindow &window);
    int move_board_position_y(sf::RenderWindow &window);
    int move_board_global_bounds_h(sf::RenderWindow &window);
    int move_board_global_bounds_w(sf::RenderWindow &window);
    void move_board_reset_right(sf::RenderWindow &window, int);
    void move_board_reset_left(sf::RenderWindow &window, int);
    int move_board_check_right(sf::RenderWindow &window);
    int move_board_check_left(sf::RenderWindow &window);
    float move_board_radius(sf::RenderWindow &window);
    void change_board_speed(sf::RenderWindow &window, bool);


private:
    sf::Sprite board_sprite;
    int size_board, set_position_x;
    float radius, change_move_speed_x, change_move_speed_y;

};
#endif
