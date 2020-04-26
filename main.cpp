#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "menu.h"
#include "option_page.h"
#include "menu_button.h"
#include "save_load.h"
#include "interface.h"



int main()
{
    int width = 1200, height = 900, menu_option=0, setings_tab[5];
    auto mode_screen = sf::Style::Default;
    Save_load load_seting;

    for(int i = 0; i < 5; i++)  {setings_tab[i] = load_seting.load_setings(i);}                                     //LOAD SETTINGS FROM FILE FROM save_load CLASS TO TABLE
    if(setings_tab[2] == 2)   {mode_screen = sf::Style::Default;}                                                   //SETTINGS SCREEN WINDOW MODE
    else if(setings_tab[2] == 1)   {mode_screen = sf::Style::Fullscreen;}                                           //SETTINGS SCREEN FULLSCREEN MODE

    sf::RenderWindow window(sf::VideoMode(1800, 900), "Magic Board", mode_screen);
    window.setFramerateLimit(60);
    sf::Vector2i mouse = sf::Mouse::getPosition(window);
    Option_page options_class(window, mouse, menu_option);
    Menu menu(window, mouse, menu_option, options_class);
    Interface interface(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Vector2i mouse = sf::Mouse::getPosition(window);

        window.clear();

//        menu.draw_menu(window, mouse, menu_option, options_class);
//        menu_option = menu.menu_option_if(window, mouse, menu_option, options_class);
//        options_class.draw_option_page(window);

        interface.draw_interface(window);

        window.display();
    }

    return 0;
}
