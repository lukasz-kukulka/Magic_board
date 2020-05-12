#ifndef BONUS_H
#define BONUS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

class Bonus

{
public:

    Bonus(sf::RenderWindow &window, sf::Texture *texture, int, int, int, int);
    Bonus(sf::RenderWindow &window, sf::Texture *texture, int, int, int, float);

    ~Bonus();

    void draw_bonus(sf::RenderWindow &window);
    void move_bonus(sf::RenderWindow &window);

    int posX_bonus(sf::RenderWindow &window);
    int posY_bonus(sf::RenderWindow &window);
    int global_x_bonus(sf::RenderWindow &window);
    int global_y_bonus(sf::RenderWindow &window);
    int random_bonus(sf::RenderWindow &window);
    int wall_global_x(sf::RenderWindow &window);
    int wall_position_x(sf::RenderWindow &window);
    int wall_position_y(sf::RenderWindow &window);




private:
    sf::Sprite bonus_sprite, wall_sprite;
    int speed, random;

};
#endif
