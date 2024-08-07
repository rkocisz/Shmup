#include "bullet.h"
#include "inputManager.h"
#include "common.h"

Bullet::Bullet(const sf::Texture* texture)
: texture_ (texture)
, isActive_ (false)
, isHit_ (false)
{
	posX_ = 0;
	posY_ = 0;

	bullet_.setSize(sf::Vector2f(32, 32));
	bullet_.setTexture(texture_);
	bullet_.setPosition(posX_, posY_);
	colisionRectangle_.setSize(16, 32);
}

void Bullet::update()
{
	if (isActive_)
	{
		moveUp();

		if (posY_ < -32)
		{
			despawn();
		}

		if(isHit_)
		{
			despawn();
			isHit_ = false;
		}
	}


}

void Bullet::draw(sf::RenderWindow& window)
{
	window.draw(bullet_);
}

void Bullet::shoot(Player* player1)
{
	posX_ = player1->getPosX();
	posY_ = player1->getPosY() -32;
	bullet_.setPosition(posX_, posY_);
}

void Bullet::moveUp()
{
	posY_ -= 9;
	bullet_.setPosition(posX_, posY_);
	colisionRectangle_.setPosition(posX_ + 8, posY_);
}

int Bullet::getPosX() const
{
	return posX_;
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

void Bullet::despawn()
{
	isActive_ = false;
	colisionRectangle_.setPosition(-100, -100);
}

void Bullet::hit()
{
	isHit_ = true;
}

bool Bullet::isHit() const
{
	return isHit_;
}
