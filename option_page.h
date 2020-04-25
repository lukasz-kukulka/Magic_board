#ifndef OPTION_PAGE_H
#define OPTION_PAGE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "save_load.h"

class Option_page
{
public:

    static int width_screen_basic, height_screen_basic;

    Option_page(sf::RenderWindow &window, sf::Vector2i, int );
    ~Option_page();



    void draw_option_page(sf::RenderWindow &window);
    int basic(sf::RenderWindow &window, sf::Vector2i, int);
    void background_animation(sf::RenderWindow &window, sf::Vector2i, int);
    void board_load(sf::RenderWindow &window, sf::Vector2i, int);
    int system(sf::RenderWindow &window, sf::Vector2i, int);
    void reset_object(sf::RenderWindow &window, sf::Vector2i, int);
    void load_from_file(sf::RenderWindow &window, sf::Vector2i, int);
    void settings_ini(sf::RenderWindow &window);


private:
    sf::Text screen_resolution, screen_resolution800x600, screen_resolution1280x1024, screen_resolution1920x1080,
              windowed_mode, fullscreen_mode, high_score, high_score_no_1, high_score_no_3, high_score_no_5, save_button_text, back_button_text,
              mode_screen, window_option, full_option, color_board, back_text, save_text;

    int width_screen, height_screen, center_x, center_y, size_block, start_draw_x, end_draw_x, start_draw_y, end_draw_y, no_blocks_x, no_blocks_y,
        resolution_x, resolution_y, screen_mode, no_winners, no_parts, menu_options, menu_option_menu_page, settings_tab[5], position_nice_font_x,
        position_nice_font_y, annoucment;

    sf::Font otama_font, nice_font;

    sf::Sprite block, button800x600_true, button1280x1024_true, button1920x1080_true, mode_full, mode_window, score_1, score_3, score_5, board_part,
        option_board_green, option_board_yellow, option_board_red;

    sf::RectangleShape back_button, save_button, line1, line2, line3;

    sf::Texture block_texture_corner, block_texture_middle, block_texture_board, button_null, button_true, player_left, player_middle, player_right,
                player_middle_yellow, player_right_yellow, player_left_yellow, player_right_green, player_middle_green, player_left_green;

    std::vector<sf::Sprite>blocks;
    std::vector<sf::Sprite>board_parts_red;
    std::vector<sf::Sprite>board_parts_yellow;
    std::vector<sf::Sprite>board_parts_green;

    Save_load save_setings;

    bool animation;


};

#endif
