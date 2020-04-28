#include "game_objects_ini.h"


Game_objects_ini::Game_objects_ini(sf::RenderWindow &window)
{

    this->player_left_green.loadFromFile("Textures/player-left-green.png");
    this->player_middle_green.loadFromFile("Textures/player-middle-green.png");
    this->player_right_green.loadFromFile("Textures/player-right-green.png");

    this->ball_red.loadFromFile("Textures/ball-red.png");


    this->ini_index_left = false;
    this->ini_index_right = false;
    this->min_delete = 0;
    object_setings(window);

    board_ini(window, &player_left_green, &player_middle_green, &player_right_green, size_board_index);
    balls_ini(window, &ball_red);
}


Game_objects_ini::~Game_objects_ini(){}


void Game_objects_ini::board_ini(sf::RenderWindow &window, sf::Texture *left_tex, sf::Texture *mid_tex, sf::Texture *right_tex, int size_board)
{
    for(int i = 0; i < size_board; i++)
        {
            if(i<=size_board/2)
                {
                    this->reverse_ball_board_temp = reverse_ball_board_temp + reverse_ball_board;
                }

            else
                {
                    this->reverse_ball_board_temp = reverse_ball_board_temp - reverse_ball_board;
                }

            if(i==0){board_blocks.push_back(Boards(window, left_tex, i, reverse_ball_board_temp));}
            else if(i>0 && i < size_board - 1){board_blocks.push_back(Boards(window, mid_tex, i, reverse_ball_board_temp));}
            else if(i==size_board - 1){board_blocks.push_back(Boards(window, right_tex, i, reverse_ball_board_temp));}
        }
}

void Game_objects_ini::balls_ini(sf::RenderWindow &window, sf::Texture *texture)
{
    balls.push_back(Ball(window, texture));
}

void Game_objects_ini::system(sf::RenderWindow &window, bool main_ball, bool board_left, bool board_right)
{
    if(main_ball == true)
        {
            balls_start(window);
        }
    if(board_left == true)
        {
            board_move_left(window);
        }
    if(board_right == true)
        {
            board_move_right(window);
        }
}

void Game_objects_ini::balls_start(sf::RenderWindow &window)
{
    for(int i = 0; i < balls.size(); i++)
        {
            balls[i].move_ball(window, (1 + balls[i].main_ball_radius_colision_out(window)) * balls[i].colision_main_ball_x(window), - 1 * balls[i].colision_main_ball_y(window), 3, 1);
            colision_objects(window);
        }
}

void Game_objects_ini::colision_objects(sf::RenderWindow &window)
{
    for(int i = 0; i < balls.size(); i++)
        {
            for(int j = 0; j < board_blocks.size(); j++)
                {
                    if(balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) > board_blocks[j].move_board_position_y(window) &&
                       balls[i].main_ball_position_y(window) + balls[i].main_ball_global_bounds_h(window) < board_blocks[j].move_board_position_y(window) + board_blocks[j].move_board_global_bounds_h(window) &&
                        balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window) > board_blocks[0].move_board_position_x(window) &&
                        balls[i].main_ball_position_x(window) < board_blocks[board_blocks.size() - 1].move_board_position_x(window) + board_blocks[j].move_board_global_bounds_w(window))
                        {
                            if(balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window)
                            > board_blocks[0].move_board_position_x(window) &&
                            balls[i].main_ball_position_x(window) + balls[i].main_ball_global_bounds_w(window)
                            < board_blocks[0].move_board_position_x(window) + board_blocks[0].move_board_global_bounds_w(window))
                                {
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
                                    balls[i].main_ball_radius_colision_in(window, board_blocks[j].move_board_radius(window));
                                    balls[i].colision_main_ball_board_x(window);
                                    balls[i].colision_main_ball_board(window, 0);
                                    break;
                                }
                            balls[i].main_ball_radius_colision_in(window, board_blocks[j].move_board_radius(window));
                            balls[i].colision_main_ball_board(window, 0);
                            break;
                        }
                }
        }
}

float Game_objects_ini::board_blocks_radius(sf::RenderWindow &window)
{

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
    this->size_board_index = window.getSize().x/60;
    this->reverse_ball_board = size_board_index/70.0;
    this->reverse_ball_board_temp = 0;
}

void Game_objects_ini::draw_game_objects(sf::RenderWindow &window)
{
    for(int i = 0; i < board_blocks.size(); i++)
        {
            board_blocks[i].draw_board(window);
        }

    for(int i = 0; i < balls.size(); i++)
        {
            balls[i].draw_ball(window);
        }

}
