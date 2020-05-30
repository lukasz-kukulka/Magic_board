#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Menu_button
{
public:

    static int no_menu_options;

    Menu_button(sf::RenderWindow &window, sf::Font *font, std::string);
    Menu_button(std::string, sf::RenderWindow &window, sf::Font *font, int);
    ~Menu_button();

    int touch_button(sf::RenderWindow &window, sf::Vector2i);
    int back_save_button(sf::RenderWindow &window, sf::Vector2i, int);
    void show_button(sf::RenderWindow &window, sf::Vector2i);
    void menu_button_exit(sf::RenderWindow &window);
    int animation_button_off(sf::RenderWindow &window, sf::Vector2i mouse);
    int animation_button_on(sf::RenderWindow &window);

private:
    sf::Font button_font;
    sf::Text text_button, button_text;
    sf::RectangleShape button_menu, button_shape;
    int start_position_x, start_position_y, r_color, g_color, b_color, t_color, outline_button_size, outline_text_size, text_size, how_many_button, menu_index;
    double scale_index_button, scale_index_text;
    bool play_sound;
    sf::Clock clock;
    sf::Time time;
};

#endif
