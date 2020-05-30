#include "save_load.h"
#include <fstream>
#include <windows.h>

Save_load::Save_load()
{
    this->settings_to_file[0] = 0;
    this->settings_to_file[1] = 0;
    this->settings_to_file[2] = 0;
    this->settings_to_file[3] = 0;
    this->settings_to_file[4] = 0;
}

Save_load::~Save_load(){}

int Save_load::load_setings(int tab_index)
{
    int no_line = 0;
    std::string line;
    std::fstream files;
    files.open("settings.ini", std::ios::in);

    if(files.good()==false)
        {
            std::cout<<"File not exist"<<std::endl;
            exit(0);
        }

    while(getline(files, line))
        {
            if (no_line==0)
                {
                    settings_to_file[0] = std::atoi(line.c_str());
                }

            if (no_line==1)
                {
                    settings_to_file[1] = std::atoi(line.c_str());
                }

            if (no_line==2)
                {
                    settings_to_file[2] = std::atoi(line.c_str());
                }

            if (no_line==3)
                {
                    settings_to_file[3] = std::atoi(line.c_str());
                }

            if (no_line==4)
                {
                    settings_to_file[4] = std::atoi(line.c_str());
                }

            no_line++;
        }

        files.close();
    return settings_to_file[tab_index];
}

int Save_load::save_setings(sf::RenderWindow &window, int *tab, sf::Font *font, int pozX, int pozY, int annoucment)
{
    this->pozX = pozX;
    this->pozY = pozY;
    this->save_text.setScale(1, 1);
    this->save_text.setFont(*font);
    this->save_text.setCharacterSize(window.getSize().x/50);
    this->save_text.setFillColor(sf::Color(255, 0, 0, 255));
    this->save_text.setString("Save settings, please restart program to confirm settings");
    this->save_text.setOutlineThickness(1);
    this->save_text.setOutlineColor(sf::Color(255, 255, 255));
    this->save_text.setPosition(pozX - save_text.getGlobalBounds().width, pozY - save_text.getGlobalBounds().height*2);


    if(annoucment>10)
        {
            this->save_text.setCharacterSize(0);
            this->save_text.setOutlineThickness(0);
            this->save_text.setScale(0, 0);
            annoucment = 0;
            Sleep(2000);
        }
    else
        {
            annoucment++;
        }
    this->settings_to_file[0] = tab[0];
    this->settings_to_file[1] = tab[1];
    this->settings_to_file[2] = tab[2];
    this->settings_to_file[3] = tab[3];
    this->settings_to_file[4] = tab[4];

    std::fstream files;

    files.open("settings.ini", std::ios::out | std::ios::trunc);
    files<<settings_to_file[0]<<std::endl;
    files<<settings_to_file[1]<<std::endl;
    files<<settings_to_file[2]<<std::endl;
    files<<settings_to_file[3]<<std::endl;
    files<<settings_to_file[4]<<std::endl;

    files.close();
    return annoucment;
}

void Save_load::load_score(sf::RenderWindow &window, sf::Font *font)
{
    int no_line = 0;
    std::string line;
    std::fstream files;
    files.open("score.txt", std::ios::in);

    if(files.good()==false)
        {
            std::cout<<"File not exist"<<std::endl;
            exit(0);
        }

    while(getline(files, line))
        {
            if(load_board_lvl(window, 4) > 0)
            {
                if (no_line==0)
                    {
                        cell.push_back(Score(window, font, 1, 1, "1"));
                        cell.push_back(Score(window, font, 2, 1, line));
                    }

                if (no_line==1)
                    {
                        cell.push_back(Score(window, font, 3, 1, line));
                    }
            }

            if(load_board_lvl(window, 4) > 1)
                {
                    if (no_line==2)
                        {
                            cell.push_back(Score(window, font, 1, 2, "2"));
                            cell.push_back(Score(window, font, 2, 2, line));
                        }

                    if (no_line==3)
                        {
                            cell.push_back(Score(window, font, 3, 2, line));
                        }

                    if (no_line==4)
                        {
                            cell.push_back(Score(window, font, 1, 3, "3"));
                            cell.push_back(Score(window, font, 2, 3, line));
                        }

                    if (no_line==5)
                        {
                            cell.push_back(Score(window, font, 3, 3, line));
                        }
                }

            if(load_board_lvl(window, 4) > 2)
            {
                if (no_line==6)
                    {
                        cell.push_back(Score(window, font, 1, 4, "4"));
                        cell.push_back(Score(window, font, 2, 4, line));
                    }
                if (no_line==7)
                    {
                        cell.push_back(Score(window, font, 3, 4, line));
                    }

                if (no_line==8)
                    {
                        cell.push_back(Score(window, font, 1, 5, "5"));
                        cell.push_back(Score(window, font, 2, 5, line));
                    }
                if (no_line==9)
                    {
                        cell.push_back(Score(window, font, 3, 5, line));
                    }
            }


            no_line++;
        }

    files.close();
}

