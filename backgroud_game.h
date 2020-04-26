#ifndef BACKGROUND_GAME_H
#define BACKGROUND_GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Backgroung_game

{
public:

     Backgroung_game(sf::RenderWindow &window, sf::Texture *left, sf::Texture *middle, sf::Texture *right, int, int, int);
     Backgroung_game(sf::RenderWindow &window, sf::Texture *connector, int, int, int);
     Backgroung_game(sf::Texture *corner, int, int, int);
     Backgroung_game(sf::Texture *corner, int, int);
     Backgroung_game(sf::Texture *square, int, int, int, sf::RenderWindow &window);
     ~Backgroung_game();

    void draw_backgroud_game(sf::RenderWindow &window);
    void draw_backgroud_connector(sf::RenderWindow &window);
    void draw_backgroud_corners(sf::RenderWindow &window);
    void draw_backgroud_quads(sf::RenderWindow &window);
    void draw_backgroud_square(sf::RenderWindow &window);


private:

    sf::Sprite left_sprite, middle_sprite1, middle_sprite2, middle_sprite3,  middle_sprite4, middle_sprite5, right_sprite, connector_sprite,
                corner_sprite, quad_sprite, square_sprite;

};
#endif
