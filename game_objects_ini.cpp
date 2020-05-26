#include "game_objects_ini.h"

Game_objects_ini::Game_objects_ini(sf::RenderWindow &window, Interface &interface)
{
    this->font_ann.loadFromFile("Fonts/Bada.ttf");
    this->font_points.loadFromFile("Fonts/nasalization-rg.ttf");

    this->player_left_green.loadFromFile("Textures/player-left-green.png");
    this->player_middle_green.loadFromFile("Textures/player-middle-green.png");
    this->player_right_green.loadFromFile("Textures/player-right-green.png");

    this->player_left_red.loadFromFile("Textures/player-left-red.png");
    this->player_middle_red.loadFromFile("Textures/player-middle-red.png");
    this->player_right_red.loadFromFile("Textures/player-right-red.png");

    this->player_left_yellow.loadFromFile("Textures/player-left-yellow.png");
    this->player_middle_yellow.loadFromFile("Textures/player-middle-yellow.png");
    this->player_right_yellow.loadFromFile("Textures/player-right-yellow.png");

    this->blue_button.loadFromFile("Textures/blue_button.png"); //1 HP
    this->yellow_button.loadFromFile("Textures/yellow_button.png");//2 HP
    this->orange_button.loadFromFile("Textures/orange_button.png");//3 HP
    this->grey_button.loadFromFile("Textures/grey_button.png");//4 HP
    this->green_button.loadFromFile("Textures/green_button.png");//5 HP

    this->stage1.loadFromFile("Textures/stage1.png");
    this->stage2.loadFromFile("Textures/stage2.png");
    this->stage3.loadFromFile("Textures/stage3.png");
    this->stage4.loadFromFile("Textures/stage4.png");

    this->fire_board.loadFromFile("Textures/fire_board.png");
    this->small_board.loadFromFile("Textures/small_board.png");
    this->big_board.loadFromFile("Textures/big_boards.png");
    this->extra_ball.loadFromFile("Textures/extra_ball.png");
    this->extra_life.loadFromFile("Textures/extra_life.png");
    this->board_botton.loadFromFile("Textures/board_botton.png");
    this->random.loadFromFile("Textures/random.png");
    this->random_small_big.loadFromFile("Textures/random_small_big.png");
    this->slow_board.loadFromFile("Textures/slow_board.png");

    this->wall_board.loadFromFile("Textures/wall.png");
    this->bullet.loadFromFile("Textures/bullet.png");

    this->fire.loadFromFile("Textures/fire.png");
    this->ball_red.loadFromFile("Textures/ball-red.png");

    this->wall_begin_x = ((window.getSize().x/2) % 32) + 70;
    this->wall_begin_y = window.getSize().y/11*10;
    this->wall_scale_x = (((window.getSize().x - (2.0* wall_begin_x)) / 12.0) / 200.0);
    this->how_many_walls = 12;

    this->posX_life = interface.posX_middle(window, 2) + 2;
    this->globalX_life = interface.global_X_middle(window, 2);
    this->globalY_life = interface.global_Y_middle(window, 2);
    this->posY_life =  interface.posY_middle(window, 2) + globalY_life/2;

    this->globalX_point = interface.global_X_middle(window, 0);
    this->globalY_point = interface.global_Y_middle(window, 0);
    this->posY_point =  interface.posY_middle(window, 0) + globalY_point/2;
    this->posX_point = interface.posX_middle(window, 0) + globalX_point/2;

    this->globalX_best = interface.global_X_middle(window, 1);
    this->globalY_best = interface.global_Y_middle(window, 1);
    this->posY_best =  interface.posY_middle(window, 1) + globalY_best/2;
    this->posX_best = interface.posX_middle(window, 1) + globalX_best/2;

    sound_ini(window);

    object_setings(window);
}

Game_objects_ini::~Game_objects_ini(){}

void Game_objects_ini::board_ini(sf::RenderWindow &window)
{
    Save_load* board_color = new Save_load;
    reverse_ball_board_temp = 0;


    for(int i = 0; i < size_board_index; i++)
        {
            if(i<=size_board_index/2)
                {
                    this->reverse_ball_board_temp = reverse_ball_board_temp + reverse_ball_board;
                }

            else
                {
                    this->reverse_ball_board_temp = reverse_ball_board_temp - reverse_ball_board;
                }

            if(board_color->load_board_lvl(window, 5) == 1)
                {
                    if(i == 0)
                        {
                            board_blocks.push_back(Boards(window, &player_left_red, i, reverse_ball_board_temp, position_board));
                        }

                    else if(i > 0 && i < size_board_index - 1)
                        {
                            board_blocks.push_back(Boards(window, &player_middle_red, i, reverse_ball_board_temp, position_board));
                        }

                    else if(i == size_board_index - 1)
                        {
                            board_blocks.push_back(Boards(window, &player_right_red, i, reverse_ball_board_temp, position_board));
                        }
                }

            else if(board_color->load_board_lvl(window, 5) == 2)
                {
                    if(i == 0)
                        {
                            board_blocks.push_back(Boards(window, &player_left_green, i, reverse_ball_board_temp, position_board));
                        }

                    else if(i > 0 && i < size_board_index - 1)
                        {
                            board_blocks.push_back(Boards(window, &player_middle_green, i, reverse_ball_board_temp, position_board));
                        }

                    else if(i == size_board_index - 1)
                        {
                            board_blocks.push_back(Boards(window, &player_right_green, i, reverse_ball_board_temp, position_board));
                        }
                }

            else if(board_color->load_board_lvl(window, 5) == 3)
                {
                    if(i == 0)
                        {
                            board_blocks.push_back(Boards(window, &player_left_yellow, i, reverse_ball_board_temp, position_board));
                        }

                    else if(i > 0 && i < size_board_index - 1)
                        {
                            board_blocks.push_back(Boards(window, &player_middle_yellow, i, reverse_ball_board_temp, position_board));
                        }

                    else if(i == size_board_index - 1)
                        {
                            board_blocks.push_back(Boards(window, &player_right_yellow, i, reverse_ball_board_temp, position_board));
                        }
                }
        }
    delete board_color;
    board_color = 0;
}

void Game_objects_ini::life_ini(sf::RenderWindow &window)
{
    for(int j = 0; j < 2; j++)
        {
            for(int i = 0; i < max_lifes/2; i++)
                {
                    lifes.push_back(Lifes(window, &extra_life, posX_life, posY_life, i, j));
                }
        }

}

