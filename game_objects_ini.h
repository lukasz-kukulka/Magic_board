#ifndef GAME_OBJECTS_INI_H
#define GAME_OBJECTS_INI_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "boards.h"
#include "ball.h"

class Game_objects_ini

{
public:

     Game_objects_ini(sf::RenderWindow &window);

     ~Game_objects_ini();

    void draw_game_objects(sf::RenderWindow &window);
    void board_ini(sf::RenderWindow &window, sf::Texture *left_tex, sf::Texture *mid_tex, sf::Texture *right_tex, int);
    void balls_ini(sf::RenderWindow &window, sf::Texture *texture);

    void balls_start(sf::RenderWindow &window);
    void colision_objects(sf::RenderWindow &window);
    float board_blocks_radius(sf::RenderWindow &window);
    void object_setings(sf::RenderWindow &window);

    void system(sf::RenderWindow &window, bool, bool, bool);

    void board_move_left(sf::RenderWindow &window);
    void board_move_right(sf::RenderWindow &window);



private:

    sf::Texture player_left_green, player_middle_green, player_right_green, ball_red;
    std::vector<Boards>board_blocks;
    std::vector<Ball>balls;
    bool ini_index_left, ini_index_right;
    int min_delete, size_board_index;
    double reverse_ball_board, reverse_ball_board_temp;
};
#endif
