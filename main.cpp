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



int main()
{
    bool main_ball = false, board_left = false, board_right = false;
    int width = 1200, height = 900, menu_option=0, setings_tab[5];
    auto mode_screen = sf::Style::Default;
    Save_load load_seting;

    for(int i = 0; i < 5; i++)  {setings_tab[i] = load_seting.load_setings(i);}                                     //LOAD SETTINGS FROM FILE FROM save_load CLASS TO TABLE
    if(setings_tab[2] == 2)   {mode_screen = sf::Style::Default;}                                                   //SETTINGS SCREEN WINDOW MODE
    else if(setings_tab[2] == 1)   {mode_screen = sf::Style::Fullscreen;}                                           //SETTINGS SCREEN FULLSCREEN MODE

    sf::RenderWindow window(sf::VideoMode(800, 1000), "Magic Board", mode_screen);
    window.setFramerateLimit(60);
    sf::Vector2i mouse = sf::Mouse::getPosition(window);
    Option_page options_class(window, mouse, menu_option);
    Menu menu(window, mouse, menu_option, options_class);
    Interface interface(window);
    Game_objects_ini game_objects_ini(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::A)
                    {
                        board_left = true;
                    }
                    if (event.key.code == sf::Keyboard::D)
                    {
                        board_right = true;
                    }
                    if (event.key.code == sf::Keyboard::Space)
                    {
                        main_ball = true;
                    }
                }
            if (event.type == sf::Event::KeyReleased)
                {
                    if (event.key.code == sf::Keyboard::A)
                    {
                        board_left = false;
                    }
                    if (event.key.code == sf::Keyboard::D)
                    {
                        board_right = false;
                    }
                    if (event.key.code == sf::Keyboard::Space)
                    {
                        main_ball = true;     //pause if i want
                    }
                }
        }
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        game_objects_ini.system(window, main_ball, board_left, board_right);
        window.clear();

//        menu.draw_menu(window, mouse, menu_option, options_class);
//        menu_option = menu.menu_option_if(window, mouse, menu_option, options_class);
//        options_class.draw_option_page(window);

        interface.draw_interface(window);
        game_objects_ini.draw_game_objects(window);

        window.display();
    }

    return 0;
}
