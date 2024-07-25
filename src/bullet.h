#ifndef BULLET_H
#define BULLET_H

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "ColisionRectangle.h"

class Bullet
{
public:
	Bullet(const sf::Texture* texture);
	void update();
	void draw(sf::RenderWindow& window);
	void shoot(Player* player1);
	void moveUp();
	int getPosX() const;
	int getPosY() const;
	void setPosition(int x, int y);
	bool isActive() const;
	void spawn();
	void despawn();
	void hit();
	bool isHit() const;

	sf::RectangleShape bullet_;
	ColisionRectangle colisionRectangle_;

private:
	float posX_;
	float posY_;
	bool isActive_;
	bool isHit_;
	const sf::Texture* texture_;
	float elapsed_;
};

#endif

