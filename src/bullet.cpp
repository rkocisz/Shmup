#include "bullet.h"

Bullet::Bullet(const sf::Texture* texture)
: texture_ (texture)
, isActive_ (false)
{
	posX_ = 0;
	posY_ = 0;

	bullet_.setSize(sf::Vector2f(32, 32));
	bullet_.setTexture(texture_);
	bullet_.setPosition(posX_, posY_);
	colisionRectangle_.setSize(16, 32);
}

void Bullet::shoot(Player* player1)
{
	posX_ = player1->getPosX();
	posY_ = player1->getPosY() -32;
	bullet_.setPosition(posX_, posY_);
}

void Bullet::moveUp(float deltaTime)
{
	posY_ -= 600 * deltaTime;
	bullet_.setPosition(posX_, posY_);
	colisionRectangle_.setPosition(posX_ + 8, posY_);
}

int Bullet::getPosY() const
{
	return posY_;
}

void Bullet::setPosition(int x, int y)
{
	posX_ = x;
	posY_ = y;
	bullet_.setPosition(posX_, posY_);
}

bool Bullet::isActive() const
{
	return isActive_;
}

void Bullet::spawn()
{
	isActive_ = true;
}

void Bullet::kill()
{
	isActive_ = false;
	posX_ = -32;
	posY_ = -32;
	colisionRectangle_.setPosition(-100, -100);
}
