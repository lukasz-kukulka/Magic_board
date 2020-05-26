#include "score.h"

Score::Score(sf::RenderWindow &window, sf::Font *font, int pozX = 1, int quan = 1, std::string text = "---NONE---")
{
    this->score_rec.setSize(sf::Vector2f(window.getSize().x/5, window.getSize().y/18));
    this->score_rec.setPosition(sf::Vector2f(window.getSize().x/5 * pozX, window.getSize().y/2 - window.getSize().y/18 + window.getSize().y/18 * quan));
    this->score_rec.setOutlineThickness(2);
    this->score_rec.setOutlineColor(sf::Color(0, 0, 0));
    this->score_rec.setFillColor(sf::Color(166, 166, 166, 166));

    this->text_score.setFont(*font);
    this->text_score.setCharacterSize(score_rec.getSize().y/7*3);
    this->text_score.setFillColor(sf::Color(255, 111, 0));
    this->text_score.setString(text);
    this->text_score.setOutlineThickness(1);
    this->text_score.setOutlineColor(sf::Color(0, 0, 0));
    this->text_score.setPosition(sf::Vector2f(score_rec.getPosition().x + score_rec.getGlobalBounds().width/2 - text_score.getGlobalBounds().width/2,
                                              score_rec.getPosition().y + score_rec.getGlobalBounds().height/2 - text_score.getGlobalBounds().height/2 - text_score.getGlobalBounds().height/4));
}

Score::~Score(){}

void Score::draw_score(sf::RenderWindow &window)
{
    window.draw(score_rec);
    window.draw(text_score);
}
