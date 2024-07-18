#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "ColisionRectangle.h"

class Player
{
public:
	sf::RectangleShape player_;

	Player(float posX, float posY, const sf::Texture* texture);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	float getPosX() const;
	float getPosY() const;
	int getHp() const;
	void setTexture(const sf::Texture* texture);
	void setPosition(int x, int y);
	void looseHp();
	void setHp(int hp);
	bool isImmune() const;
	void makeImmune();
	void stopImmunity();
	int maxHp_;
	ColisionRectangle colisionRectangle_;
//	bool doesTouch(int x, int y, int enemyWidth, int enemyHeight);

private:
	float posX_;
	float posY_;
	int hp_;
	bool immune_;
	const sf::Texture* texture_;
};

#endif