std::string Save_load::best_score(sf::RenderWindow &window)
{
    int no_line = 1;
    std::string line;
    std::fstream files;
    files.open("score.txt", std::ios::in);

    if(files.good()==false)
        {
            std::cout<<"File not exist"<<std::endl;
            exit(0);
        }

    while(getline(files, line))
        {
            if(no_line == 2)
                {
                    return line;
                }
            no_line++;
        }

    files.close();
}

void Save_load::save_score(sf::RenderWindow &window, std::string imie, int score)
{
    std::fstream files;

    files.open("score.txt", std::ios::out | std::ios::app);
    files<<imie<<std::endl;
    files<<score<<std::endl;

    files.close();
}

int Save_load::load_board_lvl(sf::RenderWindow &window, int index)
{
    int temp;
    int no_line = 1;
    std::string line;
    std::fstream files;
    files.open("settings.ini", std::ios::in);

    if(files.good() == false)
        {
            std::cout<<"File not exist"<<std::endl;
            exit(0);
        }

    while(getline(files, line))
        {
            if(no_line == 3 && index == 3)
                {
                    temp = std::stoi(line);
                    return temp;
                }

            if(no_line == 4 && index == 4)
                {
                    temp = std::stoi(line);
                    return temp;
                }

            if(no_line == 5 && index == 5)
                {
                    temp = std::stoi(line);
                    return temp;
                }

            no_line++;
        }

    files.close();
}

void Save_load::sort_score(sf::RenderWindow &window)
{
    int temp_score;
    std::string temp_name, score_string;
    int no_line = 1;
    std::string line;
    std::fstream files;
    files.open("score.txt", std::ios::in);

    if(files.good() == false)
        {
            std::cout<<"File not exist"<<std::endl;
            exit(0);
        }

    while(getline(files, line))
        {
            if(no_line % 2 == 1)
                {
                    name.push_back(line);
                }

            else if(no_line % 2 == 0)
                {
                    score.push_back(std::stoi(line));
                }

            no_line++;
        }

    files.close();

    for(int i = 0; i < score.size() - 1; i++)
        {
            for(int j = 0; j < score.size() - 1; j++)
                {
                    if(score[j] < score[j+1])
                        {
                            temp_score = score[j];
                            score[j] = score[j+1];
                            score[j+1] = temp_score;

                            temp_name = name[j];
                            name[j] = name[j+1];
                            name[j+1] = temp_name;
                        }
                }
        }

    files.open("score.txt", std::ios::out | std::ios::trunc);

    for(int i = 0; i < 5; i++)
        {
            score_string = std::to_string(score[i]);
            while(score_string.size() < 8)
                {
                    score_string = "0" + score_string;
                }
            files<<name[i]<<std::endl;
            files<<score_string<<std::endl;
        }

    score.erase(score.begin(), score.end());
    name.erase(name.begin(), name.end());
    files.close();
}

void Save_load::draw_save_load(sf::RenderWindow &window)
{
    window.draw(save_text);
}

void Save_load::draw_score(sf::RenderWindow &window)
{
    for(int i = 0; i < cell.size(); i++)
        {
            cell[i].draw_score(window);
        }
}
