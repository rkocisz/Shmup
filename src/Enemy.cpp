#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture)
: posX_(0)
, posY_(-32)
, isActive_ (false)
, hp_(3)
{
	enemy_.setTexture(texture);
	enemy_.setSize(sf::Vector2f(32, 32));
	colisionRectangle_.setSize(32, 32);
	colisionRectangle_.setPosition(posX_, posY_);
}

void Enemy::setPosition(int x, int y)
{
	posX_ = x;
	posY_ = y;
	enemy_.setPosition(posX_, posY_);
}

void Enemy::setSize(int x, int y)
{
	enemy_.setSize(sf::Vector2f(32, 32));
}



float Enemy::getPosX() const
{
	return posX_;
}

float Enemy::getPosY() const
{
	return posY_;
}

int Enemy::getSizeX() const
{
	return enemy_.getSize().x;
}

int Enemy::getSizeY() const
{
	return enemy_.getSize().y;
}

bool Enemy::isActive() const
{
	return isActive_;
}

void Enemy::spawn()
{
	isActive_ = true;
}

void Enemy::despawn()
{
	isActive_ = false;
}

int Enemy::getHp() const
{
	return hp_;
}

void Enemy::looseHp()
{
	hp_ -= 1;
	isHit_ = true;
}

void Enemy::setHp(int hp)
{
	hp_ = hp;
}

bool Enemy::isHit() const
{
	return isHit_;
}

void Enemy::setNotHit()
{
	isHit_ = false;
}