void Game_objects_ini::life_check_add(sf::RenderWindow &window)
{
    for(int i = 0; i < lifes.size(); i++)
        if(i < start_life)
            {
                life_yes_no = true;
                lifes[i].life_change(window, life_yes_no);
            }
        else
            {
                life_yes_no = false;
                lifes[i].life_change(window, life_yes_no);
            }
}

void Game_objects_ini::balls_ini(sf::RenderWindow &window)
{
    Save_load* difficulty = new Save_load;

    if(difficulty->load_board_lvl(window, 3) == 1)
        {
            balls.push_back(Ball(window, &ball_red));
            balls.push_back(Ball(window, &ball_red));
            balls.push_back(Ball(window, &ball_red));
        }

    else if(difficulty->load_board_lvl(window, 3) == 2)
        {
            balls.push_back(Ball(window, &ball_red));
            balls.push_back(Ball(window, &ball_red));
        }

    else if(difficulty->load_board_lvl(window, 3) == 3)
        {
            balls.push_back(Ball(window, &ball_red));
        }
    delete difficulty;
    difficulty = 0;
}

void Game_objects_ini::enemies_ini(sf::RenderWindow &window)
{
    if(level == 1)
        {
            for(int j = 0; j < size_enemy_y; j++)
                {
                    for(int i = 0; i < how_many_columns_enemy; i++)
                        {
                            enemies.push_back(Enemy(window, &blue_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 1, level));
                        }
                }
        }

    else if(level == 2)
        {
            for(int j = 0; j < size_enemy_y; j++)
                {
                    for(int i = 0; i < how_many_columns_enemy; i++)
                        {
                            if(j == 0)
                                {
                                    enemies.push_back(Enemy(window, &yellow_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 2, level));
                                }
                            else
                                {
                                    enemies.push_back(Enemy(window, &blue_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 1, level));
                                }
                        }
                }
        }

    else if(level == 3)
        {
            for(int j = 0; j < size_enemy_y; j++)
                {
                    for(int i = 0; i < how_many_columns_enemy; i++)
                        {
                            if(j == 0)
                                {
                                    enemies.push_back(Enemy(window, &yellow_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 2, level));
                                }
                            else if(j == 4)
                                {
                                    enemies.push_back(Enemy(window, &orange_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 3, level));
                                }
                            else
                                {
                                    enemies.push_back(Enemy(window, &blue_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 1, level));
                                }
                        }
                }
        }

    else if(level == 4)
        {
            for(int j = 0; j < size_enemy_y; j++)
                {
                    for(int i = 0; i < how_many_columns_enemy; i++)
                        {
                            if(j == 0 || j == 1)
                                {
                                    enemies.push_back(Enemy(window, &yellow_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 2, level));
                                }
                            else if(j == 4)
                                {
                                    enemies.push_back(Enemy(window, &orange_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 3, level));
                                }
                            else if(j == 7)
                                {
                                    enemies.push_back(Enemy(window, &grey_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 4, level));
                                }

                            else
                                {
                                    enemies.push_back(Enemy(window, &blue_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 1, level));
                                }
                        }
                }
        }

    else if(level == 5)
        {
            for(int j = 0; j < size_enemy_y; j++)
                {
                    for(int i = 0; i < how_many_columns_enemy; i++)
                        {
                            enemies.push_back(Enemy(window, &yellow_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 2, level));
                        }
                }
        }

    else if(level == 6)
        {
            for(int j = 0; j < size_enemy_y; j++)
                {
                    for(int i = 0; i < how_many_columns_enemy; i++)
                        {
                            if(j == 0 || j == 1 || j == 2 || j == 3)
                                {
                                    enemies.push_back(Enemy(window, &yellow_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 2, level));
                                }
                            else
                                {
                                    enemies.push_back(Enemy(window, &orange_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 3, level));
                                }
                        }
                }
        }

    else if(level == 7)
        {
            for(int j = 0; j < size_enemy_y; j++)
                {
                    for(int i = 0; i < how_many_columns_enemy; i++)
                        {
                            enemies.push_back(Enemy(window, &orange_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 3, level));
                        }
                }
        }

    else if(level == 8)
        {
            for(int j = 0; j < size_enemy_y; j++)
                {
                    for(int i = 0; i < how_many_columns_enemy; i++)
                        {
                            if(j == 0 || j == 1)
                                {
                                    enemies.push_back(Enemy(window, &grey_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 4, level));
                                }
                            else if(j == 4)
                                {
                                    enemies.push_back(Enemy(window, &green_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 5, level));
                                }

                            else
                                {
                                    enemies.push_back(Enemy(window, &orange_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 3, level));
                                }
                        }
                }
        }

    else if(level == 9)
        {
            for(int j = 0; j < size_enemy_y; j++)
                {
                    for(int i = 0; i < how_many_columns_enemy; i++)
                        {
                            if(j == 0 || j == 1 || j == 2 || j == 3 || j == 4 )
                                {
                                    enemies.push_back(Enemy(window, &grey_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 4, level));
                                }
                            else
                                {
                                    enemies.push_back(Enemy(window, &green_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 5, level));
                                }
                        }
                }
        }

    else if(level == 10)
        {
            for(int j = 0; j < size_enemy_y + 3; j++)
                {
                    for(int i = 0; i < how_many_columns_enemy; i++)
                        {
                            enemies.push_back(Enemy(window, &green_button, left_size, top_size, i, j, enemy_scale_x, enemy_scale_y, 5, level));
                        }
                }
        }
}

