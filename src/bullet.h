#ifndef BULLET_H
#define BULLET_H

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "ColisionRectangle.h"

class Bullet
{
public:
	Bullet(const sf::Texture* texture);
	sf::RectangleShape bullet_;
	
	void shoot(Player* player1);
	void moveUp();
	int getPosY() const;
	void setPosition(int x, int y);
	bool isActive() const;
	void spawn();
	void despawn();
	ColisionRectangle colisionRectangle_;

private:
	float posX_;
	float posY_;
	bool isActive_;
	const sf::Texture* texture_;
};

#endif

