#include "bullet.h"

Bullet::Bullet(const sf::Texture* texture)
: texture_(texture)
{
	posX_ = 0;
	posY_ = 0;

	bullet_.setSize(sf::Vector2f(32, 32));
	bullet_.setTexture(texture_);
	bullet_.setPosition(posX_, posY_);
}

void Bullet::shoot(Player* player1)
{
	posX_ = player1->getPosX();
	posY_ = player1->getPosY() -32;
	bullet_.setPosition(posX_, posY_);
}

void Bullet::moveUp()
{
	posY_ -= 8;
	bullet_.setPosition(posX_, posY_);
}

int Bullet::getPosY() const
{
	return posY_;
}