void Game_objects_ini::system(sf::RenderWindow &window, bool main_ball, bool board_left, bool board_right, bool bullet)
{
    this->game_over_time = game_over_clock.getElapsedTime();
    if(system_game_over == true)
        {
            game_over(window);
        }

    else
        {
            this->time_fun = clock_fun.getElapsedTime();
            this->time_end_level = clock_end_level.getElapsedTime();
            this->point_time = point_clock.getElapsedTime();
            if(enemies.size()!=0 && start_life != 0)
                {
                    if(main_ball == true)
                        {
                            space_press_index = true;
                            balls_start(window);
                            if(music_play == false)
                                {
                                    music.play();
                                    music_play = true;
                                }
                        }

                    if(board_left == true)
                        {
                            board_move_left(window);
                        }

                    if(board_right == true)
                        {
                            board_move_right(window);
                        }

                    if(bullet == true)
                        {
                            shooting_start(window);
                        }
                    ann_level = false;
                    ann_summary = false;
                    clock_end_level.restart();
                }

            else
                {
                    for(int i = 0; i < text_ann.size(); i++)
                        {
                            text_ann.erase(text_ann.begin(), text_ann.end());
                        }

                    for(int i = 0; i < enemies_die.size(); i++)
                        {
                            enemies_die.erase(enemies_die.begin(), enemies_die.end());
                        }

                    for(int i = 0; i < shots.size(); i++)
                        {
                            shots.erase(shots.begin(), shots.end());
                        }

                    for(int i = 0; i < balls.size(); i++)
                        {
                            balls.erase(balls.begin(), balls.end());
                        }

                    for(int i = 0; i < wall.size(); i++)
                        {
                            wall.erase(wall.begin(), wall.end());
                        }

                    for(int i = 0; i < bonuses.size(); i++)
                        {
                            bonuses.erase(bonuses.begin(), bonuses.end());
                        }

                    for(int i = 0; i < board_blocks.size(); i++)
                        {
                            board_blocks.erase(board_blocks.begin(), board_blocks.end());
                        }


                            if(ann_level == false)
                                {
                                    if(lvl_play == false && start_life > 0)
                                        {
                                            lvl_sound.play();
                                            lvl_play = true;
                                        }
                                    time_points_level_end = point_time.asSeconds();

                                    if(level < 10 && start_life > 0)
                                        {
                                            text_ann.push_back(Text_ini(window, &font_ann, "CONGRATULATIONS" , text_ann.size()));
                                            text_ann.push_back(Text_ini(window, &font_ann, "" , text_ann.size()));
                                            text_ann.push_back(Text_ini(window, &font_ann, "You finished " + std::to_string(level) + " level" , text_ann.size()));
                                        }
                                    else
                                        {
                                            text_ann.push_back(Text_ini(window, &font_ann, "GAME OVER" , text_ann.size()));
                                        }

                                }

                            if(start_life <= 0)
                                        {
                                            time_points_level_end = 200 * level;
                                        }

                            if(time_end_level.asSeconds() >= 3 && ann_summary == false)
                                {
                                    ann_level = true;
                                    text_ann.erase(text_ann.begin(), text_ann.end());
                                    summary.push_back(Summary(window, &font_points, your_point, level * 200 - time_points_level_end));
                                    ann_summary = true;
                                }

                            for(int i = 0; i < summary.size(); i++)
                                {
                                    if(time_fun.asMilliseconds() >= time_fun_temp && time_end_level.asSeconds() >= 4)
                                        {
                                            clock_fun.restart();
                                            if(summary[i].time_point_up(window) == false)
                                                {
                                                    summary[i].summary_point_up(window, (your_point, level * 200 - time_points_level_end) + your_point);
                                                    if(summary[i].summary_point_up(window, (your_point, level * 200 - time_points_level_end) + your_point) == false)
                                                        {
                                                            if(level < 10 && start_life > 0)
                                                                {
                                                                    if(summary[i].summary_move_to_points(window, points[0].posX(window), points[0].posY(window)) == false)
                                                                        {
                                                                            summary.erase(summary.begin(), summary.end());
                                                                            your_point = your_point + (level * 200 - time_points_level_end);
                                                                            text_ann.push_back(Text_ini(window, &font_ann, "PRESS 'SPACE' BUTTON TO START", text_ann.size()));
                                                                            level++;
                                                                            space_press_index = false;
                                                                            ball_speed++;
                                                                            if(ball_speed > 9)
                                                                                {
                                                                                    ball_speed = 9;
                                                                                }
                                                                            this->size_board_index = window.getSize().x/60;
                                                                            board_ini(window);
                                                                            balls_ini(window);
                                                                            enemies_ini(window);
                                                                            this->lvl_play = false;
                                                                        }

                                                                }
                                                            else
                                                                {
                                                                    game_over_clock.restart();
                                                                    system_game_over = true;
                                                                    text_ann.push_back(Text_ini(window, &font_ann, "PRESS 'SPACE' BUTTON TO continue", 15));
                                                                }

                                                        }
                                                }
                                        }
                                }
                }
        }
}

void Game_objects_ini::game_over(sf::RenderWindow &window)
{
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && summary[0].del_char(window) == false)
                {
                    for(int i = 0; i < text_ann.size(); i++)
                        {
                            text_ann.erase(text_ann.begin(), text_ann.end());
                        }

                    for(int i = 0; i < summary.size(); i++)
                        {
                            summary.erase(summary.begin(), summary.end());
                        }

                    for(int i = 0; i < points.size(); i++)
                        {
                            points.erase(points.begin(), points.end());
                        }

                    for(int i = 0; i < enemies_die.size(); i++)
                        {
                            enemies_die.erase(enemies_die.begin(), enemies_die.end());
                        }

                    for(int i = 0; i < shots.size(); i++)
                        {
                            shots.erase(shots.begin(), shots.end());
                        }

                    for(int i = 0; i < balls.size(); i++)
                        {
                            balls.erase(balls.begin(), balls.end());
                        }

                    for(int i = 0; i < wall.size(); i++)
                        {
                            wall.erase(wall.begin(), wall.end());
                        }

                    for(int i = 0; i < bonuses.size(); i++)
                        {
                            bonuses.erase(bonuses.begin(), bonuses.end());
                        }

                    for(int i = 0; i < board_blocks.size(); i++)
                        {
                            board_blocks.erase(board_blocks.begin(), board_blocks.end());
                        }

                    for(int i = 0; i < lifes.size(); i++)
                        {
                            lifes.erase(lifes.begin(), lifes.end());
                        }

                    for(int i = 0; i < enemies.size(); i++)
                        {
                            enemies.erase(enemies.begin(), enemies.end());
                        }
                    summary.push_back(Summary(window, &font_points));
                    system_game_over_ini = true;
                    music.pause();
                }


}

bool Game_objects_ini::space_press(sf::RenderWindow &window)
{
    return space_press_index;
}

int Game_objects_ini::points_out(sf::RenderWindow &window)
{
    return your_point;
}

bool Game_objects_ini::enter_name_bool(sf::RenderWindow &window)
{
    return system_game_over_ini;
}

