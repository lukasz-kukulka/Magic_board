#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "score.h"

class Save_load
{

public:

Save_load(int, int, sf::Font *font);
Save_load();
 ~Save_load();

int load_setings(int);
int save_setings(sf::RenderWindow &window, int *tab, sf::Font *font, int, int, int);
void draw_save_load(sf::RenderWindow &window);
void save_score(sf::RenderWindow &window);
void load_score(sf::RenderWindow &window, sf::Font *font);
void draw_score(sf::RenderWindow &window);
void sort_score(sf::RenderWindow &window);
std::string best_score(sf::RenderWindow &window);

private:

sf::Text save_text;
int settings_to_file[5], pozX, pozY;

std::vector<Score>cell;


};
#endif

