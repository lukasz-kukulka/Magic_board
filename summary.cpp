#include "summary.h"


Summary::Summary(sf::RenderWindow &window, sf::Font *font, int mypoints, int seconds)
{
    this->transparent = 1;
    this->seconds_points = seconds;
    this->my_points = std::to_string(mypoints);
    this->extra_points = "00000000";
    this->summary_points = "00000000";
    this->end_game = false;

    while(my_points.size() < 8)
        {
            this->my_points = "0" + my_points;
        }

    this->background.setSize(sf::Vector2f(window.getSize().x - 300, window.getSize().y/2 ));
    this->background.setFillColor(sf::Color(255, 255, 255, 111));
    this->background.setOutlineColor(sf::Color::Black);
    this->background.setOutlineThickness(5);
    this->background.setPosition(window.getSize().x/2 - background.getGlobalBounds().width/2, window.getSize().y/2 - background.getGlobalBounds().height/2);

    this->your_points.setFont(*font);
    this->your_points.setCharacterSize(window.getSize().x/25);
    this->your_points.setStyle(sf::Text::Bold);
    this->your_points.setFillColor(sf::Color(255, 255, 0, 255));
    this->your_points.setOutlineColor(sf::Color(0, 0, 0, 255));
    this->your_points.setOutlineThickness(1);
    this->your_points.setString("Your points");
    this->your_points.setPosition(background.getPosition().x + background.getGlobalBounds().width/2 - your_points.getGlobalBounds().width/2, background.getPosition().y);

    this->points.setFont(*font);
    this->points.setCharacterSize(window.getSize().x/10);
    this->points.setStyle(sf::Text::Bold);
    this->points.setFillColor(sf::Color(255, 255, 0, 255));
    this->points.setOutlineColor(sf::Color(0, 0, 0, 255));
    this->points.setOutlineThickness(1);
    this->points.setString(my_points);
    this->points.setPosition(background.getPosition().x + background.getGlobalBounds().width/2 - points.getGlobalBounds().width/2, your_points.getPosition().y
                             + your_points.getGlobalBounds().height);

    this->extra_time_points.setFont(*font);
    this->extra_time_points.setCharacterSize(window.getSize().x/25);
    this->extra_time_points.setStyle(sf::Text::Bold);
    this->extra_time_points.setFillColor(sf::Color(255, 255, 0, 255));
    this->extra_time_points.setOutlineColor(sf::Color(0, 0, 0, 255));
    this->extra_time_points.setOutlineThickness(1);
    this->extra_time_points.setString("Extra time points");
    this->extra_time_points.setPosition(background.getPosition().x + background.getGlobalBounds().width/2 - extra_time_points.getGlobalBounds().width/2, points.getPosition().y
                             + points.getGlobalBounds().height +80);

    this->time_points.setFont(*font);
    this->time_points.setCharacterSize(window.getSize().x/10);
    this->time_points.setStyle(sf::Text::Bold);
    this->time_points.setFillColor(sf::Color(255, 255, 0, 255));
    this->time_points.setOutlineColor(sf::Color(0, 0, 0, 255));
    this->time_points.setOutlineThickness(1);
    this->time_points.setString(extra_points);
    this->time_points.setPosition(background.getPosition().x + background.getGlobalBounds().width/2 - time_points.getGlobalBounds().width/2, extra_time_points.getPosition().y
                                  + extra_time_points.getGlobalBounds().height);

    this->summary.setFont(*font);
    this->summary.setCharacterSize(window.getSize().x/25);
    this->summary.setStyle(sf::Text::Bold);
    this->summary.setFillColor(sf::Color(255, 255, 0, 255));
    this->summary.setOutlineColor(sf::Color(0, 0, 0, 255));
    this->summary.setOutlineThickness(1);
    this->summary.setString("SUMMARY");
    this->summary.setPosition(background.getPosition().x + background.getGlobalBounds().width/2 - summary.getGlobalBounds().width/2, time_points.getPosition().y
                             + time_points.getGlobalBounds().height + 80);

    this->all_points.setFont(*font);
    this->all_points.setCharacterSize(window.getSize().x/10);
    this->all_points.setStyle(sf::Text::Bold);
    this->all_points.setFillColor(sf::Color(255, 255, 0, 255));
    this->all_points.setOutlineColor(sf::Color(0, 0, 0, 255));
    this->all_points.setOutlineThickness(1);
    this->all_points.setString(summary_points);
    this->all_points.setPosition(background.getPosition().x + background.getGlobalBounds().width/2 - all_points.getGlobalBounds().width/2, summary.getPosition().y + 25
                                  + summary.getGlobalBounds().height);

}

