#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "save_load.h"


class Enemy

{
public:

    Enemy(sf::RenderWindow &window, sf::Texture *texture, int, int, int, int, float, float, int, int);
    ~Enemy();

    void draw_enemy_main(sf::RenderWindow &window);
    int HP_enemy_out(sf::RenderWindow &window);
    int enemy_pos_x(sf::RenderWindow &window);
    int enemy_global_w(sf::RenderWindow &window);
    int enemy_pos_y(sf::RenderWindow &window);
    int enemy_global_h(sf::RenderWindow &window);
    int HP_enemy_reduce(sf::RenderWindow &window);
    int enemy_bonus(sf::RenderWindow &window);
    int enemy_punish(sf::RenderWindow &window);
    void enemy_update(sf::RenderWindow &window, sf::Texture *stage1, sf::Texture *stage2, sf::Texture *stage3, sf::Texture *stage4);

private:

    sf::Sprite enemy_rec, enemy_damage;
    int HP_enemy, HP_enemy_MAX, random_punish, random_bonus, level;
    float scale_x, scale_y;
};

#endif