int Game_objects_ini::enter_name_void(sf::RenderWindow &window, std::string name)
{
    if(summary.size() > 0)
        {
            return summary[0].insert_name(window, name).size();
        }
}

void Game_objects_ini::balls_start(sf::RenderWindow &window)
{
    for(int i = 0; i < balls.size(); i++)
        {
            balls[i].move_ball(window, (1 + balls[i].main_ball_radius_colision_out(window)) * balls[i].colision_main_ball_x(window), -1 * balls[i].colision_main_ball_y(window), ball_speed, 1);
        }

    colision_objects(window);
    colision_bonuses(window);
    bullets_colision(window);
}

void Game_objects_ini::bullets_colision(sf::RenderWindow &window)
{
    if(balls.size() == 0 && start_life == 0)
        {
            game_over(window);
        }

    points[0].points_update(window, your_point);

    for(int i = 0; i < shots.size(); i++)
        {
            shots[i].bullet_move(window);
        }

    for(int i = 0; i < shots.size(); i++)
        {
            if(shots[i].shot_pos_y(window) < 0)
               {
                   shots.erase(shots.begin() + i);
               }
        }

    for(int i = 0; i < shots.size(); i++)
        {
            for(int j = 0; j < enemies.size(); j++)
                {
                    if(shots[i].shot_pos_y(window) - 20 <= enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window) &&
                    shots[i].shot_pos_x(window) <= enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window) &&
                    shots[i].shot_pos_x(window) + shots[i].shot_global_x(window) >= enemies[j].enemy_pos_x(window))
                        {
                            enemies_die.push_back(Animations(window, &fire, (enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window)/2),
                                                                             (enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window)/2), enemies[j].HP_enemy_out(window)));
                            shots.erase(shots.begin() + i);
                            if(enemies[j].HP_enemy_reduce(window) <= 0)
                                {
                                    bonus_ini(window, enemies[j].enemy_bonus(window), enemies[j].enemy_punish(window),
                                    enemies[j].enemy_pos_x(window), enemies[j].enemy_pos_y(window));
                                    enemies.erase(enemies.begin() + j);
                                }
                            i--;
                            break;
                        }
                }
        }
    }


