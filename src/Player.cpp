#include "Player.h"
#include "common.h"

#include <iostream>

using namespace sf;

const int playerWidth = 32;
const int playerHeight = 32;

Player::Player(float posX, float posY, const sf::Texture* texture)
	: posX_(posX)
	, posY_(posY)
	, texture_(texture)
	, hp_(3)
	, maxHp_(3)
	, immune_(false)
	{
		player_.setSize(Vector2f(playerWidth, playerHeight));
		player_.setPosition(posX_, posY_);
		player_.setTexture(texture_);
		colisionRectangle_.setSize(32, 32);
	}

void Player::moveLeft()
{
	posX_ -= 5;
	if (posX_ < 0)
		posX_ = 0;

	colisionRectangle_.setPosition(posX_ + 2, posY_);
	colisionRectangle_.setSize(28, 32);

	player_.setPosition(posX_, posY_);
}

void Player::moveRight()
{
	posX_ += 5;
	if (posX_ >= windowWidth - 32)
		posX_ = windowWidth - 32;
	
	colisionRectangle_.setPosition(posX_ + 2, posY_);
	colisionRectangle_.setSize(28, 32);

	player_.setPosition(posX_, posY_);

}

void Player::moveUp()
{
	posY_ -= 5;
	if (posY_ < 0)
		posY_ = 0;

	colisionRectangle_.setPosition(posX_, posY_);

	player_.setPosition(posX_, posY_);

}

void Player::moveDown()
{
	posY_ += 5;
	if (posY_ > windowHeight - 32)
		posY_ = windowHeight - 32;

	colisionRectangle_.setPosition(posX_, posY_);

	player_.setPosition(posX_, posY_);
}

float Player::getPosX() const
{
	return posX_;
}

float Player::getPosY() const
{
	return posY_;
}

int Player::getHp() const
{
	return hp_;
}

void Player::setTexture(const sf::Texture* texture)
{
	player_.setTexture(texture);
}

void Player::setPosition(int x, int y)
{
	posX_ = x;
	posY_ = y;
	player_.setPosition(posX_, posY_);
}

void Player::looseHp()
{
	hp_ -= 1;
}

void Player::setHp(int hp)
{
	hp_ = hp;
}

bool Player::isImmune() const
{
	return immune_;
}

void Player::makeImmune()
{
	immune_ = true;
}

void Player::stopImmunity()
{
	immune_ = false;
}


//bool Player::doesTouch(int x, int y, int enemyWidth, int enemyHeight)
//{
//	for(int i = 0; i < playerWidth; i++)
//	{
//		if(posX_ + i >= x && posX_ + i <= x + enemyWidth && posY_ + i >= y && posY_ <= y + enemyHeight)
//		{
//			std::cout << "collision";
//			return true;
//		}
//
//	//	if (posX_ + i >= x && posX_ + i <= x + enemyWidth && posY_+ i >= y && posY_ <= y + enemyHeight)
//	//	{
//	//		std::cout << "collision";
//	//		return true;
//	//	}
//	}
//
//
//	return false;
//}
