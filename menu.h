#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "option_page.h"
#include "menu_button.h"
#include "credits.h"
#include "save_load.h"

class Menu
{
public:

     Menu(sf::RenderWindow &window, sf::Vector2i, int, Option_page &options_class);
     ~Menu();


    void menu_credits(sf::RenderWindow &window);
    void menu_button_exit(sf::RenderWindow &window);
    void menu_option_index(sf::RenderWindow &window, sf::Vector2i, int, Option_page &options_object);
    void draw_menu(sf::RenderWindow &window, sf::Vector2i, int, Option_page &options_class);
    void menu_button_objects(sf::RenderWindow &window, sf::Vector2i);
    int menu_option_if(sf::RenderWindow &window, sf::Vector2i, int, Option_page &options_class);


private:

    sf::Text back_text, lukasz_kukulka, lukasz_copy1, lukasz_copy2, lukasz_copy3, director, screenplan, project, editor;
    sf::Font font, otama_font, SF_Italic, SF_Extended;
    sf::Sprite backgroud_menu;
    sf::Texture backgroud;
    sf::RectangleShape back_button;
    sf::Color base_menu_change, base_menu_regular, red_menu, green_menu, black_menu;
    int rec_size_x, rec_size_y, transparent_color, y, space_block, return_menu_button, credits_class_true, records;
    sf::Clock clock;
    sf::Time time;
    std::vector<Menu_button>menu_options_class;
    std::vector<Credits>credits_class;
    Save_load load_records;

};
#endif
