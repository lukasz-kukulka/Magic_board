#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Animations

{
public:

    Animations(sf::RenderWindow &window, sf::Texture *texture, int, int, int);

    ~Animations();

    void draw_animation_death(sf::RenderWindow &window);
    int animation_fire(sf::RenderWindow &window);

private:
    sf::Sprite animation_die;
    sf::Color animation_color;
    float scale_x, scale_y;
    int pozX, pozY, color_fire;

};
#endif
