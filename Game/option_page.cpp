#include "option_page.h"
#include <windows.h>

Option_page::Option_page(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
                                :save_setings()
{
    this->otama_font.loadFromFile("Fonts/otama.otf");
    this->nice_font.loadFromFile("Fonts/Honor_med.ttf");
    this->center_x = window.getSize().x/2;
    this->center_y = window.getSize().y/2;
    this->size_block = 32;
    this->start_draw_x = (center_x % size_block) + (size_block*3);
    this->end_draw_x = window.getSize().x - ((center_x % size_block) + (size_block*3));
    this->start_draw_y = (center_y % size_block) + (size_block*3);
    this->end_draw_y = window.getSize().y - ((center_y % size_block) + (size_block*3));
    this->width_screen = window.getSize().x - ((center_x % size_block) + (size_block*3)*2);
    this->height_screen = window.getSize().y - ((center_y % size_block) + (size_block*3)*2);
    this->no_blocks_x = width_screen/size_block;
    this->no_blocks_y = height_screen/size_block;
    this->no_parts = 10;
    this->menu_option_menu_page = 3;
    this->animation = false;

    this->block_texture_corner.loadFromFile("Textures/corner-board.png");
    this->block_texture_middle.loadFromFile("Textures/middle.png");
    this->block_texture_board.loadFromFile("Textures/middle-board.png");

    this->player_left.loadFromFile("Textures/player-left-red.png");
    this->player_middle.loadFromFile("Textures/player-middle-red.png");
    this->player_right.loadFromFile("Textures/player-right-red.png");

    this->player_left_green.loadFromFile("Textures/player-left-green.png");
    this->player_middle_green.loadFromFile("Textures/player-middle-green.png");
    this->player_right_green.loadFromFile("Textures/player-right-green.png");

    this->player_left_yellow.loadFromFile("Textures/player-left-yellow.png");
    this->player_middle_yellow.loadFromFile("Textures/player-middle-yellow.png");
    this->player_right_yellow.loadFromFile("Textures/player-right-yellow.png");

    this->button_null.loadFromFile("Textures/button_null.png");
    this->button_true.loadFromFile("Textures/button_true.png");

    settings_ini(window);

    this->position_nice_font_x = end_draw_x;
    this->position_nice_font_y = save_button.getPosition().y;
    this->annoucment = 0;
//--------------------------------------------------------------------RESET SETINGS-------------------------------------------------------------------------------------

    reset_object(window, mouse, menu_option);
}

void Option_page::settings_ini(sf::RenderWindow &window)
{
    //---------------------------------------------------------------------------SETTINGS LOAD FROM FILE-------------------------------------------------------------------------
    Save_load load_seting_options;
    for(int i = 0; i < 5; i++)
        {
            this->settings_tab[i] = load_seting_options.load_setings(i);
        }
    //----------------------------------------------------------------------------------BACKGROUND BLOCKS INI---------------------------------------------------------------------

    this->block.setColor(sf::Color(180, 180, 180, 240));
    this->block.setPosition(start_draw_x, start_draw_y);
    this->block.setOrigin (size_block/2, size_block/2);

//---------------------------------------------------------------------------------SEPERATE LINE-----------------------------------------------------------------------------
    this->line1.setSize(sf::Vector2f(width_screen - 5, 2));
    this->line1.setPosition(window.getSize().x/2 - line1.getGlobalBounds().width/2, height_screen/5 + start_draw_y);
    this->line1.setFillColor(sf::Color(144, 77, 0));
    this->line1.setOutlineThickness(1);
    this->line1.setOutlineColor(sf::Color(0, 0, 0));
    line3 = line2 = line1;
    this->line2.setPosition(line1.getPosition().x, start_draw_y + height_screen/5*2);
    this->line3.setPosition(line1.getPosition().x, start_draw_y + height_screen/5*3);

//---------------------------------------------------------------------------------SCREEN RESOLUTION MODE-----------------------------------------------------------------------------
    this->screen_resolution.setFont(otama_font);
    this->screen_resolution.setCharacterSize(window.getSize().x/35 - 5);
    this->screen_resolution.setFillColor(sf::Color(255, 255, 255));
    this->screen_resolution.setString("Screen resolution");
    this->screen_resolution.setOutlineThickness(2);
    this->screen_resolution.setOutlineColor(sf::Color(0, 0, 0));
    this->screen_resolution.setPosition(width_screen/2 - screen_resolution.getGlobalBounds().width/2 + start_draw_x, start_draw_y + 10);

    this->screen_resolution640x800.setFont(otama_font);
    this->screen_resolution640x800.setCharacterSize(window.getSize().x/35);
    this->screen_resolution640x800.setFillColor(sf::Color(255, 255, 255));
    this->screen_resolution640x800.setString("640x800");
    this->screen_resolution640x800.setOutlineThickness(1);
    this->screen_resolution640x800.setOutlineColor(sf::Color(0, 0, 0));
    this->screen_resolution640x800.setPosition(start_draw_x + (width_screen/3)/2 - screen_resolution640x800.getGlobalBounds().width/2, screen_resolution.getPosition().y + window.getSize().y/60 + screen_resolution.getGlobalBounds().height);

    this->screen_resolution800x1000.setFont(otama_font);
    this->screen_resolution800x1000.setCharacterSize(window.getSize().x/35);
    this->screen_resolution800x1000.setFillColor(sf::Color(255, 255, 255));
    this->screen_resolution800x1000.setString("800x1000");
    this->screen_resolution800x1000.setOutlineThickness(1);
    this->screen_resolution800x1000.setOutlineColor(sf::Color(0, 0, 0));
    this->screen_resolution800x1000.setPosition(start_draw_x + (width_screen/3)/2 + width_screen/3 - screen_resolution800x1000.getGlobalBounds().width/2, screen_resolution640x800.getPosition().y);

    this->screen_resolution960x1200.setFont(otama_font);
    this->screen_resolution960x1200.setCharacterSize(window.getSize().x/35);
    this->screen_resolution960x1200.setFillColor(sf::Color(255, 255, 255));
    this->screen_resolution960x1200.setString("960x1200");
    this->screen_resolution960x1200.setOutlineThickness(1);
    this->screen_resolution960x1200.setOutlineColor(sf::Color(0, 0, 0));
    this->screen_resolution960x1200.setPosition(start_draw_x + (width_screen/3)/2 + width_screen/3*2 - screen_resolution960x1200.getGlobalBounds().width/2, screen_resolution640x800.getPosition().y);

    if(settings_tab[0] == 640)
        {
            this->button800x600_true.setTexture(button_true);
            this->button1280x1024_true.setTexture(button_null);
            this->button1920x1080_true.setTexture(button_null);
        }
    else if (settings_tab[0] == 800)
        {
            this->button800x600_true.setTexture(button_null);
            this->button1280x1024_true.setTexture(button_true);
            this->button1920x1080_true.setTexture(button_null);
        }
    else if (settings_tab[0] == 960)
        {
            this->button800x600_true.setTexture(button_null);
            this->button1280x1024_true.setTexture(button_null);
            this->button1920x1080_true.setTexture(button_true);
        }

    this->button800x600_true.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->button800x600_true.setPosition(screen_resolution640x800.getPosition().x - 5 - button800x600_true.getGlobalBounds().width, screen_resolution640x800.getPosition().y + button800x600_true.getGlobalBounds().height);


    this->button1280x1024_true.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->button1280x1024_true.setPosition(screen_resolution800x1000.getPosition().x - 5 - button1280x1024_true.getGlobalBounds().width, screen_resolution800x1000.getPosition().y + button1280x1024_true.getGlobalBounds().height);


    this->button1920x1080_true.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->button1920x1080_true.setPosition(screen_resolution960x1200.getPosition().x - 5 - button1920x1080_true.getGlobalBounds().width, screen_resolution960x1200.getPosition().y + button1920x1080_true.getGlobalBounds().height);

//---------------------------------------------------------------------------------SCREEN MODE-----------------------------------------------------------------------------
    this->game_mode.setFont(otama_font);
    this->game_mode.setCharacterSize(window.getSize().x/35 - 5);
    this->game_mode.setFillColor(sf::Color(255, 255, 255));
    this->game_mode.setString("Game mode");
    this->game_mode.setOutlineThickness(2);
    this->game_mode.setOutlineColor(sf::Color(0, 0, 0));
    this->game_mode.setPosition(width_screen/2 - game_mode.getGlobalBounds().width/2 + start_draw_x, line1.getPosition().y + 10);

    this->easy_mode.setFont(otama_font);
    this->easy_mode.setCharacterSize(window.getSize().x/35);
    this->easy_mode.setFillColor(sf::Color(255, 255, 255));
    this->easy_mode.setString("Easy");
    this->easy_mode.setOutlineThickness(1);
    this->easy_mode.setOutlineColor(sf::Color(0, 0, 0));
    this->easy_mode.setPosition(start_draw_x + (width_screen/3)/2 - easy_mode.getGlobalBounds().width/2, game_mode.getPosition().y + window.getSize().y/60 + game_mode.getGlobalBounds().height);

    this->normal.setFont(otama_font);
    this->normal.setCharacterSize(window.getSize().x/35);
    this->normal.setFillColor(sf::Color(255, 255, 255));
    this->normal.setString("Normal");
    this->normal.setOutlineThickness(1);
    this->normal.setOutlineColor(sf::Color(0, 0, 0));
    this->normal.setPosition(start_draw_x + width_screen/3*2 - (width_screen/6) - normal.getGlobalBounds().width/2, game_mode.getPosition().y + window.getSize().y/60 + game_mode.getGlobalBounds().height);

    this->hard_mode.setFont(otama_font);
    this->hard_mode.setCharacterSize(window.getSize().x/35);
    this->hard_mode.setFillColor(sf::Color(255, 255, 255));
    this->hard_mode.setString("Hard");
    this->hard_mode.setOutlineThickness(1);
    this->hard_mode.setOutlineColor(sf::Color(0, 0, 0));
    this->hard_mode.setPosition(start_draw_x + width_screen - (width_screen/3)/2 - hard_mode.getGlobalBounds().width/2, game_mode.getPosition().y + window.getSize().y/60 + game_mode.getGlobalBounds().height);

    if(settings_tab[2] == 1)
        {
            this->easy_sprite.setTexture(button_true);
            this->normal_sprite.setTexture(button_null);
            this->hard_sprite.setTexture(button_null);
        }

    else if (settings_tab[2] == 2)
        {
            this->easy_sprite.setTexture(button_null);
            this->normal_sprite.setTexture(button_true);
            this->hard_sprite.setTexture(button_null);
        }

    else if (settings_tab[2] == 3)
        {
            this->easy_sprite.setTexture(button_null);
            this->normal_sprite.setTexture(button_null);
            this->hard_sprite.setTexture(button_true);
        }

    this->easy_sprite.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->easy_sprite.setPosition(easy_mode.getPosition().x - 5 - easy_sprite.getGlobalBounds().width, easy_mode.getPosition().y + easy_sprite.getGlobalBounds().height);

    this->normal_sprite.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->normal_sprite.setPosition(normal.getPosition().x - 5 - normal_sprite.getGlobalBounds().width, normal.getPosition().y + normal_sprite.getGlobalBounds().height);

    this->hard_sprite.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->hard_sprite.setPosition(hard_mode.getPosition().x - 5 - hard_sprite.getGlobalBounds().width, hard_mode.getPosition().y + hard_sprite.getGlobalBounds().height);


//---------------------------------------------------------------------------------HIGH SCORE OPTION-----------------------------------------------------------------------------
    this->high_score.setFont(otama_font);
    this->high_score.setCharacterSize(window.getSize().x/35 - 5);
    this->high_score.setFillColor(sf::Color(255, 255, 255));
    this->high_score.setString("High score");
    this->high_score.setOutlineThickness(2);
    this->high_score.setOutlineColor(sf::Color(0, 0, 0));
    this->high_score.setPosition(width_screen/2 - high_score.getGlobalBounds().width/2 + start_draw_x, line2.getPosition().y + 10);

    this->high_score_no_1.setFont(otama_font);
    this->high_score_no_1.setCharacterSize(window.getSize().x/35);
    this->high_score_no_1.setFillColor(sf::Color(255, 255, 255));
    this->high_score_no_1.setString("One best");
    this->high_score_no_1.setOutlineThickness(1);
    this->high_score_no_1.setOutlineColor(sf::Color(0, 0, 0));
    this->high_score_no_1.setPosition(start_draw_x + (width_screen/3)/2 - high_score_no_1.getGlobalBounds().width/2, high_score.getPosition().y + window.getSize().y/60 + high_score.getGlobalBounds().height);

    this->high_score_no_3.setFont(otama_font);
    this->high_score_no_3.setCharacterSize(window.getSize().x/35);
    this->high_score_no_3.setFillColor(sf::Color(255, 255, 255));
    this->high_score_no_3.setString("Three best");
    this->high_score_no_3.setOutlineThickness(1);
    this->high_score_no_3.setOutlineColor(sf::Color(0, 0, 0));
    this->high_score_no_3.setPosition(start_draw_x + (width_screen/3)/2 + width_screen/3 - high_score_no_3.getGlobalBounds().width/2, high_score.getPosition().y + window.getSize().y/60 + high_score.getGlobalBounds().height);

    this->high_score_no_5.setFont(otama_font);
    this->high_score_no_5.setCharacterSize(window.getSize().x/35);
    this->high_score_no_5.setFillColor(sf::Color(255, 255, 255));
    this->high_score_no_5.setString("Five best");
    this->high_score_no_5.setOutlineThickness(1);
    this->high_score_no_5.setOutlineColor(sf::Color(0, 0, 0));
    this->high_score_no_5.setPosition(start_draw_x + (width_screen/3)/2 + width_screen/3*2 - high_score_no_5.getGlobalBounds().width/2, high_score.getPosition().y + window.getSize().y/60 + high_score.getGlobalBounds().height);

    if(settings_tab[3] == 1)
        {
            this->score_1.setTexture(button_true);
            this->score_3.setTexture(button_null);
            this->score_5.setTexture(button_null);
        }
    else if (settings_tab[3] == 3)
        {
            this->score_1.setTexture(button_null);
            this->score_3.setTexture(button_true);
            this->score_5.setTexture(button_null);
        }
    else if (settings_tab[3] == 5)
        {
            this->score_1.setTexture(button_null);
            this->score_3.setTexture(button_null);
            this->score_5.setTexture(button_true);
        }

    this->score_1.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->score_1.setPosition(high_score_no_1.getPosition().x - 5 - score_1.getGlobalBounds().width, high_score_no_1.getPosition().y + score_1.getGlobalBounds().height);


    this->score_3.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->score_3.setPosition(high_score_no_3.getPosition().x - 5 - score_3.getGlobalBounds().width, high_score_no_3.getPosition().y + score_3.getGlobalBounds().height);


    this->score_5.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->score_5.setPosition(high_score_no_5.getPosition().x - 5 - score_5.getGlobalBounds().width, high_score_no_5.getPosition().y + score_5.getGlobalBounds().height);

//---------------------------------------------------------------------------------COLORS BOARD OPTION-----------------------------------------------------------------------------
    this->color_board.setFont(otama_font);
    this->color_board.setCharacterSize(window.getSize().x/35 - 5);
    this->color_board.setFillColor(sf::Color(255, 255, 255));
    this->color_board.setString("Color board");
    this->color_board.setOutlineThickness(2);
    this->color_board.setOutlineColor(sf::Color(0, 0, 0));
    this->color_board.setPosition(width_screen/2 - color_board.getGlobalBounds().width/2 + start_draw_x, line3.getPosition().y + 10);

    this->board_part.setTexture(player_left);
    this->board_part.setPosition(start_draw_x + (width_screen/3)/2 - board_part.getGlobalBounds().width*5, color_board.getPosition().y + window.getSize().y/60 + board_part.getGlobalBounds().height + color_board.getGlobalBounds().height );
    this->board_part.setScale(0.00105*window.getSize().x, 0.00105*window.getSize().x);

    if(settings_tab[4] == 1)
        {
            this->option_board_red.setTexture(button_true);
            this->option_board_green.setTexture(button_null);
            this->option_board_yellow.setTexture(button_null);
        }
    else if (settings_tab[4] == 2)
        {
            this->option_board_red.setTexture(button_null);
            this->option_board_green.setTexture(button_true);
            this->option_board_yellow.setTexture(button_null);
        }
    else if (settings_tab[4] == 3)
        {
            this->option_board_red.setTexture(button_null);
            this->option_board_green.setTexture(button_null);
            this->option_board_yellow.setTexture(button_true);
        }

    this->option_board_red.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->option_board_red.setPosition(board_part.getPosition().x - 5 - board_part.getGlobalBounds().width*2, board_part.getPosition().y);

    this->option_board_green.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->option_board_green.setPosition(start_draw_x + (width_screen/3)/2 + width_screen/3 - board_part.getGlobalBounds().width*8, option_board_red.getPosition().y);

    this->option_board_yellow.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->option_board_yellow.setPosition(start_draw_x + (width_screen/3)/2 + width_screen/3*2 - board_part.getGlobalBounds().width*8, option_board_red.getPosition().y);


//---------------------------------------------------------------------------------BUTTONS BACK & SAVE------------------------------------------------------------
    this->back_button.setSize(sf::Vector2f(no_blocks_x/4 * size_block, window.getSize().y/20));
    this->back_button.setPosition(start_draw_x, end_draw_y - back_button.getGlobalBounds().height);
    this->back_button.setOutlineThickness(2);
    this->back_button.setOutlineColor(sf::Color(144, 77, 0));
    this->back_button.setFillColor(sf::Color(22, 22, 22, 22));

    this->back_text.setFont(otama_font);
    this->back_text.setCharacterSize(window.getSize().x/40 - 5);
    this->back_text.setFillColor(sf::Color(144, 144, 144, 255));
    this->back_text.setString("Back to menu");
    this->back_text.setOutlineThickness(2);
    this->back_text.setOutlineColor(sf::Color(0, 0, 0));
    this->back_text.setPosition(back_button.getPosition().x + (back_button.getGlobalBounds().width/2) - (back_text.getGlobalBounds().width/2),
                                back_button.getPosition().y + back_button.getGlobalBounds().height/2 - back_text.getGlobalBounds().height/2 - back_text.getCharacterSize()/3);

    this->save_button.setSize(sf::Vector2f(no_blocks_x/4 * size_block, window.getSize().y/20));
    this->save_button.setPosition(end_draw_x - save_button.getGlobalBounds().width, end_draw_y - save_button.getGlobalBounds().height);
    this->save_button.setOutlineThickness(2);
    this->save_button.setOutlineColor(sf::Color(144, 77, 0));
    this->save_button.setFillColor(sf::Color(22, 22, 22, 22));

    this->save_text.setFont(otama_font);
    this->save_text.setCharacterSize(window.getSize().x/40 - 5);
    this->save_text.setFillColor(sf::Color(144, 144, 144, 255));
    this->save_text.setString("Save");
    this->save_text.setOutlineThickness(2);
    this->save_text.setOutlineColor(sf::Color(0, 0, 0));
    this->save_text.setPosition(save_button.getPosition().x + (save_button.getGlobalBounds().width/2) - (save_text.getGlobalBounds().width/2),
                                save_button.getPosition().y + save_button.getGlobalBounds().height/2 - save_text.getGlobalBounds().height/2 - save_text.getCharacterSize()/3);
}

Option_page::~Option_page(){}

int Option_page::basic(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{


    background_animation(window, mouse, menu_option);
    this->menu_option_menu_page = 3;
    this->line1.setSize(sf::Vector2f(width_screen - 5, 2));
    this->line2.setSize(sf::Vector2f(width_screen - 5, 2));
    this->line3.setSize(sf::Vector2f(width_screen - 5, 2));

    this->screen_resolution.setCharacterSize(window.getSize().x/35 - 5);
    this->screen_resolution640x800.setCharacterSize(window.getSize().x/35);
    this->screen_resolution800x1000.setCharacterSize(window.getSize().x/35);
    this->screen_resolution960x1200.setCharacterSize(window.getSize().x/35);

    this->button800x600_true.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->button1280x1024_true.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->button1920x1080_true.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));

    this->game_mode.setCharacterSize(window.getSize().x/35 - 5);
    this->easy_mode.setCharacterSize(window.getSize().x/35);
    this->normal.setCharacterSize(window.getSize().x/35);
    this->hard_mode.setCharacterSize(window.getSize().x/35);

    this->easy_sprite.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->normal_sprite.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->hard_sprite.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));

    this->high_score.setCharacterSize(window.getSize().x/35 - 5);
    this->high_score_no_1.setCharacterSize(window.getSize().x/35);
    this->high_score_no_3.setCharacterSize(window.getSize().x/35);
    this->high_score_no_5.setCharacterSize(window.getSize().x/35);

    this->score_1.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->score_3.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->score_5.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));

    this->option_board_red.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->option_board_green.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->option_board_yellow.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));

    this->color_board.setCharacterSize(window.getSize().x/35 - 5);

    this->back_button.setSize(sf::Vector2f(no_blocks_x/4 * size_block, window.getSize().y/20));
    this->back_text.setCharacterSize(window.getSize().x/40 - 5);
    this->save_button.setSize(sf::Vector2f(no_blocks_x/4 * size_block, window.getSize().y/20));
    this->save_text.setCharacterSize(window.getSize().x/40 - 5);

    this->line1.setOutlineThickness(1);
    this->line2.setOutlineThickness(1);
    this->line3.setOutlineThickness(1);

    this->screen_resolution.setOutlineThickness(2);
    this->screen_resolution640x800.setOutlineThickness(1);
    this->screen_resolution800x1000.setOutlineThickness(1);
    this->screen_resolution960x1200.setOutlineThickness(1);

    this->game_mode.setOutlineThickness(2);
    this->easy_mode.setOutlineThickness(1);
    this->hard_mode.setOutlineThickness(1);

    this->high_score.setOutlineThickness(2);
    this->high_score_no_1.setOutlineThickness(1);
    this->high_score_no_3.setOutlineThickness(1);
    this->high_score_no_5.setOutlineThickness(1);

    this->color_board.setOutlineThickness(2);
    this->back_button.setOutlineThickness(2);
    this->back_text.setOutlineThickness(2);
    this->save_button.setOutlineThickness(2);
    this->save_text.setOutlineThickness(2);

    system(window, mouse, menu_option);
    return menu_option_menu_page;
}

