#ifndef GAME_OBJECTS_INI_H
#define GAME_OBJECTS_INI_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "boards.h"

class Game_objects_ini

{
public:

     Game_objects_ini(sf::RenderWindow &window);

     ~Game_objects_ini();

    void draw_game_objects(sf::RenderWindow &window);
    void board_ini(sf::RenderWindow &window, sf::Texture *left_tex, sf::Texture *mid_tex, sf::Texture *right_tex, int);
    void board_move_left(sf::RenderWindow &window);
    void board_move_right(sf::RenderWindow &window);

private:

    sf::Texture player_left_green, player_middle_green, player_right_green;
    std::vector<Boards>board_blocks;
    bool ini_index_left, ini_index_right;
    int min_delete;
};
#endif
