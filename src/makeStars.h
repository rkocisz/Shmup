#ifndef MAKESTARS_H
#define MAKESTARS_H

#include "SFML/Graphics.hpp"

void makeStars(std::vector<sf::RectangleShape>& starField);

void updateStars(std::vector<sf::RectangleShape>& starField);

int getRandomInt(int max);

#endif
