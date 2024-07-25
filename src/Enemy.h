#ifndef ENEMY_H
#define ENEMY_H

#include "SFML/Graphics.hpp"
#include "ColisionRectangle.h"
#include "Animation.h"

class Enemy
{
public:
	Enemy(sf::Texture *texture, sf::Texture* hitEnemyTextures);
	void update();
	void draw(sf::RenderWindow& window);
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
	void hit();
	bool didJustDie();

	sf::RectangleShape enemy_;
	ColisionRectangle colisionRectangle_;
	Animation* enemyAnimation_;

private:
	int posX_;
	int posY_;
	int hp_;
	bool isActive_;
	bool isHit_;
	bool justDied_;
	float elapsed_;

	sf::Texture* hitEnemyTextures_;
	sf::Texture* enemyTextures_;

};

#endif
