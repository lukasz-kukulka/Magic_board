#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "menu.h"
#include "option_page.h"
#include "menu_button.h"
#include "save_load.h"
#include "interface.h"
#include "game_objects_ini.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>



int main()
{
    srand( time( NULL ) );
    sf::Time enter_time;
    sf::Clock enter_clock;
    std::string playerInput = "";
    bool main_ball = false, board_left = false, board_right = false, bullet = false, play = true, event_name = false;
    int width = 800, height = 1000, menu_option = 0, setings_tab[5], name_size = 0;
    Save_load load_seting;

    for(int i = 0; i < 5; i++)
        {
            setings_tab[i] = load_seting.load_setings(i);
        }

    width = setings_tab[0];
    height = setings_tab[1];

    sf::RenderWindow window(sf::VideoMode(width, height), "Magic Board", sf::Style::Default);
    window.setFramerateLimit(60);
    sf::Vector2i mouse = sf::Mouse::getPosition(window);

    Option_page options_class(window, mouse, menu_option);
    Menu menu(window, mouse, menu_option, options_class);
    Interface interface(window);
    Game_objects_ini* game_objects_ini = new Game_objects_ini(window, interface);

    while (window.isOpen())
    {
        enter_time = enter_clock.getElapsedTime();
        main_ball = game_objects_ini->space_press(window);
        event_name = game_objects_ini->enter_name_bool(window);
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::A && menu_option == 1)
                        {
                            board_left = true;
                        }

                    if (event.key.code == sf::Keyboard::D && menu_option == 1)
                        {
                            board_right = true;
                        }

                    if (event.key.code == sf::Keyboard::Space && menu_option == 1)
                        {
                            main_ball = true;
                            enter_clock.restart();
                        }

                    if (event.key.code == sf::Keyboard::Backspace && playerInput.size() > 0)
                        {
                            playerInput.erase(playerInput.size() - 1, 1);
                            name_size = game_objects_ini->enter_name_void(window, playerInput);
                            enter_clock.restart();
                        }

                    if (event.key.code == sf::Keyboard::Enter && playerInput.size() > 0)
                        {
                            Save_load save_new_score;
                            save_new_score.save_score(window, playerInput, game_objects_ini->points_out(window));
                            save_new_score.sort_score(window);
                            menu_option = 0;
                            game_objects_ini->object_setings(window);
                            main_ball = false;
                        }
                }

            if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Right)
                        {
                            bullet = true;
                        }
                }

            if (event.type == sf::Event::KeyReleased)
                {
                    if (event.key.code == sf::Keyboard::A && menu_option == 1)
                        {
                            board_left = false;
                        }

                    if (event.key.code == sf::Keyboard::D && menu_option == 1)
                        {
                            board_right = false;
                        }

                    if (event.key.code == sf::Keyboard::Space && menu_option == 1)
                        {
                            main_ball = true;
                        }
                }

            if (event.type == sf::Event::MouseButtonReleased)
                {
                    if (event.mouseButton.button == sf::Mouse::Right)
                        {
                            bullet = false;
                        }
                }

            if (event_name == true && enter_time.asMilliseconds() >= 150)
                {
                    if (event.type == sf::Event::TextEntered && name_size < 10 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                        {
                            playerInput +=event.text.unicode;
                            name_size = game_objects_ini->enter_name_void(window, playerInput);
                            enter_clock.restart();
                        }
                }
        }

        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        game_objects_ini->system(window, main_ball, board_left, board_right, bullet);

        window.clear();
        menu.draw_menu(window, mouse, menu_option, options_class);
        menu_option = menu.menu_option_if(window, mouse, menu_option, options_class);
        options_class.draw_option_page(window);

        if(menu_option == 1)
            {
                interface.draw_interface(window);
                game_objects_ini->draw_game_objects(window);
            }

        window.display();
    }

    delete game_objects_ini;
    game_objects_ini = 0;
    return 0;
}
