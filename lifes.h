#ifndef LIFES_H
#define LIFES_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Lifes

{
public:

     Lifes(sf::RenderWindow &window, sf::Texture *left, int, int, int, int);

     ~Lifes();

     void draw_life(sf::RenderWindow &window);
     void life_change(sf::RenderWindow &window, bool);
     int life_check(sf::RenderWindow &window);



private:
    sf::Sprite life_sprite;

    bool life_yes_no;

};
#endif
