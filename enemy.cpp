#include "enemy.h"


Enemy::Enemy(sf::RenderWindow &window, sf::Texture *texture, int position_x, int position_y, int no_blocks, int how_many_columns, float scale_x, float scale_y, int HP_enemy, int level = 1)
{
    Save_load* difficulty = new Save_load;
    this->level = level;
    this->HP_enemy_MAX = HP_enemy;
    this->HP_enemy = HP_enemy;
    this->enemy_rec.setTexture(*texture);
    this->enemy_rec.setScale(scale_x, scale_y);
    this->enemy_rec.setPosition(position_x + (enemy_rec.getGlobalBounds().width * no_blocks), position_y + (enemy_rec.getGlobalBounds().height * how_many_columns));
    this->random_bonus = ( std::rand() % (20 * difficulty->load_board_lvl(window, 3)) * level ) + 1;
    this->random_punish = ( std::rand() % 300 / level ) + 1000;
    this->enemy_damage.setScale(scale_x, scale_y);
    this->enemy_damage.setPosition(enemy_rec.getPosition().x, enemy_rec.getPosition().y);
    delete difficulty;
    difficulty = 0;
}

Enemy::~Enemy(){}

void Enemy::enemy_update(sf::RenderWindow &window, sf::Texture *stage1, sf::Texture *stage2, sf::Texture *stage3, sf::Texture *stage4)
{
    if(HP_enemy_MAX - HP_enemy == 1)
       {
            this->enemy_damage.setTexture(*stage1);
       }

    else if(HP_enemy_MAX - HP_enemy == 2)
       {
            this->enemy_damage.setTexture(*stage2);
       }

    else if(HP_enemy_MAX - HP_enemy == 3)
       {
            this->enemy_damage.setTexture(*stage3);
       }

    else if(HP_enemy_MAX - HP_enemy == 4)
       {
            this->enemy_damage.setTexture(*stage4);
       }
}

int Enemy::enemy_bonus(sf::RenderWindow &window)
{
    return random_bonus;
}

int Enemy::enemy_punish(sf::RenderWindow &window)
{
    return random_punish;
}

int Enemy::HP_enemy_out(sf::RenderWindow &window)
{
    return HP_enemy_MAX;
}

int Enemy::HP_enemy_reduce(sf::RenderWindow &window)
{
    this->HP_enemy = HP_enemy - 1;
    return HP_enemy;
}

int Enemy::enemy_pos_x(sf::RenderWindow &window)
{
    return enemy_rec.getPosition().x;
}

int Enemy::enemy_global_w(sf::RenderWindow &window)
{
    return enemy_rec.getGlobalBounds().width;
}

int Enemy::enemy_pos_y(sf::RenderWindow &window)
{
    return enemy_rec.getPosition().y;
}

int Enemy::enemy_global_h(sf::RenderWindow &window)
{
    return enemy_rec.getGlobalBounds().height;
}

void Enemy::draw_enemy_main(sf::RenderWindow &window)
{
    window.draw(enemy_rec);
    window.draw(enemy_damage);
}
