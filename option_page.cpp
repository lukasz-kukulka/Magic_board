#include "option_page.h"


Option_page::Option_page(sf::RenderWindow &window)
{
    this->otama_font.loadFromFile("Fonts/otama.otf");
    this->center_x = window.getSize().x/2;
    this->center_y = window.getSize().y/2;
    this->size_block = 32;
    this->start_draw_x = (center_x % size_block) + (size_block*3);
    this->end_draw_x = window.getSize().x - ((center_x % size_block) + (size_block*3));
    this->start_draw_y = (center_y % size_block) + (size_block*3);
    this->end_draw_y = window.getSize().y - ((center_y % size_block) + (size_block*3));;
    this->width_screen = window.getSize().x - ((center_x % size_block) + (size_block*3)*2);
    this->height_screen = window.getSize().y - ((center_y % size_block) + (size_block*3)*2);
    this->no_blocks_x = width_screen/size_block;
    this->no_blocks_y = height_screen/size_block;

    this->block_texture_corner.loadFromFile("Textures/corner-board.png");
    this->block_texture_middle.loadFromFile("Textures/middle.png");
    this->block_texture_board.loadFromFile("Textures/middle-board.png");

    this->screen_resolution.setFont(otama_font);
    this->screen_resolution.setCharacterSize(0);
    this->screen_resolution.setFillColor(sf::Color(255, 255, 0));
    this->screen_resolution.setString("NEW GAME");
    this->screen_resolution.setOutlineThickness(2);
    this->screen_resolution.setPosition(100, 100);
}



Option_page::~Option_page(){}

void Option_page::basic(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{
    screen_resolution.setCharacterSize(150);
    std::cout<<"..................................................."<<std::endl;
}

void Option_page::animation(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{

}

void Option_page::draw_option_page(sf::RenderWindow &window)
{
    window.draw(screen_resolution);
}
