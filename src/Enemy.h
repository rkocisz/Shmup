#ifndef ENEMY_H
#define ENEMY_H

#include "SFML/Graphics.hpp"
#include "ColisionRectangle.h"

class Enemy
{
public:
	Enemy(sf::Texture *texture);
	void setPosition(int x, int y);
	void setSize(int x, int y);
	float getPosX() const;
	float getPosY() const;
	int getSizeX() const;
	int getSizeY() const;
	bool isActive() const;
	void spawn();
	void despawn();
	int getHp() const;
	void looseHp();
	void setHp(int hp);
	bool isHit() const;
	void setNotHit();

	sf::RectangleShape enemy_;
	ColisionRectangle colisionRectangle_;

private:
	int posX_;
	int posY_;
	bool isActive_;
	int hp_;
	bool isHit_;
};

#endif
