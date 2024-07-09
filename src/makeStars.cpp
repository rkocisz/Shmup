#include "makeStars.h"
#include <cstdlib>

void makeStars(std::vector<sf::RectangleShape>& starField)
{
	sf::RectangleShape star(sf::Vector2f(2, 2));
	srand((unsigned)time(NULL));
	
	for(int i = 0; i < 160; i++)
	{
		star.setPosition(getRandomInt(960), getRandomInt(540));
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

int getRandomInt(int max)
{
	return rand() % max;
}
