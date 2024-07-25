#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "ColisionRectangle.h"
#include "Animation.h"

class Player
{
public:
	sf::RectangleShape player_;
	sf::RectangleShape fire_;

	Player(float posX, float posY);
	void update();
	void draw(sf::RenderWindow& window);
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
	bool isVisible_;
	void hit();

	int maxHp_;
	ColisionRectangle colisionRectangle_;
	Animation* fireAnimation_;

private:
	float posX_;
	float posY_;
	float elapsed_;
	float elapsed2_;
	int hp_;
	bool immune_;
	bool isHit;
	sf::Texture playerTexture_;
	sf::Texture fireTextures_;
	sf::Texture playerTextureLeft_;
	sf::Texture playerTextureRight_;
};

#endif

