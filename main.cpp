#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "menu.h"

int main()
{
    int width = 1200, height = 900, menu_option=0;
    auto mode_screen = sf::Style::Fullscreen;
    sf::RenderWindow window(sf::VideoMode(width, height), "Magic Board", mode_screen);
    window.setFramerateLimit(60);
    Menu menu(window.getSize());
    //menu_option = menu.menu_option;
    std::cout<<"BEGIN---------------------------------------------"<<menu.menu_option<<std::endl;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        menu.menu_option_index(window, mouse, menu_option);
        menu_option = menu.menu_option;

        window.clear();
        menu.draw_menu(window, mouse, menu_option);
        window.display();
    }

    return 0;
}
