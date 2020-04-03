#include <iostream>
#include <conio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "menu.h"

Menu::Menu(sf::Vector2u windowSize)
{
    this->font.loadFromFile("Fonts/main_small.ttf");
    this->otama_font.loadFromFile("Fonts/otama.otf");
    this->backgroud.loadFromFile("Textures/background1.jpg");
    this->window = windowSize;
    this->menu_option = 0;
    this->y = window.y;
    this->rec_size_x = window.x/8*3;
    this->rec_size_y = window.y/20;
    this->transparent_color = 255;
    this->base_menu_change = sf::Color(255, 255, 255, 128);
    this->base_menu_regular = sf::Color(255, 255, 255, 64);
    this->red_menu = sf::Color(255, 0, 0, transparent_color);
    this->green_menu = sf::Color(0, 255, 0, transparent_color);
    this->black_menu = sf::Color(0, 0, 0, transparent_color);

    this->backgroud_menu.setTexture(backgroud);
    this->backgroud_menu.setPosition(0.0f, 0.0f);

}
Menu::~Menu(){}

void Menu::menu_base(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{
    float scale_x = 1.15, scale_y = 1.05, scale_regular = 1;
    int out_line = 2;
    this->rec1.setSize(sf::Vector2f(window.getSize().x/8*3, window.getSize().y/20));
    this->rec1.setPosition(window.getSize().x/2 - rec1.getGlobalBounds().width/2, window.getSize().y/3*2);
    this->rec1.setOutlineThickness(1);
    this->rec1.setOutlineColor(black_menu);
    this->rec1.setFillColor(sf::Color(base_menu_regular));

    this->rec2.setSize(sf::Vector2f(rec1.getSize()));
    this->rec2.setPosition(window.getSize().x/2 - rec2.getGlobalBounds().width/2, rec1.getPosition().y + rec1.getGlobalBounds().height);
    this->rec2.setOutlineThickness(rec1.getOutlineThickness());
    this->rec2.setOutlineColor(black_menu);
    this->rec2.setFillColor(sf::Color(base_menu_regular));

    this->rec3.setSize(sf::Vector2f(rec1.getSize()));
    this->rec3.setPosition(window.getSize().x/2 - rec3.getGlobalBounds().width/2, rec2.getPosition().y + rec2.getGlobalBounds().height);
    this->rec3.setOutlineThickness(rec1.getOutlineThickness());
    this->rec3.setOutlineColor(black_menu);
    this->rec3.setFillColor(sf::Color(base_menu_regular));

    this->rec4.setSize(sf::Vector2f(rec1.getSize()));
    this->rec4.setPosition(window.getSize().x/2 - rec4.getGlobalBounds().width/2, rec3.getPosition().y + rec3.getGlobalBounds().height);
    this->rec4.setOutlineThickness(rec1.getOutlineThickness());
    this->rec4.setOutlineColor(black_menu);
    this->rec4.setFillColor(sf::Color(base_menu_regular));

    this->rec5.setSize(sf::Vector2f(rec1.getSize()));
    this->rec5.setPosition(window.getSize().x/2 - rec5.getGlobalBounds().width/2, rec4.getPosition().y + rec4.getGlobalBounds().height);
    this->rec5.setOutlineThickness(rec1.getOutlineThickness());
    this->rec5.setOutlineColor(black_menu);
    this->rec5.setFillColor(sf::Color(base_menu_regular));

    this->new_game.setFont(font);
    this->new_game.setCharacterSize(rec1.getSize().y*0.8);
    this->new_game.setFillColor(green_menu);
    this->new_game.setString("NEW GAME");
    this->new_game.setOutlineThickness(2);
    this->new_game.setOutlineColor(black_menu);
    this->new_game.setPosition(rec1.getPosition().x + (rec1.getGlobalBounds().width/2) - (new_game.getGlobalBounds().width/2), window.getSize().y/3*2);

    this->highScore.setFont(font);
    this->highScore.setCharacterSize(new_game.getCharacterSize());
    this->highScore.setFillColor(green_menu);
    this->highScore.setString("HIGH SCORES");
    this->highScore.setOutlineThickness(new_game.getOutlineThickness());
    this->highScore.setOutlineColor(black_menu);
    this->highScore.setPosition(rec2.getPosition().x + (rec2.getGlobalBounds().width/2) - (highScore.getGlobalBounds().width/2), window.getSize().y/3*2 + window.getSize().y/20);

    this->options.setFont(font);
    this->options.setCharacterSize(new_game.getCharacterSize());
    this->options.setFillColor(green_menu);
    this->options.setString("OPTIONS");
    this->options.setOutlineThickness(new_game.getOutlineThickness());
    this->options.setOutlineColor(black_menu);
    this->options.setPosition(rec3.getPosition().x + (rec3.getGlobalBounds().width/2) - (options.getGlobalBounds().width/2), window.getSize().y/3*2 + window.getSize().y/20*2);

    this->credits.setFont(font);
    this->credits.setCharacterSize(new_game.getCharacterSize());
    this->credits.setFillColor(green_menu);
    this->credits.setString("CREDITS");
    this->credits.setOutlineThickness(new_game.getOutlineThickness());
    this->credits.setOutlineColor(black_menu);
    this->credits.setPosition(rec4.getPosition().x + (rec4.getGlobalBounds().width/2) - (credits.getGlobalBounds().width/2), window.getSize().y/3*2 + window.getSize().y/20*3);

    this->exit.setFont(font);
    this->exit.setCharacterSize(new_game.getCharacterSize());
    this->exit.setFillColor(green_menu);
    this->exit.setString("EXIT");
    this->exit.setOutlineThickness(new_game.getOutlineThickness());
    this->exit.setOutlineColor(black_menu);
    this->exit.setPosition(rec5.getPosition().x + (rec5.getGlobalBounds().width/2) - (exit.getGlobalBounds().width/2), window.getSize().y/3*2 + window.getSize().y/20*4);

  if(mouse.x > rec1.getPosition().x  && mouse.x < rec1.getPosition().x + rec1.getGlobalBounds().width &&
        mouse.y > rec1.getPosition().y  && mouse.y < rec1.getPosition().y - 6 + rec1.getGlobalBounds().height)
      {
          this->new_game.setFillColor(red_menu);
          this->rec1.setScale(scale_x, scale_y);
          this->rec1.setOutlineThickness(out_line);
          this->rec1.setFillColor(sf::Color(base_menu_change));
          this->rec1.setPosition(window.getSize().x/2 - rec1.getGlobalBounds().width/2, window.getSize().y/3*2);
      }
  else
      {
          this->new_game.setFillColor(green_menu);
          this->rec1.setScale(scale_regular, scale_regular);
          this->rec1.setOutlineThickness(1);
          this->rec1.setFillColor(base_menu_regular);
          this->rec1.setPosition(window.getSize().x/2 - rec1.getGlobalBounds().width/2, window.getSize().y/3*2);
      }

  if(mouse.x > rec2.getPosition().x  && mouse.x < rec2.getPosition().x + rec2.getGlobalBounds().width &&
        mouse.y > rec2.getPosition().y  && mouse.y < rec2.getPosition().y - 6 + rec2.getGlobalBounds().height)
      {
          this->highScore.setFillColor(red_menu);
          this->rec2.setScale(scale_x, scale_y);
          this->rec2.setOutlineThickness(out_line);
          this->rec2.setFillColor(sf::Color(base_menu_change));
          this->rec2.setPosition(window.getSize().x/2 - rec2.getGlobalBounds().width/2, window.getSize().y/3*2 + rec_size_y);
      }
  else
      {
          this->highScore.setFillColor(green_menu);
          this->rec2.setScale(scale_regular, scale_regular);
          this->rec2.setOutlineThickness(1);
          this->rec2.setFillColor(sf::Color(base_menu_regular));
          this->rec2.setPosition(window.getSize().x/2 - rec2.getGlobalBounds().width/2, window.getSize().y/3*2 + rec_size_y);
      }

  if(mouse.x > rec3.getPosition().x  && mouse.x < rec3.getPosition().x + rec3.getGlobalBounds().width &&
        mouse.y > rec3.getPosition().y  && mouse.y < rec3.getPosition().y - 6 + rec3.getGlobalBounds().height)
      {
          this->options.setFillColor(red_menu);
          this->rec3.setScale(scale_x, scale_y);
          this->rec3.setOutlineThickness(out_line);
          this->rec3.setFillColor(sf::Color(base_menu_change));
          this->rec3.setPosition(window.getSize().x/2 - rec3.getGlobalBounds().width/2, window.getSize().y/3*2 + rec_size_y*2);
      }
  else
      {
          this->options.setFillColor(green_menu);
          this->rec3.setScale(scale_regular, scale_regular);
          this->rec3.setOutlineThickness(1);
          this->rec3.setFillColor(sf::Color(base_menu_regular));
          this->rec3.setPosition(window.getSize().x/2 - rec3.getGlobalBounds().width/2, window.getSize().y/3*2 + rec_size_y*2);
      }

  if(mouse.x > rec4.getPosition().x  && mouse.x < rec4.getPosition().x + rec4.getGlobalBounds().width &&
        mouse.y > rec4.getPosition().y  && mouse.y < rec4.getPosition().y - 6 + rec4.getGlobalBounds().height)
      {
          this->credits.setFillColor(red_menu);
          this->rec4.setScale(scale_x, scale_y);
          this->rec4.setOutlineThickness(out_line);
          this->rec4.setFillColor(sf::Color(base_menu_change));
          this->rec4.setPosition(window.getSize().x/2 - rec4.getGlobalBounds().width/2, window.getSize().y/3*2 + rec_size_y*3);
      }
  else
      {
          this->credits.setFillColor(green_menu);
          this->rec4.setScale(scale_regular, scale_regular);
          this->rec4.setOutlineThickness(1);
          this->rec4.setFillColor(sf::Color(base_menu_regular));
          this->rec4.setPosition(window.getSize().x/2 - rec4.getGlobalBounds().width/2, window.getSize().y/3*2 + rec_size_y*3);
      }

  if(mouse.x > rec5.getPosition().x  && mouse.x < rec5.getPosition().x + rec5.getGlobalBounds().width &&
        mouse.y > rec5.getPosition().y  && mouse.y < rec5.getPosition().y - 6 + rec5.getGlobalBounds().height)
      {
          this->exit.setFillColor(red_menu);
          this->rec5.setScale(scale_x, scale_y);
          this->rec5.setOutlineThickness(out_line);
          this->rec5.setFillColor(sf::Color(base_menu_change));
          this->rec5.setPosition(window.getSize().x/2 - rec5.getGlobalBounds().width/2, window.getSize().y/3*2 + rec_size_y*4);
      }
  else
      {
          this->exit.setFillColor(green_menu);
          this->rec5.setScale(scale_regular, scale_regular);
          this->rec5.setOutlineThickness(1);
          this->rec5.setFillColor(sf::Color(base_menu_regular));
          this->rec5.setPosition(window.getSize().x/2 - rec5.getGlobalBounds().width/2, window.getSize().y/3*2 + rec_size_y*4);
      }

  if(mouse.x > rec4.getPosition().x  && mouse.x < rec4.getPosition().x + rec4.getGlobalBounds().width &&
            mouse.y > rec4.getPosition().y  && mouse.y < rec4.getPosition().y - 6 + rec4.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->menu_option = 4;
                menu_animation(window, mouse, menu_option);
            }

  if(mouse.x > rec5.getPosition().x  && mouse.x < rec5.getPosition().x + rec5.getGlobalBounds().width &&
            mouse.y > rec5.getPosition().y  && mouse.y < rec5.getPosition().y - 6 + rec5.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->menu_option = 5;
                menu_animation(window, mouse, menu_option);
            }
}
void Menu::menu_animation(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{
                int a = 100;
                this->rec_size_x = window.getSize().x/8*3;
                this->rec_size_y = window.getSize().y/20;
                this->rec5.setScale(1.0, 1.0);
                this->rec4.setScale(1.0, 1.0);
                this->rec3.setScale(1.0, 1.0);
                this->rec2.setScale(1.0, 1.0);
                this->rec1.setScale(1.0, 1.0);
                int x = rec_size_x/100, y = 255;

                for(;;)
                {
                    time = clock.getElapsedTime();
                        if (time.asMicroseconds()>=100)
                        {
                            y = y - 3;
                            if(y<=3)
                                y = 3;
                            rec_size_x = rec_size_x - x;

                            if(menu_option == 1){this->credits.setFillColor(sf::Color(255, 0, 0, y));}
                            else
                            {
                                this->new_game.setFillColor(sf::Color(0, 255, 0, y));
                                this->new_game.setOutlineColor(sf::Color(0, 0, 0, y));
                                this->rec1.setOutlineColor(sf::Color(0, 0, 0, y));
                                this->rec1.setSize(sf::Vector2f(rec_size_x, rec_size_y));
                                this->rec1.setPosition(window.getSize().x/2 - rec4.getGlobalBounds().width/2, window.getSize().y/3*2);
                            }


                            if(menu_option == 2){credits.setFillColor(sf::Color(255, 0, 0, y));}
                            else
                            {
                                this->highScore.setFillColor(sf::Color(0, 255, 0, y));
                                this->highScore.setOutlineColor(sf::Color(0, 0, 0, y));
                                this->rec2.setOutlineColor(sf::Color(0, 0, 0, y));
                                this->rec2.setSize(sf::Vector2f(rec_size_x, rec_size_y));
                                this->rec2.setPosition(window.getSize().x/2 - rec4.getGlobalBounds().width/2, window.getSize().y/3*2 + rec_size_y);
                            }


                            if(menu_option == 3){credits.setFillColor(sf::Color(255, 0, 0, y));}
                            else
                            {
                                this->options.setFillColor(sf::Color(0, 255, 0, y));
                                this->options.setOutlineColor(sf::Color(0, 0, 0, y));
                                this->rec3.setOutlineColor(sf::Color(0, 0, 0, y));
                                this->rec3.setSize(sf::Vector2f(rec_size_x, rec_size_y));
                                this->rec3.setPosition(window.getSize().x/2 - rec4.getGlobalBounds().width/2, window.getSize().y/3*2 + rec_size_y*2);
                            }


                            if(menu_option == 4){credits.setFillColor(sf::Color(255, 0, 0, y));}
                            else
                            {
                                this->credits.setFillColor(sf::Color(0, 255, 0, y));
                                this->credits.setOutlineColor(sf::Color(0, 0, 0, y));
                                this->rec4.setOutlineColor(sf::Color(0, 0, 0, y));
                                this->rec4.setSize(sf::Vector2f(rec_size_x, rec_size_y));
                                this->rec4.setPosition(window.getSize().x/2 - rec4.getGlobalBounds().width/2, window.getSize().y/3*2 + rec_size_y*3);
                            }


                            if(menu_option == 5){exit.setFillColor(sf::Color(255, 0, 0, y));}
                            else
                            {
                                this->exit.setFillColor(sf::Color(0, 255, 0, y));
                                this->exit.setOutlineColor(sf::Color(0, 0, 0, y));
                                this->rec5.setOutlineColor(sf::Color(0, 0, 0, y));
                                this->rec5.setSize(sf::Vector2f(rec_size_x, rec_size_y));
                                this->rec5.setPosition(window.getSize().x/2 - rec5.getGlobalBounds().width/2, window.getSize().y/3*2 + rec_size_y*4);
                            }

                            std::cout<<"petla--------------------------------------------"<<menu_option<<std::endl;
                            clock.restart();
                            a--;
                            window.clear();
                            draw_menu(window, mouse, menu_option);
                            window.display();
                            if(a<=0)
                            {
                                this->new_game.setCharacterSize(0);
                                this->highScore.setCharacterSize(0);
                                this->options.setCharacterSize(0);
                                this->credits.setCharacterSize(0);
                                this->exit.setCharacterSize(0);
                                this->rec5.setScale(0.0, 0.0);
                                this->rec4.setScale(0.0, 0.0);
                                this->rec3.setScale(0.0, 0.0);
                                this->rec2.setScale(0.0, 0.0);
                                this->rec1.setScale(0.0, 0.0);
                                break;
                            }
                        }
                }

}

void Menu::menu_newGame(sf::RenderWindow &window, sf::Vector2i mouse, int menu_optionw)
{

}

void Menu::menu_highScore(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{

}

void Menu::menu_options(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{

}

void Menu::menu_credits(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{
    this->back_button.setSize(sf::Vector2f(window.getSize().x/8*3, window.getSize().y/20));
    this->back_button.setPosition(window.getSize().x - back_button.getSize().x - 5, window.getSize().y - back_button.getSize().y - 5);
    this->back_button.setOutlineThickness(rec1.getOutlineThickness());
    this->back_button.setOutlineColor(black_menu);
    this->back_button.setFillColor(sf::Color(base_menu_regular));

    this->back_text.setFont(font);
    this->back_text.setCharacterSize(30);
    this->back_text.setFillColor(green_menu);
    this->back_text.setString("BACK TO MENU");
    this->back_text.setOutlineThickness(new_game.getOutlineThickness());
    this->back_text.setOutlineColor(black_menu);
    this->back_text.setPosition(back_button.getPosition().x + (back_button.getGlobalBounds().width/2) - (back_text.getGlobalBounds().width/2), window.getSize().y - back_button.getSize().y);

    if(mouse.x > back_button.getPosition().x  && mouse.x < back_button.getPosition().x + back_button.getGlobalBounds().width &&
        mouse.y > back_button.getPosition().y  && mouse.y < back_button.getPosition().y - 6 + back_button.getGlobalBounds().height)
      {
          this->back_text.setFillColor(red_menu);
          this->back_button.setOutlineThickness(5);
          this->back_button.setFillColor(sf::Color(base_menu_change));
          this->back_button.setPosition(window.getSize().x - back_button.getSize().x - 5, window.getSize().y - back_button.getSize().y - 5);
      }
    else
      {
          this->back_text.setFillColor(green_menu);
          this->back_button.setOutlineThickness(1);
          this->back_button.setFillColor(sf::Color(base_menu_regular));
          this->back_button.setPosition(window.getSize().x - back_button.getSize().x - 5, window.getSize().y - back_button.getSize().y - 5);
      }

    y = y - 1;
    if(y <= - 1600)
    {
        y = window.getSize().y;
    }

    this->lukasz_kukulka.setFont(otama_font);
    this->lukasz_kukulka.setCharacterSize(120);
    this->lukasz_kukulka.setFillColor(sf::Color(0, 170, 0));
    this->lukasz_kukulka.setString("Lukasz Kukulka");
    this->lukasz_kukulka.setOutlineThickness(2);
    this->lukasz_kukulka.setOutlineColor(sf::Color(255, 255, 255));
    this->lukasz_kukulka.setPosition(window.getSize().x/2 - lukasz_kukulka.getGlobalBounds().width/2, y);
    director = lukasz_copy1 = lukasz_copy2 = lukasz_copy3 = lukasz_kukulka;

    this->director.setCharacterSize(60);
    this->director.setString("DIRECTOR");
    this->director.setPosition(window.getSize().x/2 - director.getGlobalBounds().width/2, y - lukasz_kukulka.getGlobalBounds().height);
    screenplan = project = editor = director;

    this->lukasz_copy1.setPosition(window.getSize().x/2 - lukasz_kukulka.getGlobalBounds().width/2, y + 500);
    this->screenplan.setString("SCREENPLAN");
    this->screenplan.setPosition(window.getSize().x/2 - director.getGlobalBounds().width/2, y - lukasz_copy1.getGlobalBounds().height + 500);

    this->lukasz_copy2.setPosition(window.getSize().x/2 - lukasz_kukulka.getGlobalBounds().width/2, y + 1000);
    this->project.setString("PROJECT");
    this->project.setPosition(window.getSize().x/2 - director.getGlobalBounds().width/2, y - lukasz_copy2.getGlobalBounds().height + 1000);

    this->lukasz_copy3.setPosition(window.getSize().x/2 - lukasz_kukulka.getGlobalBounds().width/2, y + 1500);
    this->editor.setString("EDITOR");
    this->editor.setPosition(window.getSize().x/2 - director.getGlobalBounds().width/2, y - lukasz_copy3.getGlobalBounds().height + 1500);



    if(mouse.x > back_button.getPosition().x  && mouse.x < back_button.getPosition().x + back_button.getGlobalBounds().width &&
            mouse.y > back_button.getPosition().y  && mouse.y < back_button.getPosition().y - 6 + back_button.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->menu_option = 0;
                this->back_text.setCharacterSize(0);
                this->back_button.setSize(sf::Vector2f(0, 0));
                this->lukasz_kukulka.setCharacterSize(0);
                this->director.setCharacterSize(0);
                screenplan = project = editor = director;
                lukasz_copy1 = lukasz_copy2 = lukasz_copy3 = lukasz_kukulka;
            }


}

void Menu::menu_exit(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{
    this->closing.setFont(font);
    this->closing.setCharacterSize(100);
    this->closing.setFillColor(red_menu);
    this->closing.setOutlineThickness(new_game.getOutlineThickness());
    this->closing.setOutlineColor(black_menu);
    this->closing.setString("CLOSING GAME");
    this->closing.setPosition(window.getSize().x/2 - (closing.getGlobalBounds().width/2), window.getSize().y/2);
    window.close();
}

void Menu::menu_form_to_play(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{

}

void Menu::menu_option_index(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{
    if(menu_option==0)
    {
        menu_base(window, mouse, menu_option);
    }
    else if(menu_option==1)
    {

    }
    else if(menu_option==2)
    {

    }
    else if(menu_option==3)
    {

    }
    else if(menu_option==4)
    {
        menu_credits(window, mouse, menu_option);
    }
    else if(menu_option==5)
    {
        menu_exit(window, mouse, menu_option);
    }
}

void Menu::draw_menu(sf::RenderWindow &window, sf::Vector2i mouse, int menu_option)
{
        window.draw(backgroud_menu);
        window.draw(rec1);
        window.draw(rec2);
        window.draw(rec3);
        window.draw(rec4);
        window.draw(rec5);
        window.draw(closing);
        window.draw(new_game);
        window.draw(highScore);
        window.draw(options);
        window.draw(credits);
        window.draw(exit);
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
}
