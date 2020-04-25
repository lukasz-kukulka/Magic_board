#include "menu_button.h"
#include <windows.h>

Menu_button::Menu_button(sf::RenderWindow &window, sf::Font *font, std::string name = "TEST")
{
    this->how_many_button = 7;

    this->button_menu.setSize(sf::Vector2f(window.getSize().x/5*2, window.getSize().y/25));
    this->button_menu.setPosition(window.getSize().x/2 - button_menu.getGlobalBounds().width/2,
                                  (window.getSize().y - button_menu.getGlobalBounds().height * how_many_button) + (button_menu.getGlobalBounds().height * no_menu_options));
    this->button_menu.setOutlineThickness(1);
    this->button_menu.setOutlineColor(sf::Color(0, 0, 0));
    this->button_menu.setFillColor(sf::Color(111, 111, 111, 111));


    this->text_button.setFont(*font);
    this->text_button.setCharacterSize(button_menu.getSize().y - button_menu.getSize().y/5);
    this->text_button.setFillColor(sf::Color(0, 222, 0));
    this->text_button.setString(name);
    this->text_button.setOutlineThickness(2);
    this->text_button.setOutlineColor(sf::Color(0, 0, 0));
    this->text_button.setPosition(window.getSize().x/2 - text_button.getGlobalBounds().width/2, button_menu.getPosition().y);

    this->no_menu_options++;
    this->menu_index = no_menu_options;
    this->scale_index_button = button_menu.getSize().x/200;


    this->scale_index_text = 254;
}

Menu_button::Menu_button(std::string name, sf::RenderWindow &window, sf::Font *font, int pozX)
{
    this->button_shape.setSize(sf::Vector2f(window.getSize().x/6, window.getSize().y/25));
    this->button_shape.setPosition(10, window.getSize().y - button_shape.getGlobalBounds().height - 10);
    this->button_shape.setOutlineThickness(1);
    this->button_shape.setScale(1, 1);
    this->button_shape.setOutlineThickness(1);
    this->button_shape.setOutlineColor(sf::Color(0, 0, 0));
    this->button_shape.setFillColor(sf::Color(111, 111, 111, 55));



    this->button_text.setFont(*font);
    this->button_text.setCharacterSize(window.getSize().x/50);
    this->button_text.setFillColor(sf::Color(255, 100, 0));
    this->button_text.setString(name);
    this->button_text.setOutlineThickness(2);
    this->button_text.setOutlineColor(sf::Color(0, 0, 0));
    this->button_text.setPosition(button_shape.getPosition().x + button_shape.getGlobalBounds().width/2 - button_text.getGlobalBounds().width/2,
                                  button_shape.getPosition().y + button_shape.getGlobalBounds().height/2 - button_text.getGlobalBounds().height/2 - button_text.getGlobalBounds().height/5);
}

Menu_button::~Menu_button(){}

int Menu_button::touch_button(sf::RenderWindow &window, sf::Vector2i mouse)
{
    if(button_menu.getSize().x >= window.getSize().x/5*2 - 5)
        {
            this->button_menu.setScale(1, 1);
            if(mouse.x > button_menu.getPosition().x  && mouse.x < button_menu.getPosition().x + button_menu.getGlobalBounds().width &&
                    mouse.y > button_menu.getPosition().y  && mouse.y < button_menu.getPosition().y - 6 + button_menu.getGlobalBounds().height)
                {
                    this->button_menu.setScale(1.1, 1.1);
                    this->button_menu.setPosition(window.getSize().x/2 - button_menu.getGlobalBounds().width/2, button_menu.getPosition().y);
                    this->text_button.setScale(1.1, 1.1);
                    this->text_button.setFillColor(sf::Color(222, 0, 0));
                    this->text_button.setPosition(window.getSize().x/2 - text_button.getGlobalBounds().width/2, button_menu.getPosition().y);
                    this->button_menu.setFillColor(sf::Color(111, 111, 111, 200));

                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            this->button_menu.setFillColor(sf::Color(255, 111, 0, 255));
                            this->text_button.setFillColor(sf::Color(222, 0, 0));
                            this->text_button.setScale(1, 1);
                            this->button_menu.setScale(1, 1);
                            return menu_index;
                        }
                }

            else
                {
                    this->button_menu.setScale(1, 1);
                    this->button_menu.setFillColor(sf::Color(111, 111, 111, 111));
                    this->button_menu.setPosition(window.getSize().x/2 - button_menu.getGlobalBounds().width/2, button_menu.getPosition().y);
                    this->text_button.setScale(1, 1);
                    this->text_button.setFillColor(sf::Color(0, 222, 0));
                    this->text_button.setPosition(window.getSize().x/2 - text_button.getGlobalBounds().width/2, button_menu.getPosition().y);
                }

            return 0;
        }
}

