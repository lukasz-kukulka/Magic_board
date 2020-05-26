#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Score
{

public:

    Score(sf::RenderWindow &window, sf::Font *font, int, int, std::string);
     ~Score();

    void draw_score(sf::RenderWindow &window);


private:

    sf::Font font;
    sf::RectangleShape score_rec;
    sf::Text text_score;
};

#endif