void Game_objects_ini::colision_objects(sf::RenderWindow &window)
{
    Save_load* difficulty = new Save_load;
    time_slow_board = clock_slow_board.getElapsedTime();
    if(time_slow_board.asSeconds() >= 5.0)
        {
            for(int i = 0; i < board_blocks.size(); i++)
                {
                    board_blocks[i].change_board_speed(window, false);
                }
        }

    if(balls.size()<=0)
            {
                start_life--;
                life_check_add(window);
                balls_ini(window);
            }
    for(int i = 0; i < balls.size(); i++)
        {
            for(int z = 0; z < wall.size(); z++)
                {
                    if(balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) >= wall[z].wall_position_y(window))
                       {
                           wall.erase(wall.begin(), wall.end());
                           balls[i].colision_main_ball_board(window, 0);
                           this->wall_size = 0;
                       }
                }


            if(balls[i].main_ball_position_y(window) > window.getSize().y)
                {
                    balls.erase(balls.begin() + i);
                    fail_ball_sound.play();
                }

            for(int j = 0; j < board_blocks.size(); j++)
                {
                    if(balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) > board_blocks[j].move_board_position_y(window) &&
                       balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) < board_blocks[j].move_board_position_y(window) + board_blocks[j].move_board_global_bounds_h(window) &&
                        balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window) > board_blocks[0].move_board_position_x(window) &&
                        balls[i].main_ball_position_x(window) < board_blocks[board_blocks.size() - 1].move_board_position_x(window) + board_blocks[j].move_board_global_bounds_w(window))
                        {
                            col_board_sound.play();
                            if(balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window)
                            > board_blocks[0].move_board_position_x(window) &&
                            balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window)
                            < board_blocks[0].move_board_position_x(window) + board_blocks[0].move_board_global_bounds_w(window))
                                {
                                    balls[i].error_ball(window, board_blocks[0].move_board_position_y(window));
                                    balls[i].main_ball_radius_colision_in(window, board_blocks[j].move_board_radius(window));
                                    balls[i].colision_main_ball_board_x(window);
                                    balls[i].colision_main_ball_board(window, 0);
                                    break;
                                }

                            if(balls[i].main_ball_position_x(window)
                            > board_blocks[board_blocks.size() - 1].move_board_position_x(window)&&
                            balls[i].main_ball_position_x(window)
                            < board_blocks[board_blocks.size() - 1].move_board_position_x(window) + board_blocks[board_blocks.size() - 1].move_board_global_bounds_w(window))
                                {
                                    balls[i].error_ball(window, board_blocks[0].move_board_position_y(window));
                                    balls[i].main_ball_radius_colision_in(window, board_blocks[j].move_board_radius(window));
                                    balls[i].colision_main_ball_board_x(window);
                                    balls[i].colision_main_ball_board(window, 0);
                                    break;
                                }
                            balls[i].error_ball(window, board_blocks[0].move_board_position_y(window));
                            balls[i].main_ball_radius_colision_in(window, board_blocks[j].move_board_radius(window));
                            balls[i].colision_main_ball_board(window, 0);
                            break;
                        }
                }
        }
    for(int i = 0; i < balls.size(); i++)
        {
            ball_real_speed_x = balls[i].main_ball_real_speed_x(window);
            ball_real_speed_y = balls[i].main_ball_real_speed_y(window);
            if(ball_real_speed_y < 0) { ball_real_speed_y = ball_real_speed_y * (-1); }
            if(ball_real_speed_x < 0) { ball_real_speed_x = ball_real_speed_x * (-1); }

                for(int j = 0; j < enemies.size(); j++)
                {

                    if(balls[i].main_ball_position_y(window) <= enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window) &&
                       balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) >=  enemies[j].enemy_pos_y(window) &&
                       balls[i].main_ball_position_x(window) <= enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window) &&
                       balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window) >= enemies[j].enemy_pos_x(window)         )
                        {
                            ball_enemy_sound.play();
                            if(balls[i].main_ball_position_y(window) <= enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window) &&
                               balls[i].main_ball_position_y(window) >= enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window) - ball_real_speed_y &&
                               balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window) >= enemies[j].enemy_pos_x(window) + ball_real_speed_x &&
                               balls[i].main_ball_position_x(window) <= enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window) - ball_real_speed_x)
                                    {
                                        balls[i].colision_main_ball_board(window, 0);
                                        enemies_die.push_back(Animations(window, &fire, (enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window)/2),
                                                                         (enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window)/2), enemies[j].HP_enemy_out(window)));
                                        if(enemies[j].HP_enemy_reduce(window) <= 0)
                                            {
                                                your_point = your_point + (enemies[j].HP_enemy_out(window) * difficulty->load_board_lvl(window, 3));
                                                bonus_ini(window, enemies[j].enemy_bonus(window), enemies[j].enemy_punish(window),
                                                          enemies[j].enemy_pos_x(window), enemies[j].enemy_pos_y(window));
                                                enemies.erase(enemies.begin() + j);
                                            }

                                        break;
                                    }

                            else if(balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) >= enemies[j].enemy_pos_y(window) &&
                                    balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) <= enemies[j].enemy_pos_y(window) + ball_real_speed_y &&
                                    balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window) >= enemies[j].enemy_pos_x(window) + ball_real_speed_x &&
                                    balls[i].main_ball_position_x(window) <= enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window) - ball_real_speed_x)
                                        {
                                            balls[i].colision_main_ball_board(window, 0);
                                            enemies_die.push_back(Animations(window, &fire, (enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window)/2),
                                                                             (enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window)/2), enemies[j].HP_enemy_out(window)));
                                            if(enemies[j].HP_enemy_reduce(window) <= 0)
                                            {
                                                your_point = your_point + (enemies[j].HP_enemy_out(window) * difficulty->load_board_lvl(window, 3));
                                                bonus_ini(window, enemies[j].enemy_bonus(window), enemies[j].enemy_punish(window),
                                                          enemies[j].enemy_pos_x(window), enemies[j].enemy_pos_y(window));
                                                enemies.erase(enemies.begin() + j);
                                            }

                                            break;
                                        }
                            else if(balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window) >= enemies[j].enemy_pos_x(window) &&
                                    balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window) <= enemies[j].enemy_pos_x(window) + ball_real_speed_x &&
                                    balls[i].main_ball_position_y(window) <= enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window) - ball_real_speed_y  &&
                                    balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) > enemies[j].enemy_pos_y(window) + ball_real_speed_y)
                                        {
                                            balls[i].colision_main_ball_board_x(window);
                                            enemies_die.push_back(Animations(window, &fire, (enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window)/2),
                                                                             (enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window)/2), enemies[j].HP_enemy_out(window)));
                                            if(enemies[j].HP_enemy_reduce(window) <= 0)
                                            {
                                                your_point = your_point + (enemies[j].HP_enemy_out(window) * difficulty->load_board_lvl(window, 3));
                                                bonus_ini(window, enemies[j].enemy_bonus(window), enemies[j].enemy_punish(window),
                                                          enemies[j].enemy_pos_x(window), enemies[j].enemy_pos_y(window));
                                                enemies.erase(enemies.begin() + j);
                                            }
                                            break;
                                        }
                            else if(balls[i].main_ball_position_x(window) <= enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window) &&
                                    balls[i].main_ball_position_x(window) >= enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window) - ball_real_speed_x &&
                                    balls[i].main_ball_position_y(window) <= enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window) - ball_real_speed_y  &&
                                    balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) > enemies[j].enemy_pos_y(window) + ball_real_speed_y)
                                        {
                                            balls[i].colision_main_ball_board_x(window);
                                            enemies_die.push_back(Animations(window, &fire, (enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window)/2),
                                                                             (enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window)/2), enemies[j].HP_enemy_out(window)));
                                            if(enemies[j].HP_enemy_reduce(window) <= 0)
                                            {
                                                your_point = your_point + (enemies[j].HP_enemy_out(window) * difficulty->load_board_lvl(window, 3));
                                                bonus_ini(window, enemies[j].enemy_bonus(window), enemies[j].enemy_punish(window),
                                                          enemies[j].enemy_pos_x(window), enemies[j].enemy_pos_y(window));
                                                enemies.erase(enemies.begin() + j);
                                            }
                                            break;
                                        }

                           else if(balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window) > enemies[j].enemy_pos_x(window) &&
                                        balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window) < enemies[j].enemy_pos_x(window) + ball_real_speed_x &&
                                        balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) > enemies[j].enemy_pos_y(window) &&
                                        balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) < enemies[j].enemy_pos_y(window) + ball_real_speed_y)
                                        {
                                            balls[i].colision_main_ball_board_x(window);
                                            balls[i].colision_main_ball_board(window, 0);
                                            enemies_die.push_back(Animations(window, &fire, (enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window)/2),
                                                                             (enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window)/2), enemies[j].HP_enemy_out(window)));
                                            if(enemies[j].HP_enemy_reduce(window) <= 0)
                                            {
                                                your_point = your_point + (enemies[j].HP_enemy_out(window) * difficulty->load_board_lvl(window, 3));
                                                bonus_ini(window, enemies[j].enemy_bonus(window), enemies[j].enemy_punish(window),
                                                          enemies[j].enemy_pos_x(window), enemies[j].enemy_pos_y(window));
                                                enemies.erase(enemies.begin() + j);
                                            }
                                            break;
                                        }

                           else if(balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window) > enemies[j].enemy_pos_x(window) &&
                                        balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window) < enemies[j].enemy_pos_x(window) + ball_real_speed_x &&
                                        balls[i].main_ball_position_y(window) < enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window) &&
                                        balls[i].main_ball_position_y(window) > enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window) - ball_real_speed_y)
                                        {
                                            balls[i].colision_main_ball_board_x(window);
                                            balls[i].colision_main_ball_board(window, 0);
                                            enemies_die.push_back(Animations(window, &fire, (enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window)/2),
                                                                             (enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window)/2), enemies[j].HP_enemy_out(window)));
                                            if(enemies[j].HP_enemy_reduce(window) <= 0)
                                            {
                                                your_point = your_point + (enemies[j].HP_enemy_out(window) * difficulty->load_board_lvl(window, 3));
                                                bonus_ini(window, enemies[j].enemy_bonus(window), enemies[j].enemy_punish(window),
                                                          enemies[j].enemy_pos_x(window), enemies[j].enemy_pos_y(window));
                                                enemies.erase(enemies.begin() + j);
                                            }
                                            break;
                                        }

                           else if(balls[i].main_ball_position_x(window) < enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window) &&
                                     balls[i].main_ball_position_x(window) > enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window) - ball_real_speed_x &&
                                     balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) > enemies[j].enemy_pos_y(window) &&
                                     balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) < enemies[j].enemy_pos_y(window) + ball_real_speed_y)
                                        {
                                            balls[i].colision_main_ball_board_x(window);
                                            balls[i].colision_main_ball_board(window, 0);
                                            enemies_die.push_back(Animations(window, &fire, (enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window)/2),
                                                                             (enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window)/2), enemies[j].HP_enemy_out(window)));
                                            if(enemies[j].HP_enemy_reduce(window) <= 0)
                                            {
                                                your_point = your_point + (enemies[j].HP_enemy_out(window) * difficulty->load_board_lvl(window, 3));
                                                bonus_ini(window, enemies[j].enemy_bonus(window), enemies[j].enemy_punish(window),
                                                          enemies[j].enemy_pos_x(window), enemies[j].enemy_pos_y(window));
                                                enemies.erase(enemies.begin() + j);
                                            }
                                            break;
                                        }

                           else if(balls[i].main_ball_position_x(window) < enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window) &&
                                     balls[i].main_ball_position_x(window) > enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window) - ball_real_speed_x &&
                                     balls[i].main_ball_position_y(window) < enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window) &&
                                     balls[i].main_ball_position_y(window) > enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window) - ball_real_speed_y)
                                        {
                                            balls[i].colision_main_ball_board_x(window);
                                            balls[i].colision_main_ball_board(window, 0);
                                            enemies_die.push_back(Animations(window, &fire, (enemies[j].enemy_pos_x(window) + enemies[j].enemy_global_w(window)/2),
                                                                             (enemies[j].enemy_pos_y(window) + enemies[j].enemy_global_h(window)/2), enemies[j].HP_enemy_out(window)));
                                            if(enemies[j].HP_enemy_reduce(window) <= 0)
                                            {
                                                your_point = your_point + (enemies[j].HP_enemy_out(window) * difficulty->load_board_lvl(window, 3));
                                                bonus_ini(window, enemies[j].enemy_bonus(window), enemies[j].enemy_punish(window),
                                                          enemies[j].enemy_pos_x(window), enemies[j].enemy_pos_y(window));
                                                enemies.erase(enemies.begin() + j);
                                            }
                                            break;
                                        }
                            }
                }
        }
    for(int i = 0; i < enemies_die.size(); i++)
        {
            if(enemies_die[i].animation_fire(window) == 1)
               enemies_die.erase(enemies_die.begin() + i);
        }

    for(int i = 0; i < text_ann.size(); i++)
        {
            if(text_ann[i].animation_text(window) == 0)
                {
                    text_ann.erase(text_ann.begin() + i);
                    for(int j = 0; j < text_ann.size(); j++)
                        {
                            text_ann[j].move_up(window);
                        }
                }
        }

    for(int i = 0; i < enemies.size(); i++)
          {
              enemies[i].enemy_update(window, &stage1, &stage2, &stage3, &stage4);
          }

    delete difficulty;
    difficulty = 0;
}

