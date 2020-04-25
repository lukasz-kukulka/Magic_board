#include <iostream>
#include <conio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "menu.h"


int Menu_button::no_menu_options = 0;
int Credits::space_betwen = 0;

Menu::Menu(sf::RenderWindow &window, sf::Vector2i mouse, int return_menu_button, Option_page &options_class)
                                                    :load_records() //INITIALIZING LIST - OBJECT: LOAD FROM FILE HIGH SCORE
{
//------------------------------------------------------------------------------- FONTS INI --------------------------------------------------------------
    this->font.loadFromFile("Fonts/main_small.ttf");
    this->otama_font.loadFromFile("Fonts/otama.otf");
    this->SF_Italic.loadFromFile("Fonts/SF_Italic.ttf");
    this->SF_Extended.loadFromFile("Fonts/SF_Extended.ttf");
//--------------------------------------------------------------------------------FONT INI END------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------BACKGROUNG INI------------------------------------------------------------
    this->backgroud.loadFromFile("Textures/background1.jpg");
    this->backgroud_menu.setTexture(backgroud);
    this->backgroud_menu.setPosition(0.0f, 0.0f);
//--------------------------------------------------------------------------------BACKGROUND INI END------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------BUTTONS MENU INI------------------------------------------------------------
    menu_options_class.push_back(Menu_button(window, &font, "New game"));
    menu_options_class.push_back(Menu_button(window, &font, "High score"));
    menu_options_class.push_back(Menu_button(window, &font, "Options"));
    menu_options_class.push_back(Menu_button(window, &font, "Credits"));
    menu_options_class.push_back(Menu_button(window, &font, "Exit"));
//--------------------------------------------------------------------------------BUTTONS MENU INI END------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------BACK BUTTON INI ----------------------------------------------------------------------
    menu_options_class.push_back(Menu_button("Back", window, &otama_font, 1000));
//--------------------------------------------------------------------------------BACK BUTTON INI END------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------CREDITS SUBTITLES INI-------------------------------------------------------------------
    credits_class.push_back(Credits(window, &SF_Italic, "DIRECTOR", 20, 300));
    credits_class.push_back(Credits(window, &SF_Extended, "Lukasz Kukulka", 15, 100));
    credits_class.push_back(Credits(window, &SF_Italic, "SCREEN PLAN", 20, 300));
    credits_class.push_back(Credits(window, &SF_Extended, "Lukasz Kukulka", 15, 100));
    credits_class.push_back(Credits(window, &SF_Italic, "PROJECT", 20, 300));
    credits_class.push_back(Credits(window, &SF_Extended, "Lukasz Kukulka", 15, 100));
    credits_class.push_back(Credits(window, &SF_Italic, "EDITOR", 20, 300));
    credits_class.push_back(Credits(window, &SF_Extended, "Lukasz Kukulka", 15, 100));
//--------------------------------------------------------------------------------CREDITS SUBTITLES INI------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    records = 0;   // HELP VARIABLE TO INITIALIZE OBJECT TABLE HIGH SCORE
}
Menu::~Menu(){}

void Menu::menu_credits(sf::RenderWindow &window)  //METHOD INITIALIZE MOVMENT SUBTITLES
{
    for(int i = 0; i < credits_class.size(); i++)
        {
            credits_class[i].move_text(window);
        }
}

int Menu::menu_option_if(sf::RenderWindow &window, sf::Vector2i mouse, int return_menu_button, Option_page &options_class)  //METHOD ACCOUNTABLE FOR MENU MECHANICS
{
    for(int i = 0; i < menu_options_class.size(); i++)
        {

            if(menu_options_class[i].touch_button(window, mouse) > 0 && menu_options_class[i].touch_button(window, mouse) <=5)
                {
                    return_menu_button = menu_options_class[i].touch_button(window, mouse);
                    menu_options_class[i].touch_button(window, mouse);
                }

            else
                {
                    menu_options_class[i].touch_button(window, mouse);
                }


            if(return_menu_button == 0)
                {
                    menu_options_class[i].animation_button_on(window);
                    if(menu_options_class[i].animation_button_on(window) == 44)
                        {
                            std::cout<<"0.  00  "<<std::endl;
                        }
                }

            else if(return_menu_button == 1)
                {
                    menu_options_class[i].animation_button_off(window, mouse);
                    if(menu_options_class[i].animation_button_off(window, mouse) == 55)
                        {
                            std::cout<<"1.    "<<std::endl;
                        }
                }

            else if(return_menu_button == 2)
                {
                    menu_options_class[i].animation_button_off(window, mouse);
                    if(menu_options_class[i].animation_button_off(window, mouse) == 55)
                        {
                            return_menu_button = menu_options_class[i].back_save_button(window, mouse, return_menu_button);
                            std::cout<<"2.    "<<std::endl;
                            if(records == 0)
                            {
                                load_records.load_score(window, &otama_font);
                                records++;
                            }

                        }
                }

            else if(return_menu_button == 3)
                {
                    menu_options_class[i].animation_button_off(window, mouse);
                    if(menu_options_class[i].animation_button_off(window, mouse) == 55)
                        {

                            return_menu_button = options_class.basic(window, mouse, return_menu_button);
                            std::cout<<"3.    "<<std::endl;
                        }
                }

            else if(return_menu_button == 4)
                {
                    menu_options_class[i].animation_button_off(window, mouse);
                    if(menu_options_class[i].animation_button_off(window, mouse) == 55)
                        {
                            return_menu_button = menu_options_class[i].back_save_button(window, mouse, return_menu_button);
                            menu_credits(window);
                        }
                }

            else if(return_menu_button == 5)
                {
                    menu_options_class[i].animation_button_off(window, mouse);
                    if(menu_options_class[i].animation_button_off(window, mouse) == 55)
                        {
                            menu_button_exit(window);
                        }
                }

            else if(return_menu_button > 5)/////DELETE IN THE END
                {
                    std::cout<<"6. ERROR ERROR ERROR   "<<std::endl;
                    return_menu_button = 0;
                }
        }

    return return_menu_button;
}

void Menu::menu_button_exit(sf::RenderWindow &window) //METHOD CLOSE WINDOW
{
    window.close();
}

void Menu::draw_menu(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option, Option_page &options_class) //DRAW METHOD
{

    window.draw(backgroud_menu);
    window.draw(back_button);
    window.draw(back_text);
    window.draw(lukasz_kukulka);
    window.draw(lukasz_copy1);
    window.draw(lukasz_copy2);
    window.draw(lukasz_copy3);
    window.draw(director);
    window.draw(editor);
    window.draw(screenplan);
    window.draw(project);

    options_class.draw_option_page(window);

    for(int i = 0; i < 5; i++)
        {
            menu_options_class[i].show_button(window, mouse);
        }
    if(menu_option == 4)
        {
           for(int i = 0; i < credits_class.size(); i++)
                {
                    credits_class[i].draw_credits(window);
                    menu_options_class[5].show_button(window, mouse);
                }
        }
    if(menu_option == 2)
        {
            load_records.draw_score(window);
            menu_options_class[5].show_button(window, mouse);
        }

}
