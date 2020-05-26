#ifndef GAME_OBJECTS_INI_H
#define GAME_OBJECTS_INI_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "boards.h"
#include "ball.h"
#include "enemy.h"
#include "animations.h"
#include "bonus.h"
#include "interface.h"
#include "lifes.h"
#include "shooting.h"
#include "text_ini.h"
#include "save_load.h"
#include "summary.h"

class Game_objects_ini

{
public:

     Game_objects_ini(sf::RenderWindow &window, Interface &interface);
     ~Game_objects_ini();

    void draw_game_objects(sf::RenderWindow &window);
    void board_ini(sf::RenderWindow &window);
    void balls_ini(sf::RenderWindow &window);
    void balls_start(sf::RenderWindow &window);
    void colision_objects(sf::RenderWindow &window);
    void object_setings(sf::RenderWindow &window);
    void system(sf::RenderWindow &window, bool, bool, bool, bool);
    void board_move_left(sf::RenderWindow &window);
    void board_move_right(sf::RenderWindow &window);
    void enemies_ini(sf::RenderWindow &window);
    void bonus_ini(sf::RenderWindow &window, int, int, int, int);
    void colision_bonuses(sf::RenderWindow &window);
    void life_ini(sf::RenderWindow &window);
    void life_check_add(sf::RenderWindow &window);
    void shooting_start(sf::RenderWindow &window);
    void bullets_colision(sf::RenderWindow &window);
    void game_over(sf::RenderWindow &window);
    bool space_press(sf::RenderWindow &window);
    int enter_name_void(sf::RenderWindow &window, std::string);
    bool enter_name_bool(sf::RenderWindow &window);
    int points_out(sf::RenderWindow &window);
    void sound_ini(sf::RenderWindow &window);

private:

    sf::Texture player_left_green, player_middle_green, player_right_green, ball_red, blue_button, yellow_button, orange_button, grey_button, green_button, fire, fire_board,
                small_board, big_board, extra_ball, extra_life, board_botton, random, random_small_big, slow_board, wall_board, bullet, stage1, stage2, stage3, stage4,
                player_left_red, player_left_yellow, player_middle_red, player_middle_yellow, player_right_red, player_right_yellow;

    sf::Time time_slow_board, time_shooting, point_time, time_end_level, time_fun, game_over_time;

    sf::Clock clock_slow_board, clock_shooting, point_clock, clock_end_level, clock_fun, game_over_clock;

    sf::Font font_ann, font_points;

    std::vector<Enemy>enemies;
    std::vector<Boards>board_blocks;
    std::vector<Ball>balls;
    std::vector<Animations>enemies_die;
    std::vector<Bonus>bonuses;
    std::vector<Bonus>wall;
    std::vector<Lifes>lifes;
    std::vector<Shooting>shots;
    std::vector<Text_ini>text_ann;
    std::vector<Text_ini>points;
    std::vector<Summary>summary;

    std::string playerInput;

    sf::Event event;

    bool life_yes_no, shoot_enabled, level_end, ann_level, ann_summary, space_press_index, system_game_over, system_game_over_ini, music_play, lvl_play;

    int min_delete, size_board_index, top_size, how_many_columns_enemy, size_enemy_y, ERROR, for_s, level, position_board, wall_size, wall_begin_x, wall_begin_y, how_many_walls,
        size_wall_x, posX_life, posY_life, globalX_life, max_lifes, start_life, globalY_life, bonuses_index, time_check, your_point, posX_point, globalX_point, globalY_point,
        posY_point, globalX_best, globalY_best, posY_best, posX_best, time_points_level_end, time_fun_temp;

    float reverse_ball_board, reverse_ball_board_temp, enemy_scale_x, enemy_scale_y, size_enemy_x, left_size, balls_temp_x, balls_temp_y, ball_speed, ball_real_speed_x,
            ball_real_speed_y, wall_scale_x ;

    sf::SoundBuffer col_board, ball_enemy, fail_ball, bonus_buff, shoot_buff, lvl_buff;

    sf::Sound col_board_sound, ball_enemy_sound, fail_ball_sound, bonus_sound, shoot_sound, lvl_sound;

    sf::Music music;
};

#endif