int Option_page::system(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{
    if(mouse.x > back_button.getPosition().x  && mouse.x < back_button.getPosition().x + back_button.getGlobalBounds().width &&
        mouse.y > back_button.getPosition().y  && mouse.y < back_button.getPosition().y - 6 + back_button.getGlobalBounds().height)
        {
              this->back_text.setPosition(back_button.getPosition().x + (back_button.getGlobalBounds().width/2) - (back_text.getGlobalBounds().width/2),
                                back_button.getPosition().y + back_button.getGlobalBounds().height/2 - back_text.getGlobalBounds().height/2 - back_text.getCharacterSize()/3);
              this->back_text.setFillColor(sf::Color(255, 255, 255, 255));
              this->back_button.setScale(1.1, 1.1);
              this->back_button.setPosition(start_draw_x, end_draw_y - back_button.getGlobalBounds().height);
        }

    else
        {
              this->back_text.setPosition(back_button.getPosition().x + (back_button.getGlobalBounds().width/2) - (back_text.getGlobalBounds().width/2),
                                back_button.getPosition().y + back_button.getGlobalBounds().height/2 - back_text.getGlobalBounds().height/2 - back_text.getCharacterSize()/3);
              this->back_text.setFillColor(sf::Color(144, 144, 144, 255));
              this->back_button.setScale(1, 1);
              this->back_button.setPosition(start_draw_x, end_draw_y - back_button.getGlobalBounds().height);
        }

    if(mouse.x > save_button.getPosition().x  && mouse.x < save_button.getPosition().x + save_button.getGlobalBounds().width &&
            mouse.y > save_button.getPosition().y  && mouse.y < save_button.getPosition().y - 6 + save_button.getGlobalBounds().height)
        {
              this->save_text.setPosition(save_button.getPosition().x + (save_button.getGlobalBounds().width/2) - (save_text.getGlobalBounds().width/2),
                                save_button.getPosition().y + save_button.getGlobalBounds().height/2 - save_text.getGlobalBounds().height/2 - save_text.getCharacterSize()/3);
              this->save_text.setFillColor(sf::Color(255, 255, 255, 255));
              this->save_button.setScale(1.1, 1.1);
              this->save_button.setPosition(end_draw_x - save_button.getGlobalBounds().width, end_draw_y - save_button.getGlobalBounds().height);
        }

    else
        {
              this->save_text.setPosition(save_button.getPosition().x + (save_button.getGlobalBounds().width/2) - (save_text.getGlobalBounds().width/2),
                                save_button.getPosition().y + save_button.getGlobalBounds().height/2 - save_text.getGlobalBounds().height/2 - save_text.getCharacterSize()/3);
              this->save_text.setFillColor(sf::Color(144, 144, 144, 255));
              this->save_button.setScale(1, 1);
              this->save_button.setPosition(end_draw_x - save_button.getGlobalBounds().width, end_draw_y - save_button.getGlobalBounds().height);
        }

    if(mouse.x > back_button.getPosition().x  && mouse.x < back_button.getPosition().x + back_button.getGlobalBounds().width &&
            mouse.y > back_button.getPosition().y  && mouse.y < back_button.getPosition().y - 6 + back_button.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
                this->menu_option_menu_page = 0;
                reset_object(window, mouse, menu_option);
        }

    if(mouse.x > save_button.getPosition().x  && mouse.x < save_button.getPosition().x + save_button.getGlobalBounds().width &&
            mouse.y > save_button.getPosition().y  && mouse.y < save_button.getPosition().y - 6 + save_button.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left)||annoucment>0)
        {
            annoucment = save_setings.save_setings(window, settings_tab, &nice_font, position_nice_font_x, position_nice_font_y, annoucment);
        }

    if(mouse.x > button800x600_true.getPosition().x  && mouse.x < button800x600_true.getPosition().x + button800x600_true.getGlobalBounds().width &&
            mouse.y > button800x600_true.getPosition().y  && mouse.y < button800x600_true.getPosition().y + button800x600_true.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->button800x600_true.setTexture(button_true);
            this->button1280x1024_true.setTexture(button_null);
            this->button1920x1080_true.setTexture(button_null);
            this->settings_tab[0] = 640;
            this->settings_tab[1] = 800;
        }

    if(mouse.x > button1280x1024_true.getPosition().x  && mouse.x < button1280x1024_true.getPosition().x + button1280x1024_true.getGlobalBounds().width &&
            mouse.y > button1280x1024_true.getPosition().y  && mouse.y < button1280x1024_true.getPosition().y + button1280x1024_true.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->button800x600_true.setTexture(button_null);
            this->button1280x1024_true.setTexture(button_true);
            this->button1920x1080_true.setTexture(button_null);
            this->settings_tab[0] = 800;
            this->settings_tab[1] = 1000;
        }

    if(mouse.x > button1920x1080_true.getPosition().x  && mouse.x < button1920x1080_true.getPosition().x + button1920x1080_true.getGlobalBounds().width &&
            mouse.y > button1920x1080_true.getPosition().y  && mouse.y < button1920x1080_true.getPosition().y + button1920x1080_true.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->button800x600_true.setTexture(button_null);
            this->button1280x1024_true.setTexture(button_null);
            this->button1920x1080_true.setTexture(button_true);
            this->settings_tab[0] = 960;
            this->settings_tab[1] = 1200;
        }

    if(mouse.x > easy_sprite.getPosition().x  && mouse.x < easy_sprite.getPosition().x + easy_sprite.getGlobalBounds().width &&
            mouse.y > easy_sprite.getPosition().y  && mouse.y < easy_sprite.getPosition().y + easy_sprite.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->easy_sprite.setTexture(button_true);
            this->normal_sprite.setTexture(button_null);
            this->hard_sprite.setTexture(button_null);
            this->settings_tab[2] = 1;
        }

    if(mouse.x > normal_sprite.getPosition().x  && mouse.x < normal_sprite.getPosition().x + normal_sprite.getGlobalBounds().width &&
            mouse.y > normal_sprite.getPosition().y  && mouse.y < normal_sprite.getPosition().y + normal_sprite.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->easy_sprite.setTexture(button_null);
            this->normal_sprite.setTexture(button_true);
            this->hard_sprite.setTexture(button_null);
            this->settings_tab[2] = 2;
        }

    if(mouse.x > hard_sprite.getPosition().x  && mouse.x < hard_sprite.getPosition().x + hard_sprite.getGlobalBounds().width &&
            mouse.y > hard_sprite.getPosition().y  && mouse.y < hard_sprite.getPosition().y + hard_sprite.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->easy_sprite.setTexture(button_null);
            this->normal_sprite.setTexture(button_null);
            this->hard_sprite.setTexture(button_true);
            this->settings_tab[2] = 3;
        }

    if(mouse.x > score_1.getPosition().x  && mouse.x < score_1.getPosition().x + score_1.getGlobalBounds().width &&
            mouse.y > score_1.getPosition().y  && mouse.y < score_1.getPosition().y + score_1.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->score_1.setTexture(button_true);
            this->score_3.setTexture(button_null);
            this->score_5.setTexture(button_null);
            this->settings_tab[3] = 1;
        }

    if(mouse.x > score_3.getPosition().x  && mouse.x < score_3.getPosition().x + score_3.getGlobalBounds().width &&
            mouse.y > score_3.getPosition().y  && mouse.y < score_3.getPosition().y + score_3.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->score_1.setTexture(button_null);
            this->score_3.setTexture(button_true);
            this->score_5.setTexture(button_null);
            this->settings_tab[3] = 3;
        }

    if(mouse.x > score_5.getPosition().x  && mouse.x < score_5.getPosition().x + score_5.getGlobalBounds().width &&
            mouse.y > score_5.getPosition().y  && mouse.y < score_5.getPosition().y + score_5.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->score_1.setTexture(button_null);
            this->score_3.setTexture(button_null);
            this->score_5.setTexture(button_true);
            this->settings_tab[3] = 5;
        }

    if(mouse.x > option_board_red.getPosition().x  && mouse.x < option_board_red.getPosition().x + option_board_red.getGlobalBounds().width &&
            mouse.y > option_board_red.getPosition().y  && mouse.y < option_board_red.getPosition().y + option_board_red.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->option_board_red.setTexture(button_true);
            this->option_board_green.setTexture(button_null);
            this->option_board_yellow.setTexture(button_null);
            this->settings_tab[4] = 1;
        }

    if(mouse.x > option_board_green.getPosition().x  && mouse.x < option_board_green.getPosition().x + option_board_green.getGlobalBounds().width &&
            mouse.y > option_board_green.getPosition().y  && mouse.y < option_board_green.getPosition().y + option_board_green.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->option_board_red.setTexture(button_null);
            this->option_board_green.setTexture(button_true);
            this->option_board_yellow.setTexture(button_null);
            this->settings_tab[4] = 2;
        }

    if(mouse.x > option_board_yellow.getPosition().x  && mouse.x < option_board_yellow.getPosition().x + option_board_yellow.getGlobalBounds().width &&
            mouse.y > option_board_yellow.getPosition().y  && mouse.y < option_board_yellow.getPosition().y + option_board_yellow.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->option_board_red.setTexture(button_null);
            this->option_board_green.setTexture(button_null);
            this->option_board_yellow.setTexture(button_true);
            this->settings_tab[4] = 3;
        }

}

