#ifndef SHOOTING_H
#define SHOOTING_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Shooting

{
public:

    Shooting(sf::RenderWindow &window, sf::Texture *texture, int, int);
    ~Shooting();

    void draw_shot(sf::RenderWindow &window);
    void bullet_move(sf::RenderWindow &window);
    int shot_pos_x(sf::RenderWindow &window);
    int shot_pos_y(sf::RenderWindow &window);
    int shot_global_x(sf::RenderWindow &window);

private:

    sf::Sprite single_shot;
};

#endif
