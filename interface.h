#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Interface
{
public:

     Interface(sf::RenderWindow &window);
     ~Interface();

     void draw_interface(sf::RenderWindow &window);

private:

    sf::Texture backgroud, board_corner, board_block_light;
    sf::Sprite backgroud_inter, board_corner_sprite, board_block_light_sprite;

    int size_block, start_draw_x, end_draw_x, start_draw_y, end_draw_y, width_screen, height_screen, no_blocks_x, no_blocks_y, center_x, center_y;


};
#endif
