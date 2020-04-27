#include "game_objects_ini.h"


Game_objects_ini::Game_objects_ini(sf::RenderWindow &window)
{
    this->player_left_green.loadFromFile("Textures/player-left-green.png");
    this->player_middle_green.loadFromFile("Textures/player-middle-green.png");
    this->player_right_green.loadFromFile("Textures/player-right-green.png");
    this->ini_index_left = false;
    this->ini_index_right = false;
    this->min_delete = 0;

    board_ini(window, &player_left_green, &player_middle_green, &player_right_green, window.getSize().x/50d);
}


Game_objects_ini::~Game_objects_ini(){}

void Game_objects_ini::board_ini(sf::RenderWindow &window, sf::Texture *left_tex, sf::Texture *mid_tex, sf::Texture *right_tex, int size_board)
{
    for(int i = 0; i < size_board; i++)
        {
            if(i==0){board_blocks.push_back(Boards(window, left_tex, i));}
            else if(i>0 && i < size_board - 1){board_blocks.push_back(Boards(window, mid_tex, i));}
            else if(i==size_board - 1){board_blocks.push_back(Boards(window, right_tex, i));}
        }
}

void Game_objects_ini::board_move_left(sf::RenderWindow &window)
{
    for(int i = 0; i < board_blocks.size(); i++)
        {
            board_blocks[i].move_board_left(window);

            if(board_blocks[0].move_board_position(window) == ((window.getSize().x/2) % 32) + 70)
                {
                    board_blocks[i].move_board_stop(window);
                }

            else if(board_blocks[0].move_board_position(window) < ((window.getSize().x/2) % 32) + 70)
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

            if(board_blocks[board_blocks.size()-1].move_board_position(window) == window.getSize().x - (((window.getSize().x/2) % 32) + 80))
                {
                    board_blocks[i].move_board_stop(window);
                }

            else if(board_blocks[board_blocks.size()-1].move_board_position(window) > window.getSize().x - (((window.getSize().x/2) % 32) + 80))
                {
                    for(int j = 0; j < board_blocks.size(); j++)
                    {
                        board_blocks[j].move_board_reset_right(window, board_blocks[board_blocks.size()-1].move_board_check_right(window));
                    }
                    break;
                }
        }
}

void Game_objects_ini::draw_game_objects(sf::RenderWindow &window)
{
    for(int i = 0; i < board_blocks.size(); i++)
        {
            board_blocks[i].draw_board(window);
        }
}
