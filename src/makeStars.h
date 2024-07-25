#ifndef MAKESTARS_H
#define MAKESTARS_H

#include "SFML/Graphics.hpp"

void makeStars(std::vector<sf::RectangleShape>& starField);

void updateStars(std::vector<sf::RectangleShape>& starField);

float getRandomFloat(float min, float max);

#endif