Summary::Summary(sf::RenderWindow &window, sf::Font *font)
{
    this->end_game = true;

    this->background.setSize(sf::Vector2f(window.getSize().x - 300, window.getSize().y/5));
    this->background.setFillColor(sf::Color(0, 0, 0, 111));
    this->background.setOutlineColor(sf::Color::Black);
    this->background.setOutlineThickness(5);
    this->background.setPosition(window.getSize().x/2 - background.getGlobalBounds().width/2, window.getSize().y/2 - background.getGlobalBounds().height/2);

    this->name.setFont(*font);
    this->name.setCharacterSize(window.getSize().x/35);
    this->name.setStyle(sf::Text::Bold);
    this->name.setFillColor(sf::Color(0, 255, 0, 255));
    this->name.setOutlineColor(sf::Color(0, 0, 0, 255));
    this->name.setOutlineThickness(1);
    this->name.setString("Enter your name (max. 10 chars):");
    this->name.setPosition(background.getPosition().x + background.getGlobalBounds().width/2 - name.getGlobalBounds().width/2,
                                 background.getPosition().y + 10);

    this->name_enter.setFont(*font);
    this->name_enter.setCharacterSize(window.getSize().x/15);
    this->name_enter.setStyle(sf::Text::Bold);
    this->name_enter.setFillColor(sf::Color(0, 255, 0, 255));
    this->name_enter.setOutlineColor(sf::Color(0, 0, 0, 255));
    this->name_enter.setOutlineThickness(1);
    this->name_enter.setString("");
    this->name_enter.setPosition(background.getPosition().x + background.getGlobalBounds().width/2 - name_enter.getGlobalBounds().width/2,
                                 background.getPosition().y + background.getGlobalBounds().height/2 - name_enter.getGlobalBounds().height/2);

    this->enter.setFont(*font);
    this->enter.setCharacterSize(window.getSize().x/35);
    this->enter.setStyle(sf::Text::Bold);
    this->enter.setFillColor(sf::Color(111, 111, 111, 255));
    this->enter.setOutlineColor(sf::Color(0, 0, 0, 255));
    this->enter.setOutlineThickness(1);
    this->enter.setString("Press 'ENTER' to confirm");
    this->enter.setPosition(background.getPosition().x + background.getGlobalBounds().width/2 - enter.getGlobalBounds().width/2,
                                 background.getPosition().y + background.getGlobalBounds().height - enter.getGlobalBounds().height*2);
}

Summary::~Summary(){}

bool Summary::time_point_up(sf::RenderWindow &window)
{
    int_extra_points = std::atoi(extra_points.c_str());
    if(seconds_points > int_extra_points)
        {
            int_extra_points++;
            extra_points = std::to_string(int_extra_points);
            while(extra_points.size() < 8)
                {
                    this->extra_points = "0" + extra_points;
                }

            this->time_points.setString(extra_points);

            return true;
        }

    else
        {
            return false;
        }

}

bool Summary::summary_point_up(sf::RenderWindow &window, int summary)
{
    int_summary_points = std::atoi(summary_points.c_str());
    if(summary > int_summary_points)
        {
            int_summary_points++;
            summary_points = std::to_string(int_summary_points);
            while(summary_points.size() < 8)
                {
                    this->summary_points = "0" + summary_points;
                }

            this->all_points.setString(summary_points);

            return true;
        }

    else
        {
            return false;
        }
}

int Summary::summary_move_to_points(sf::RenderWindow &window, int posX, int posY)
{
    if(all_points.getPosition().x > posX && all_points.getPosition().y > posY)
        {
            this->all_points.setCharacterSize(window.getSize().x/(10 + transparent));
            this->all_points.setStyle(sf::Text::Bold);
            this->all_points.setFillColor(sf::Color(255, 255, 0, 255 - transparent));
            this->all_points.setOutlineColor(sf::Color(0, 0, 0, 255 - transparent));
            this->all_points.setOutlineThickness(1);
            this->all_points.setString(summary_points);
            this->all_points.setPosition(all_points.getPosition().x, all_points.getPosition().y - 15);

            transparent++;

            return true;
        }

    else
        {
            return false;
        }
}

std::string Summary::insert_name(sf::RenderWindow &window, std::string sign)
{
    this->name_enter.setString(sign);
    this->name_enter.setPosition(background.getPosition().x + background.getGlobalBounds().width/2 - name_enter.getGlobalBounds().width/2,
                                 background.getPosition().y + background.getGlobalBounds().height/2 - name_enter.getGlobalBounds().height/2);

    return name_enter.getString();
}

bool Summary::del_char(sf::RenderWindow &window)
{
    return end_game;
}

void Summary::draw_summary(sf::RenderWindow &window)
{
    window.draw(background);
    window.draw(line);
    window.draw(points);
    window.draw(time_points);
    window.draw(your_points);
    window.draw(extra_time_points);
    window.draw(summary);
    window.draw(all_points);
    window.draw(name_enter);
    window.draw(name);
    window.draw(enter);
}