void Game_objects_ini::board_move_left(sf::RenderWindow &window)
{
    for(int i = 0; i < board_blocks.size(); i++)
        {
            board_blocks[i].move_board_left(window);

            if(board_blocks[0].move_board_position_x(window) == ((window.getSize().x/2) % 32) + 70)
                {
                    board_blocks[i].move_board_stop(window);
                }

            else if(board_blocks[0].move_board_position_x(window) < ((window.getSize().x/2) % 32) + 70)
                {
                    min_delete = board_blocks[0].move_board_check_left(window);
                    for(int j = 0; j < board_blocks.size(); j++)
                    {
                        board_blocks[j].move_board_reset_left(window, min_delete);
                    }
                }
        }
}

void Game_objects_ini::board_move_right(sf::RenderWindow &window)
{
    for(int i = 0; i < board_blocks.size(); i++)
        {

            board_blocks[i].move_board_right(window);

            if(board_blocks[board_blocks.size()-1].move_board_position_x(window) == window.getSize().x - (((window.getSize().x/2) % 32) + 80))
                {
                    board_blocks[i].move_board_stop(window);
                }

            else if(board_blocks[board_blocks.size()-1].move_board_position_x(window) > window.getSize().x - (((window.getSize().x/2) % 32) + 80))
                {
                    for(int j = 0; j < board_blocks.size(); j++)
                    {
                        board_blocks[j].move_board_reset_right(window, board_blocks[board_blocks.size()-1].move_board_check_right(window));
                    }
                    break;
                }
        }
}

void Game_objects_ini::object_setings(sf::RenderWindow &window)
{
    this->enemy_scale_x = window.getSize().x/3000.0;
    this->enemy_scale_y = window.getSize().y/2400.0;
    this->size_enemy_x = 190.0 * enemy_scale_x;
    this->size_enemy_y = 8;
    this->how_many_columns_enemy = ((window.getSize().x/2 - (2 * size_enemy_x))/size_enemy_x) * 2;
    this->min_delete = 0;
    this->top_size = 130;
    this->left_size = window.getSize().x/2 - ((how_many_columns_enemy % 2) * (size_enemy_x)/2) - how_many_columns_enemy/2*size_enemy_x;
    this->balls_temp_x = 0;
    this->balls_temp_y = 0;
    this->for_s = ball_speed;
    this->ball_real_speed_x = ball_speed;
    this->ball_real_speed_y = ball_speed;
    this->level = 1;
    this->position_board = window.getSize().x/2;
    this->size_board_index = window.getSize().x/60;
    this->reverse_ball_board = size_board_index/70.0;
    this->reverse_ball_board_temp = 0;
    this->wall_size = 0;

    Save_load best_score;
    points.push_back(Text_ini(window, &font_points, "00000000", "YOUR SCORE", posX_point, posY_point));
    points.push_back(Text_ini(window, &font_points, best_score.best_score(window), "BEST SCORE", posX_best, posY_best));

    this->max_lifes = 10;
    Save_load* difficulty = new Save_load;

    if(difficulty->load_board_lvl(window, 3) == 1)
        {
            this->start_life = 5;
            this->ball_speed = 2;
        }

    else if(difficulty->load_board_lvl(window, 3) == 2)
        {
            this->start_life = 4;
            this->ball_speed = 4;
        }

    else if(difficulty->load_board_lvl(window, 3) == 3)
        {
            this->start_life = 3;
            this->ball_speed = 6;
        }

    this->bonuses_index = 0;

    this->your_point = 0;
    this->time_fun_temp = 1;

    this->space_press_index = false;

    this->time_check = 0;
    this->shoot_enabled == false;
    this->level_end = false;
    this->ann_level = false;
    this->ann_summary = false;
    this->system_game_over = false;
    this->system_game_over_ini = false;
    this->music_play = false;
    this->lvl_play = false;

    board_ini(window);
    balls_ini(window);
    enemies_ini(window);
    life_ini(window);
    life_check_add(window);
    text_ann.push_back(Text_ini(window, &font_ann, "PRESS 'SPACE' BUTTON TO START", text_ann.size()));

    for(int i = 0; i < summary.size(); i++)
        {
            summary.erase(summary.begin(), summary.end());
        }

    delete difficulty;
    difficulty = 0;
}

