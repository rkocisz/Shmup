#include "makeStars.h"
#include "common.h"
#include <cstdlib>

void makeStars(std::vector<sf::RectangleShape>& starField)
{
	sf::RectangleShape star(sf::Vector2f(2, 2));
	srand((unsigned)time(NULL));
	
	for(int i = 0; i < 160; i++)
	{
		star.setPosition(getRandomInt(windowWidth), getRandomInt(windowHeight));
		starField.push_back(star);
	}
}

void updateStars(std::vector<sf::RectangleShape>& starField, float deltaTime)
{
	for (int i = 0; i < starField.size(); i++)
	{
		if(i % 3 == 1)
			starField[i].move(0, 50.0f * deltaTime);
		else if (i % 3 == 2)
			starField[i].move(0, 35.0f * deltaTime);
		else 
			starField[i].move(0, 25.0f * deltaTime);

		if (starField[i].getPosition().y > 540)
			starField[i].move(0, -542);
	}
}

float getRandomInt(int max)
{
	return rand() % max;
}
