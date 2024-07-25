#include "Enemy.h"
#include "common.h"

using namespace sf;

Enemy::Enemy(sf::Texture* enemyTextures, sf::Texture* hitEnemyTextures)
: enemyAnimation_(nullptr)
, posX_(0)
, posY_(-32)
, elapsed_(0)
, isActive_ (false)
, isHit_(false)
, justDied_(false)
, hp_(3)
, enemyTextures_(enemyTextures)
, hitEnemyTextures_(hitEnemyTextures)
{
	enemyAnimation_ = new Animation(enemyTextures_, Vector2u(4, 1), 100.0f);

	enemy_.setTexture(enemyTextures_);
	enemy_.setSize(sf::Vector2f(32, 32));
	colisionRectangle_.setSize(32, 32);
	colisionRectangle_.setPosition(posX_, posY_);
}

void Enemy::update()
{
	justDied_ = false;

	enemyAnimation_->run(0);

	if(isActive_)
	{
		enemy_.setTextureRect(enemyAnimation_->uvRect_);

		colisionRectangle_.setPosition(posX_, posY_);
	
		if(isHit_)
		{
			looseHp();
			enemy_.setTexture(hitEnemyTextures_);
			isHit_ = false;
			elapsed_ = 0;
		}

		if(enemy_.getTexture() == hitEnemyTextures_)
		{
			elapsed_ += targetFrameTime;
			if(elapsed_ >= 0.1f)
			{
				enemy_.setTexture(enemyTextures_);
				elapsed_ = 0;
			}
		}

		if (hp_ <= 0)
		{
			justDied_ = true;
			despawn();
		}
	}

}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(enemy_);
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
}

void Enemy::setHp(int hp)
{
	hp_ = hp;
}

bool Enemy::isHit() const
{
	return isHit_;
}

void Enemy::hit()
{
	isHit_ = true;
}

bool Enemy::didJustDie()
{
	return justDied_;
}

