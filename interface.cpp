#include "interface.h"



Interface::Interface(sf::RenderWindow &window)
{
    this->backgroud.loadFromFile("Textures/background2.jpg");
    this->board_corner.loadFromFile("Textures/board-corner.png");
    this->board_block_light.loadFromFile("Textures/board-block-light.png");
    this->board_block.loadFromFile("Textures/board-block.png");
    this->board_connect.loadFromFile("Textures/board-connect.png");

    this->score_left.loadFromFile("Textures/score-left.png");
    this->score_middle.loadFromFile("Textures/score-middle.png");
    this->score_right.loadFromFile("Textures/score-right.png");

    this->corner_board.loadFromFile("Textures/corner-board.png");
    this->middle.loadFromFile("Textures/middle.png");
    this->middle_board.loadFromFile("Textures/middle-board.png");


    this->backgroud_inter.setTexture(backgroud);

    this->center_x = window.getSize().x/2;
    this->center_y = window.getSize().y/2;
    this->size_block = 32;
    this->start_draw_x = (center_x % size_block) + (size_block*2);
    this->end_draw_x = window.getSize().x - ((center_x % size_block) + (size_block*3));
    this->start_draw_y = (center_y % size_block) + (size_block*2);
    this->end_draw_y = window.getSize().y - ((center_y % size_block) + (size_block*2));
    this->check_size_index = (window.getSize().x/250 + 2) * 32 * 3 + 74*2 + 42*2 + 200;

    for(int j = start_draw_y; j <= window.getSize().y + 32; j = j + 32)
            {
                for(int i = start_draw_x; i <= end_draw_x; i = i + 32)
                    {
                        if(i == start_draw_x && j == start_draw_y)
                            {
                                squares.push_back(Backgroung_game(&corner_board, i, j, 0, window));
                            }
                        else if((i > start_draw_x) && end_draw_x > i && j == start_draw_y)
                            {
                                squares.push_back(Backgroung_game(&middle_board, i, j, 0, window));
                            }
                        else if(i == end_draw_x && j == start_draw_y)
                            {
                                i = i + 32;
                                squares.push_back(Backgroung_game(&corner_board, i, j, 90, window));
                            }
                        else if(i == start_draw_x && j > start_draw_y)
                            {
                                squares.push_back(Backgroung_game(&middle_board, i, j + 32, -90, window));
                            }
                        else if(i == end_draw_x && j > start_draw_y)
                            {
                                i = i + 32;
                                squares.push_back(Backgroung_game(&middle_board, i, j, 90, window));
                            }
                        else if(i > start_draw_x && i < end_draw_x && j > start_draw_y)
                            {
                                squares.push_back(Backgroung_game(&middle, i, j, 0, window));
                            }
                    }
            }

    for(int i = 72; i <= window.getSize().x - 60; i = i + 12)
        {
            connect_board.push_back(Backgroung_game(window, &board_connect, i, 36, 90));
        }
    for(int i = 72; i <= window.getSize().y + 30; i = i + 12)
        {
            connect_board.push_back(Backgroung_game(window, &board_connect, 36, i, 0));
            connect_board.push_back(Backgroung_game(window, &board_connect, window.getSize().x - 36, i, 0));
        }

    corners.push_back(Backgroung_game(&board_corner, 0, 0, 0));
    corners.push_back(Backgroung_game(&board_corner, 90, window.getSize().x, 0));

    interface_items.push_back(Backgroung_game(window, &score_left, &score_middle, &score_right, window.getSize().x/4, 34, window.getSize().x/250)); //score place
    interface_items.push_back(Backgroung_game(window, &score_left, &score_middle, &score_right, window.getSize().x/2, 34, window.getSize().x/250)); //score place 2
    interface_items.push_back(Backgroung_game(window, &score_left, &score_middle, &score_right, window.getSize().x/4*3, 34, window.getSize().x/250)); //score place 3

    quads.push_back(Backgroung_game(&board_block_light, 72, 0));
    quads.push_back(Backgroung_game(&board_block_light, window.getSize().x - 116, 0));

    for(int i = 72; i <= window.getSize().y - 30; i = i + 132)
        {
            quads.push_back(Backgroung_game(&board_block_light, 15, i));
            quads.push_back(Backgroung_game(&board_block_light, window.getSize().x - 59, i));

            quads.push_back(Backgroung_game(&board_block, 15, i + 66));
            quads.push_back(Backgroung_game(&board_block, window.getSize().x - 59, i + 66));
        }

    if(check_size_index <= window.getSize().x)
    {
        quads.push_back(Backgroung_game(&board_block_light, window.getSize().x/8 - 22, 0));
        quads.push_back(Backgroung_game(&board_block_light, window.getSize().x/8*7 - 22, 0));
        quads.push_back(Backgroung_game(&board_block, window.getSize().x/8*3 - 22, 0));
        quads.push_back(Backgroung_game(&board_block, window.getSize().x/8*5 - 22, 0));
        if(check_size_index + 500 <= window.getSize().x)
            {
                quads.push_back(Backgroung_game(&board_block, (window.getSize().x/8 - 94)/2 + 72, 0));
                quads.push_back(Backgroung_game(&board_block, (window.getSize().x - 116 - window.getSize().x/8*7 - 22)/2 + window.getSize().x/8*7, 0));
            }
    }
}

Interface:: ~Interface(){}


int Interface::posX_middle(sf::RenderWindow &window, int place)
{
    return interface_items[place].posX_middle(window);
}

int Interface::posY_middle(sf::RenderWindow &window, int place)
{
    return interface_items[place].posY_middle(window);
}

int Interface::global_X_middle(sf::RenderWindow &window, int place)
{
    return interface_items[place].global_X_middle(window);
}

int Interface::global_Y_middle(sf::RenderWindow &window, int place)
{
    return interface_items[place].global_Y_middle(window);
}

void Interface::draw_interface(sf::RenderWindow &window)
{
    window.draw(backgroud_inter);
    for(int i = 0; i < connect_board.size(); i++)
        {
            connect_board[i].draw_backgroud_connector(window);
        }

    for(int i = 0; i < corners.size(); i++)
        {
            corners[i].draw_backgroud_corners(window);
        }

    for(int i = 0; i < quads.size(); i++)
        {
            quads[i].draw_backgroud_quads(window);
        }

    for(int i = 0; i < squares.size(); i++)
        {
            squares[i].draw_backgroud_square(window);
        }

    interface_items[0].draw_backgroud_game(window);
    interface_items[1].draw_backgroud_game(window);
    interface_items[2].draw_backgroud_game(window);
}
