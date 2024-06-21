#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"

class Player
{
public:
	sf::RectangleShape player_;

	Player(int posX, int posY, const sf::Texture* texture);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	int getPosX() const;
	int getPosY() const;

private:
	int posX_;
	int posY_;
	const sf::Texture* texture_;
};

#endif

