#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

class Menu
{
private:
sf::Text new_game, highScore, options, credits, exit, closing, back_text, lukasz_kukulka, lukasz_copy1, lukasz_copy2,
         lukasz_copy3, director, screenplan, project, editor;
sf::Font font, otama_font;
sf::Sprite backgroud_menu;
sf::Texture backgroud;
sf::RectangleShape rec1, rec2, rec3, rec4, rec5, back_button;
sf::Color base_menu_change, base_menu_regular, red_menu, green_menu, black_menu;
int rec_size_x, rec_size_y, transparent_color, y, space_block;
sf::Clock clock;
sf::Time time;



public:

 Menu(sf::RenderWindow &window);
 ~Menu();

int menu_option;

void menu_base(sf::RenderWindow &window, sf::Vector2i, int);
void menu_animation(sf::RenderWindow &window, sf::Vector2i, int);
void menu_newGame(sf::RenderWindow &window, sf::Vector2i, int);
void menu_highScore(sf::RenderWindow &window, sf::Vector2i, int);
void menu_options(sf::RenderWindow &window, sf::Vector2i, int);
void menu_credits(sf::RenderWindow &window, sf::Vector2i, int);
void menu_exit(sf::RenderWindow &window, sf::Vector2i, int);
void menu_form_to_play(sf::RenderWindow &window, sf::Vector2i, int);
void menu_option_index(sf::RenderWindow &window, sf::Vector2i, int);
void draw_menu(sf::RenderWindow &window, sf::Vector2i, int);


};
#endif
