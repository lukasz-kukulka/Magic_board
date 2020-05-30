#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "backgroud_game.h"

class Interface
{
public:

     Interface(sf::RenderWindow &window);
     ~Interface();

     void draw_interface(sf::RenderWindow &window);
     int posX_middle(sf::RenderWindow &window, int);
     int posY_middle(sf::RenderWindow &window, int);
     int global_X_middle(sf::RenderWindow &window, int);
     int global_Y_middle(sf::RenderWindow &window, int);

private:

    sf::Texture backgroud, board_corner, board_block_light, board_block, board_connect, score_left, score_middle, score_right, corner_board, middle, middle_board;

    sf::Sprite backgroud_inter, board_corner_sprite, board_block_light_sprite, board_block_sprite, board_connect_sprite1,
                board_connect_sprite2, board_connect_sprite3;

    int size_block, start_draw_x, end_draw_x, start_draw_y, end_draw_y, width_screen, height_screen, no_blocks_x, no_blocks_y,
        center_x, center_y, check_size_index;

    std::vector<Backgroung_game>interface_items;
    std::vector<Backgroung_game>connect_board;
    std::vector<Backgroung_game>corners;
    std::vector<Backgroung_game>quads;
    std::vector<Backgroung_game>squares;
};

#endif
