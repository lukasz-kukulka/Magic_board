#ifndef TEXT_INI_H
#define TEXT_INI_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>

class Text_ini

{
public:

     Text_ini(sf::RenderWindow &window, sf::Font *font, std::string, int);
     Text_ini(sf::RenderWindow &window, sf::Font *font, std::string, std::string, int, int);
     ~Text_ini();

     void draw_text(sf::RenderWindow &window);
     int animation_text(sf::RenderWindow &window);
     void points_update(sf::RenderWindow &window, int points);



private:
    sf::Text text, text_point, score;
    std::string string_points;
    int color_r, color_g, color_b, color_a;

};
#endif
