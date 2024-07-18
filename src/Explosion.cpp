#include"Explosion.h"

Explosion::Explosion(sf::Texture* texture)
: isActive_(false)
, texture_(texture)
, explosionAnimation_(nullptr)
{
	explosionAnimation_ = new Animation(texture_, sf::Vector2u(5, 1), 1.0f);
	explosion_.setTexture(texture_);
	explosion_.setSize(sf::Vector2f(32, 32));
}

void Explosion::setPosition(float x, float y)
{
	posX_ = x;
	posY_ = y;
	explosion_.setPosition(x, y);
}

bool Explosion::isActive() const
{
	return isActive_;
}

void Explosion::spawn()
{
	isActive_ = true;
}

void Explosion::despawn()
{
	isActive_ = false;
}
