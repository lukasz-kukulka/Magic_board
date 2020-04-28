#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


class Ball

{
public:

    Ball(sf::RenderWindow &window, sf::Texture *texture);

    ~Ball();

    void draw_ball(sf::RenderWindow &window);
    void move_ball(sf::RenderWindow &window, float, float, float, float);
    int colision_main_ball_y(sf::RenderWindow &window);
    int colision_main_ball_x(sf::RenderWindow &window);
    float colision_main_ball_board(sf::RenderWindow &window, float);
    int main_ball_global_bounds_h(sf::RenderWindow &window);
    int main_ball_global_bounds_w(sf::RenderWindow &window);
    int main_ball_position_x(sf::RenderWindow &window);
    int main_ball_position_y(sf::RenderWindow &window);
    int colision_main_ball_board_x(sf::RenderWindow &window);
    void main_ball_radius_colision_in(sf::RenderWindow &window, float);
    float main_ball_radius_colision_out(sf::RenderWindow &window);


private:

    sf::Sprite ball_main;
    float right_colision, left_colision, top_colision, colision_change_y, colision_change_x, radius_colision;

};
#endif