void Game_objects_ini::bonus_ini(sf::RenderWindow &window, int bonus, int punish, int posX, int posY)
{
    switch(bonus)
        {
            case 1:  bonuses.push_back(Bonus(window, &fire_board, posX, posY, 1, bonus));    break;
            case 2:  bonuses.push_back(Bonus(window, &big_board, posX, posY, 1, bonus));    break;
            case 3:  bonuses.push_back(Bonus(window, &extra_ball, posX, posY, 1, bonus));    break;
            case 4:  bonuses.push_back(Bonus(window, &extra_life, posX, posY, 1, bonus));    break;
            case 5:  bonuses.push_back(Bonus(window, &board_botton, posX, posY, 1, bonus));    break;
            default: break;
        }

    switch(punish)
        {
            case 1001:  bonuses.push_back(Bonus(window, &small_board, posX + size_enemy_x/2, posY, 2, punish));    break;
            case 1002:  bonuses.push_back(Bonus(window, &random, posX + size_enemy_x/2, posY, 2, punish));    break;
            case 1003:  bonuses.push_back(Bonus(window, &random_small_big, posX + size_enemy_x/2, posY, 2, punish));    break;
            case 1004:  bonuses.push_back(Bonus(window, &slow_board, posX + size_enemy_x/2, posY, 2, punish));    break;
            default: break;
        }
}

void Game_objects_ini::shooting_start(sf::RenderWindow &window)
{
    time_shooting = clock_shooting.getElapsedTime();

    if(shoot_enabled == true)
        {
            if(time_shooting.asMilliseconds() <= 10000.0)
                {
                    if(time_shooting.asMilliseconds() > time_check)
                        {
                            for(int i = 0; i < board_blocks.size(); i++)
                                {
                                    if(i == 1)
                                        {
                                            shots.push_back(Shooting(window, &bullet, board_blocks[1].move_board_position_x(window), board_blocks[1].move_board_position_y(window)));
                                            shoot_sound.play();
                                        }

                                    if(i == board_blocks.size() - 2)
                                        {
                                            shots.push_back(Shooting(window, &bullet, board_blocks[board_blocks.size() - 2].move_board_position_x(window), board_blocks[board_blocks.size() - 2].move_board_position_y(window)));
                                        }
                                }
                            time_check = time_check + 700;
                        }
                }

            else
                {
                    shoot_enabled == false;
                }
        }

}

