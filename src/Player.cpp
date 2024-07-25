#include "Player.h"
#include "common.h"
#include "inputManager.h"

#include <iostream>

using namespace sf;

const int playerWidth = 32;
const int playerHeight = 32;

Player::Player(float posX, float posY)
	: fireAnimation_(nullptr)
	, posX_(posX)
	, posY_(posY)
	, hp_(3)
	, maxHp_(3)
	, immune_(false)
	, isVisible_(true)
	, elapsed_(0)
	, elapsed2_(0)
	, isHit(false)
	{
		playerTexture_.loadFromFile("../textures/spaceship.png");
		playerTextureLeft_.loadFromFile("../textures/spaceshipLeft.png");
		playerTextureRight_.loadFromFile("../textures/spaceshipRight.png");
		fireTextures_.loadFromFile("../textures/fireAnimation.png");

		fireAnimation_ = new Animation(&fireTextures_, Vector2u(5, 1), 0.05f);

		player_.setSize(Vector2f(playerWidth, playerHeight));
		player_.setPosition(posX_, posY_);
		player_.setTexture(&playerTexture_);
		fire_.setSize(Vector2f(32, 32));
		fire_.setPosition(posX_, posY + 34);
		fire_.setTexture(&fireTextures_);
		colisionRectangle_.setSize(32, 32);
	}

void Player::update()
{
	fireAnimation_->run(0);

	fire_.setTextureRect(fireAnimation_->uvRect_);

	colisionRectangle_.setSize(32, 32);
	colisionRectangle_.setPosition(posX_, posY_);


	player_.setTexture(&playerTexture_);


	if (leftIsClicked())
	{
		moveLeft();
		player_.setTexture(&playerTextureLeft_);

		fire_.setPosition(posX_ - 1, posY_ + 34);
	}

	if (rightIsClicked())
	{
		moveRight();
		player_.setTexture(&playerTextureRight_);

		fire_.setPosition(posX_ + 1, posY_ + 34);
	}

	if (upIsClicked())
	{
		moveUp();

		fire_.setPosition(posX_, posY_ + 34);
	}

	if (downIsClicked())
	{
		moveDown();

		fire_.setPosition(posX_, posY_ + 34);
	}

	if (leftIsClicked() && rightIsClicked())
	{
		player_.setTexture(&playerTexture_);
	}

	if(isHit)
	{
		looseHp();
		makeImmune();
		isHit = false;
	}

	if (isImmune())
	{
		elapsed_ += targetFrameTime;
		elapsed2_ += targetFrameTime;

		if (elapsed2_ >= 0.1)
		{
			elapsed2_ = 0;
			isVisible_ = !isVisible_;
		}


		if (elapsed_ >= 2)
		{
			isVisible_ = true;
			stopImmunity();
			elapsed_ = 0;
		}
	}

	

}

void Player::draw(sf::RenderWindow& window)
{
//	if (!isImmune())
//	{
//		window.draw(player_);
//		window.draw(fire_);
//	}

//	if (isImmune())
//	{
		if (isVisible_)
		{
			window.draw(player_);
			window.draw(fire_);
		}
//	}

}


void Player::moveLeft()
{
	posX_ -= 3;
	if (posX_ < 0)
		posX_ = 0;

	colisionRectangle_.setPosition(posX_ + 2, posY_);
	colisionRectangle_.setSize(28, 32);

	player_.setPosition(posX_, posY_);
}

void Player::moveRight()
{
	posX_ += 3;
	if (posX_ >= windowWidth - 32)
		posX_ = windowWidth - 32;
	
	colisionRectangle_.setPosition(posX_ + 2, posY_);
	colisionRectangle_.setSize(28, 32);

	player_.setPosition(posX_, posY_);

}

void Player::moveUp()
{
	posY_ -= 3;
	if (posY_ < 0)
		posY_ = 0;

	colisionRectangle_.setPosition(posX_, posY_);

	player_.setPosition(posX_, posY_);

}

void Player::moveDown()
{
	posY_ += 3;
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

void Player::hit()
{
	isHit = true;
}


