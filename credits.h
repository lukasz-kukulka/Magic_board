#ifndef CREDITS_H
#define CREDITS_H
#include <SFML/Graphics.hpp>

class Credits
{
public:

    static int space_betwen;

    Credits(sf::RenderWindow &window, sf::Font *font, std::string, int, int);
    ~Credits();

    void move_text(sf::RenderWindow &window);
    void draw_credits(sf::RenderWindow &window);
    void inaccessible(sf::RenderWindow &window, int);

private:
    sf::Font credits_font;
    sf::Text credits_text;
    int text_size;

};

#endif
