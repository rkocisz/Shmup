#include "makeStars.h"
#include "common.h"
#include <cstdlib>
#include <iostream>

void makeStars(std::vector<sf::RectangleShape>& starField)
{
	sf::RectangleShape star(sf::Vector2f(2, 2));
	
	for(int i = 0; i < 160; i++)
	{
		star.setPosition(getRandomFloat(0, windowWidth), getRandomFloat(0, windowHeight));
		starField.push_back(star);
	}
}

void updateStars(std::vector<sf::RectangleShape>& starField)
{
	for (int i = 0; i < starField.size(); i++)
	{
		if(i % 3 == 1)
			starField[i].move(0, 0.7f);
		else if (i % 3 == 2)
			starField[i].move(0, 0.5f);
		else 
			starField[i].move(0, 0.3f);

		if (starField[i].getPosition().y > 540)
			starField[i].move(0, -542);
	}
}

float getRandomFloat(float min, float max)
{
	return ((float)rand() / RAND_MAX) * (max - min) + min;
}