int Menu_button::back_save_button(sf::RenderWindow &window, sf::Vector2i mouse, int return_menu_button)
{
    if(button_shape.getSize().x == window.getSize().x/6 || button_shape.getSize().x == 0)
        {
            if(mouse.x > button_shape.getPosition().x  && mouse.x < button_shape.getPosition().x + button_shape.getGlobalBounds().width &&
                    mouse.y > button_shape.getPosition().y  && mouse.y < button_shape.getPosition().y - 6 + button_shape.getGlobalBounds().height)
                {
                    this->button_shape.setScale(1.1, 1.1);
                    this->button_text.setScale(1.1, 1.1);

                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        {
                            return 0;
                        }
                }

            else
                {
                    this->button_shape.setScale(1, 1);
                    this->button_text.setScale(1, 1);
                }

        }
        return return_menu_button;
}

int Menu_button::animation_button_off(sf::RenderWindow &window, sf::Vector2i mouse)
{

    if(button_menu.getSize().x > 0)
        {
            if(scale_index_text > 0)
                {
                    scale_index_text = scale_index_text - 2;
                    this->text_button.setFillColor(sf::Color(0, 222, 0, scale_index_text));
                    this->text_button.setOutlineColor(sf::Color(0, 0, 0, scale_index_text));
                }
            else
                {
                    this->text_button.setScale(0,0);
                }
            this->button_menu.setSize(sf::Vector2f(button_menu.getSize().x - scale_index_button, button_menu.getSize().y));
            this->button_menu.setPosition(window.getSize().x/2 - button_menu.getGlobalBounds().width/2, button_menu.getPosition().y);
        }

    else
        {
            this->button_menu.setSize(sf::Vector2f(0, 0));
            return 55;
        }

}

int Menu_button::animation_button_on(sf::RenderWindow &window)
{

            if(button_menu.getSize().x < window.getSize().x/5*2)
                {
                    this->button_menu.setFillColor(sf::Color(111, 111, 111, 111));
                    this->text_button.setScale(1, 1);
                    this->button_menu.setSize(sf::Vector2f(button_menu.getSize().x, window.getSize().y/25));
                    if(scale_index_text <= 253)
                        {
                            this->scale_index_text = scale_index_text + 1 * 1.1;
                            this->text_button.setFillColor(sf::Color(0, 222, 0, scale_index_text));
                            this->text_button.setOutlineColor(sf::Color(0, 0, 0, scale_index_text));
                        }
                    else
                        {
                            this->text_button.setScale(1,1);
                        }
                    this->button_menu.setSize(sf::Vector2f(button_menu.getSize().x + scale_index_button, button_menu.getSize().y));
                    this->button_menu.setPosition(window.getSize().x/2 - button_menu.getGlobalBounds().width/2, button_menu.getPosition().y);
                }

            else
                {
                    this->text_button.setScale(1, 1);
                    return 44;
                }
}

void Menu_button::show_button(sf::RenderWindow &window, sf::Vector2i mouse)
{
    window.draw(button_menu);
    window.draw(text_button);

    window.draw(button_shape);
    window.draw(button_text);
}



