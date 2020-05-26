#ifndef SUMMARY_H
#define SUMMARY_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Summary

{
public:

    Summary(sf::RenderWindow &window, sf::Font *font, int, int);
    Summary(sf::RenderWindow &window, sf::Font *font);
    ~Summary();

    void draw_summary(sf::RenderWindow &window);
    bool time_point_up(sf::RenderWindow &window);
    bool summary_point_up(sf::RenderWindow &window, int summary);
    int summary_move_to_points(sf::RenderWindow &window, int, int);
    std::string insert_name(sf::RenderWindow &window, std::string);
    bool del_char(sf::RenderWindow &window);


private:

    sf::RectangleShape background, line;
    sf::Text points, time_points, all_points, your_points, extra_time_points, summary, name_enter, name, enter;
    std::string my_points, extra_points, summary_points;
    int seconds_points, int_extra_points, int_summary_points, transparent;
    bool end_game;
};

#endif
