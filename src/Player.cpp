#include "Player.h"

using namespace sf;

const int playerWidth = 32;
const int playerHeight = 32;

Player::Player(int posX, int posY, const sf::Texture* texture)
	: posX_(posX)
	, posY_(posY)
	, texture_(texture)
	{
		player_.setSize(Vector2f(playerWidth, playerHeight));
		player_.setPosition(posX_, posY_);
		player_.setTexture(texture_);
	}

void Player::moveLeft()
{
	posX_ -= 2;
	player_.setPosition(posX_, posY_);
}

void Player::moveRight()
{
	posX_ += 2;
	player_.setPosition(posX_, posY_);
}

void Player::moveUp()
{
	posY_ -= 2;
	player_.setPosition(posX_, posY_);
}

void Player::moveDown()
{
	posY_ += 2;
	player_.setPosition(posX_, posY_);
}

int Player::getPosX() const
{
	return posX_;
}

int Player::getPosY() const
{
	return posY_;
}