void Game_objects_ini::colision_bonuses(sf::RenderWindow &window)
{
    Save_load* difficulty = new Save_load;
    for(int i = 0; i < bonuses.size(); i++)
        {
            bonuses[i].move_bonus(window);
            bonuses_index = bonuses[i].random_bonus(window);
            for(int j = 0; j < board_blocks.size(); j++)
                {
                    if (bonuses[i].posY_bonus(window) + bonuses[i].global_y_bonus(window) > board_blocks[j].move_board_position_y(window) &&
                        bonuses[i].posY_bonus(window) + bonuses[i].global_y_bonus(window) < board_blocks[j].move_board_position_y(window) + board_blocks[j].move_board_global_bounds_h(window) &&
                        bonuses[i].posX_bonus(window) + bonuses[i].global_x_bonus(window) > board_blocks[0].move_board_position_x(window) &&
                        bonuses[i].posX_bonus(window) < board_blocks[board_blocks.size() - 1].move_board_position_x(window) + board_blocks[j].move_board_global_bounds_w(window))
                            {
                                bonus_sound.play();
                                for(int z = 0; z < 1; z++)
                                    {
                                        if(bonuses_index == 1)
                                            {
                                                your_point = your_point + (2 * difficulty->load_board_lvl(window, 3));
                                                text_ann.push_back(Text_ini(window, &font_ann, "Missles tun on, press right mouse button to use", text_ann.size()));
                                                clock_shooting.restart();
                                                time_check = 0;
                                                this->shoot_enabled = true;
                                            }

                                        else if(bonuses_index == 2)
                                            {
                                                your_point = your_point + (2 * difficulty->load_board_lvl(window, 3));
                                                text_ann.push_back(Text_ini(window, &font_ann, "Your board in growing up", text_ann.size()));
                                                position_board = board_blocks[0].move_board_position_x(window);
                                                board_blocks.erase(board_blocks.begin(), board_blocks.end());
                                                size_board_index = size_board_index + size_board_index/5;
                                                board_ini(window);
                                            }

                                        else if(bonuses_index == 3)
                                            {
                                                your_point = your_point + (2 * difficulty->load_board_lvl(window, 3));
                                                text_ann.push_back(Text_ini(window, &font_ann, "EXTRA BALL !!!", text_ann.size()));
                                                balls.push_back(Ball(window, &ball_red));
                                            }

                                        else if(bonuses_index == 4)
                                            {
                                                your_point = your_point + (2 * difficulty->load_board_lvl(window, 3));
                                                text_ann.push_back(Text_ini(window, &font_ann, "EXTRA LIFE !!!", text_ann.size()));
                                                start_life++;
                                                if(start_life >= 10)
                                                    {
                                                        start_life = 10;
                                                    }
                                                life_check_add(window);
                                            }

                                        else if(bonuses_index == 5)
                                            {
                                                your_point = your_point + (2 * difficulty->load_board_lvl(window, 3));
                                                text_ann.push_back(Text_ini(window, &font_ann, "WALL PROTECTED", text_ann.size()));
                                                for(int z = 0; z < how_many_walls; z++)
                                                    {
                                                        wall.push_back(Bonus(window, &wall_board, z, wall_begin_x, wall_begin_y, wall_scale_x));
                                                        wall_size = wall_size + wall[z].wall_global_x(window);
                                                    }
                                            }

                                        else if(bonuses_index == 1001)
                                            {
                                                your_point = your_point + (3 * difficulty->load_board_lvl(window, 3));
                                                text_ann.push_back(Text_ini(window, &font_ann, "Your board is shrinks", text_ann.size()));
                                                position_board = board_blocks[0].move_board_position_x(window);
                                                board_blocks.erase(board_blocks.begin(), board_blocks.end());
                                                size_board_index = size_board_index - size_board_index/5;
                                                board_ini(window);
                                            }

                                        else if(bonuses_index == 1002)
                                            {
                                                your_point = your_point + (3 * difficulty->load_board_lvl(window, 3));
                                                text_ann.push_back(Text_ini(window, &font_ann, "RANDOM !!!", text_ann.size()));
                                                int temp = ( std::rand() % 8 / level ) + 1;
                                                if(temp == 1)
                                                    {
                                                        bonuses_index = 1;
                                                        z--;
                                                    }

                                                else if(temp == 2)
                                                    {
                                                        bonuses_index = 2;
                                                        z--;
                                                    }

                                                else if(temp == 3)
                                                    {
                                                        bonuses_index = 3;
                                                        z--;
                                                    }

                                                else if(temp == 4)
                                                    {
                                                        bonuses_index = 4;
                                                        z--;
                                                    }

                                                else if(temp == 5)
                                                    {
                                                        bonuses_index = 5;
                                                        z--;
                                                    }

                                                else if(temp == 6)
                                                    {
                                                        bonuses_index = 1001;
                                                        z--;
                                                    }

                                                else if(temp == 7)
                                                    {
                                                        bonuses_index = 1003;
                                                        z--;
                                                    }

                                                else if(temp == 8)
                                                    {
                                                        bonuses_index = 1;
                                                        z--;
                                                    }
                                            }

                                        else if(bonuses_index == 1003)
                                            {
                                                your_point = your_point + (3 * difficulty->load_board_lvl(window, 3));
                                                text_ann.push_back(Text_ini(window, &font_ann, "RANDOM small or big board", text_ann.size()));
                                                int temp = ( std::rand() % 2 / level ) + 1;
                                                if(temp == 1)
                                                    {
                                                        bonuses_index = 2;
                                                        z--;
                                                    }

                                                else if(temp == 2)
                                                    {
                                                        bonuses_index = 1001;
                                                        z--;
                                                    }
                                            }

                                        else if(bonuses_index == 1004)
                                            {
                                                your_point = your_point + (3 * difficulty->load_board_lvl(window, 3));
                                                text_ann.push_back(Text_ini(window, &font_ann, "SLOW BOARD !!!", text_ann.size()));
                                                for(int a = 0; a < board_blocks.size(); a++)
                                                {
                                                    clock_slow_board.restart();
                                                    board_blocks[a].change_board_speed(window, true);
                                                }
                                            }
                                    }
                                    bonuses.erase(bonuses.begin() + i);
                                    break;
                                }

                    if (bonuses[i].posY_bonus(window) > window.getSize().y - bonuses[i].global_y_bonus(window)*2)
                           {
                               your_point = your_point - 3;
                               bonuses.erase(bonuses.begin() + i);
                               break;
                           }
                }
        }

    delete difficulty;
    difficulty = 0;
}

void Game_objects_ini::sound_ini(sf::RenderWindow &window)
{
    //----------------------------- MUSIC IN BACK ------------------------------
    music.openFromFile("Sounds/music.wav");
    music.setLoop(true);
	music.setVolume(30);
    //----------------------------- COLLISION BOARD ----------------------------
    col_board.loadFromFile("Sounds/collision_board.wav");
    col_board_sound.setBuffer(col_board);
    //----------------------------- COLLISION ENEMY ----------------------------
    ball_enemy.loadFromFile("Sounds/collision_enemy.wav");
    ball_enemy_sound.setBuffer(ball_enemy);
    //----------------------------- FAIL BALL ----------------------------------
    fail_ball.loadFromFile("Sounds/ball_fail.wav");
    fail_ball_sound.setBuffer(fail_ball);
    //----------------------------- BONUS ----------------------------------
    bonus_buff.loadFromFile("Sounds/bonus.wav");
    bonus_sound.setBuffer(bonus_buff);
    //----------------------------- SHOOTING ----------------------------------
    shoot_buff.loadFromFile("Sounds/shooting.wav");
    shoot_sound.setBuffer(shoot_buff);
    //----------------------------- LEVEL FINISH ----------------------------------
    lvl_buff.loadFromFile("Sounds/level.wav");
    lvl_sound.setBuffer(lvl_buff);
}


void Game_objects_ini::draw_game_objects(sf::RenderWindow &window)
{
    for(int i = 0; i < board_blocks.size(); i++)
        {
            board_blocks[i].draw_board(window);
        }

    for(int i = 0; i < enemies.size(); i++)
        {
            enemies[i].draw_enemy_main(window);
        }

    for(int i = 0; i < balls.size(); i++)
        {
            balls[i].draw_ball(window);
        }

    for(int i = 0; i < enemies_die.size(); i++)
        {
            enemies_die[i].draw_animation_death(window);
        }

    for(int i = 0; i < bonuses.size(); i++)
        {
            bonuses[i].draw_bonus(window);
        }

    for(int i = 0; i < wall.size(); i++)
        {
            wall[i].draw_bonus(window);
        }

    for(int i = 0; i < lifes.size(); i++)
        {
            lifes[i].draw_life(window);
        }

    for(int i = 0; i < shots.size(); i++)
        {
            shots[i].draw_shot(window);
        }

    for(int i = 0; i < text_ann.size(); i++)
        {
            text_ann[i].draw_text(window);
        }

    for(int i = 0; i < summary.size(); i++)
        {
            summary[i].draw_summary(window);
        }

    for(int i = 0; i < points.size(); i++)
        {
            points[i].draw_text(window);
        }
}
