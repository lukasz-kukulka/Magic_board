#include <iostream>
#include <SFML/Graphics.hpp>



class Option_page
{
private:
    sf::Text screen_resolution, screen_resolution800x600, screen_resolution1280x1024, screen_resolution1920x1080,
            windowed_mode, fullscreen_mode, high_score, high_score_no, save_button_text, back_button_text;
    int width_screen, height_screen, center_x, center_y, size_block, start_draw_x, end_draw_x, start_draw_y, end_draw_y, no_blocks_x, no_blocks_y;
    sf::Font otama_font;
    sf::Sprite block;
    sf::RectangleShape back_button, save_button, line;
    sf::Texture block_texture_corner, block_texture_middle, block_texture_board;
    std::vector<sf::Sprite>blocks;

public:
 Option_page(sf::RenderWindow &window);
 ~Option_page();


void animation(sf::RenderWindow &window, sf::Vector2i, int);
void draw_option_page(sf::RenderWindow &window);
void basic(sf::RenderWindow &window, sf::Vector2i, int);
};

