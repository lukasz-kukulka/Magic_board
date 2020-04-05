#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "menu.h"
#include "option_page.h"

int main()
{
    int width = 1200, height = 900, menu_option=0;
    auto mode_screen = sf::Style::Default;
    sf::RenderWindow window(sf::VideoMode(width, height), "Magic Board", mode_screen);
    window.setFramerateLimit(60);
    Option_page options_object(window);

    Menu menu(window);


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
        options_object.draw_option_page(window);
        window.display();
    }

    return 0;
}
