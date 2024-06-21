#ifndef BULLET_H
#define BULLET_H

#include "SFML/Graphics.hpp"
#include "Player.h"

class Bullet
{
public:
	Bullet(const sf::Texture* texture);
	sf::RectangleShape bullet_;
	
	void shoot(Player& player1);
	void moveUp();
	int getPosY() const;

private:
	int posX_;
	int posY_;
	const sf::Texture* texture_;
};

#endif