void Option_page::board_load(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{
    this->board_part.setScale(0.00105*window.getSize().x, 0.00105*window.getSize().x);
    this->option_board_red.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->option_board_green.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
    this->option_board_yellow.setScale(sf::Vector2f(0.0003 * window.getSize().x, 0.0003 * window.getSize().x));
        for(int i = 0; i < no_parts; i++)
            {
                if(i == 0)
                    {
                        board_part.setTexture(player_left);
                    }
                else if (i > 0 && i < no_parts-1)
                    {
                        board_part.setTexture(player_middle);
                    }
                else if (i <= no_parts-1)
                    {
                        board_part.setTexture(player_right);
                    }
                board_parts_red.push_back(board_part);
                board_part.setPosition(board_part.getPosition().x + board_part.getGlobalBounds().width, board_part.getPosition().y);

            }

        this->board_part.setPosition(start_draw_x + (width_screen/3)/2 + width_screen/3 - board_part.getGlobalBounds().width*5, board_part.getPosition().y);

        for(int i = 0; i < no_parts; i++)
            {
                if(i == 0)
                    {
                        board_part.setTexture(player_left_green);
                    }
                else if (i > 0 && i < no_parts-1)
                    {
                        board_part.setTexture(player_middle_green);
                    }
                else if (i <= no_parts-1)
                    {
                        board_part.setTexture(player_right_green);
                    }
                board_parts_red.push_back(board_part);
                board_part.setPosition(board_part.getPosition().x + board_part.getGlobalBounds().width, board_part.getPosition().y);

            }

        this->board_part.setPosition(start_draw_x + (width_screen/3)/2 + width_screen/3*2 - board_part.getGlobalBounds().width*5, board_part.getPosition().y);

        for(int i = 0; i < no_parts; i++)
            {
                if(i == 0)
                    {
                        board_part.setTexture(player_left_yellow);
                    }
                else if (i > 0 && i < no_parts-1)
                    {
                        board_part.setTexture(player_middle_yellow);
                    }
                else if (i <= no_parts-1)
                    {
                        board_part.setTexture(player_right_yellow);
                    }
                board_parts_red.push_back(board_part);
                board_part.setPosition(board_part.getPosition().x + board_part.getGlobalBounds().width, board_part.getPosition().y);
            }
}

void Option_page::background_animation(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{
    if(animation == false)
        {
            for (int j = 0; j <= no_blocks_y; j++)
                {
                    for (int i = 0; i <= no_blocks_x; i++)
                        {
                            if(i==0 && j == 0)
                                {
                                    this->block.setTexture(block_texture_corner);
                                }

                            else if((i > 0) && no_blocks_x > i && j == 0)
                                {
                                    this->block.setTexture(block_texture_board);
                                }

                            else if(i+1 >= no_blocks_x && j == 0)
                                {
                                    this->block.setRotation(90);
                                    this->block.setTexture(block_texture_corner);
                                }

                            else if(j>0 && j < no_blocks_y && i==0)
                                {
                                    this->block.setTexture(block_texture_board);
                                    this->block.setRotation(-90.0f);
                                }

                            else if(j>0 && j < no_blocks_y && i > 0 && i + 1 < no_blocks_x)
                                {
                                    this->block.setTexture(block_texture_middle);
                                }

                            else if(j>0 && j < no_blocks_y && i  >= no_blocks_x)
                                {
                                    this->block.setRotation(90);
                                    this->block.setTexture(block_texture_board);
                                }

                            else if(j >= no_blocks_y && i == 0)
                                {
                                    this->block.setRotation(-90);
                                    this->block.setTexture(block_texture_corner);
                                }

                            else if(j >= no_blocks_y && i > 0 && i < no_blocks_x)
                                {
                                    this->block.setRotation(180);
                                    this->block.setTexture(block_texture_board);
                                }

                            else if(j >= no_blocks_y && i >= no_blocks_x)
                                {
                                    this->block.setRotation(180);
                                    this->block.setTexture(block_texture_corner);
                                }


                            blocks.push_back(block);
                            block.setPosition(block.getPosition().x + size_block, block.getPosition().y);
                        }

                    block.setPosition(start_draw_x, block.getPosition().y + size_block);
                }
            board_load(window, mouse, menu_option);
        }
        animation = true;
}

void Option_page::reset_object(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{
    this->line1.setSize(sf::Vector2f(0, 0));
    this->line2.setSize(sf::Vector2f(0, 0));
    this->line3.setSize(sf::Vector2f(0, 0));
    this->screen_resolution.setCharacterSize(0);
    this->screen_resolution640x800.setCharacterSize(0);
    this->screen_resolution800x1000.setCharacterSize(0);
    this->screen_resolution960x1200.setCharacterSize(0);
    this->button800x600_true.setScale(sf::Vector2f(0, 0));
    this->button1280x1024_true.setScale(sf::Vector2f(0, 0));
    this->button1920x1080_true.setScale(sf::Vector2f(0, 0));
    this->game_mode.setCharacterSize(0);
    this->easy_mode.setCharacterSize(0);
    this->normal.setCharacterSize(0);
    this->hard_mode.setCharacterSize(0);
    this->easy_sprite.setScale(sf::Vector2f(0, 0));
    this->hard_sprite.setScale(sf::Vector2f(0, 0));
    this->high_score.setCharacterSize(0);
    this->high_score_no_1.setCharacterSize(0);
    this->high_score_no_3.setCharacterSize(0);
    this->high_score_no_5.setCharacterSize(0);
    this->score_1.setScale(sf::Vector2f(0, 0));
    this->score_3.setScale(sf::Vector2f(0, 0));
    this->score_5.setScale(sf::Vector2f(0, 0));
    this->color_board.setCharacterSize(0);
    this->board_part.setScale(0, 0);
    this->option_board_red.setScale(sf::Vector2f(0, 0));
    this->option_board_green.setScale(sf::Vector2f(0, 0));
    this->option_board_yellow.setScale(sf::Vector2f(0, 0));
    this->back_button.setSize(sf::Vector2f(0, 0));
    this->back_text.setCharacterSize(0);
    this->save_button.setSize(sf::Vector2f(0, 0));
    this->save_text.setCharacterSize(0);

    this->line1.setOutlineThickness(0);
    this->line2.setOutlineThickness(0);
    this->line3.setOutlineThickness(0);

    this->screen_resolution.setOutlineThickness(0);
    this->screen_resolution640x800.setOutlineThickness(0);
    this->screen_resolution800x1000.setOutlineThickness(0);
    this->screen_resolution960x1200.setOutlineThickness(0);

    this->game_mode.setOutlineThickness(0);
    this->easy_mode.setOutlineThickness(0);
    this->normal.setOutlineThickness(0);
    this->hard_mode.setOutlineThickness(0);

    this->high_score.setOutlineThickness(0);
    this->high_score_no_1.setOutlineThickness(0);
    this->high_score_no_3.setOutlineThickness(0);
    this->high_score_no_5.setOutlineThickness(0);

    this->color_board.setOutlineThickness(0);
    this->back_button.setOutlineThickness(0);
    this->back_text.setOutlineThickness(0);
    this->save_button.setOutlineThickness(0);
    this->save_text.setOutlineThickness(0);
}

void Option_page::draw_option_page(sf::RenderWindow &window)
{
    if(menu_option_menu_page == 3)
    {
       if(blocks.size() > 0)
    {
        for(int i = 0; i < blocks.size(); i++)
        {
            window.draw(blocks[i]);
        }
    }
    window.draw(screen_resolution);
    window.draw(game_mode);
    window.draw(high_score);
    window.draw(color_board);

    window.draw(line1);
    window.draw(line2);
    window.draw(line3);

    window.draw(screen_resolution640x800);
    window.draw(screen_resolution800x1000);
    window.draw(screen_resolution960x1200);

    window.draw(button800x600_true);
    window.draw(button1280x1024_true);
    window.draw(button1920x1080_true);

    window.draw(easy_mode);
    window.draw(normal);
    window.draw(hard_mode);

    window.draw(easy_sprite);
    window.draw(normal_sprite);
    window.draw(hard_sprite);

    window.draw(high_score_no_1);
    window.draw(high_score_no_3);
    window.draw(high_score_no_5);

    window.draw(score_1);
    window.draw(score_3);
    window.draw(score_5);

    window.draw(back_button);
    window.draw(back_text);

    window.draw(save_button);
    window.draw(save_text);

    window.draw(option_board_red);
    window.draw(option_board_green);
    window.draw(option_board_yellow);

    if(board_parts_red.size()>0)
    {
        for(int i = 0; i < board_parts_red.size(); i++)
        {
            window.draw(board_parts_red[i]);
        }
    }
    }
    save_setings.draw_save_load(window);
}
