#include "BulletPool.h"
#include "common.h"
#include "inputManager.h"


BulletPool::BulletPool()
: elapsed_(0)
{
	bulletTexture_.loadFromFile("../textures/bullet.png");

	bullets_.reserve(128);
	Bullet bullet(&bulletTexture_);

	for (int i = 0; i < 128; i++)
	{
		bullets_.push_back(bullet);
	}


}

void BulletPool::update(Player* player1)
{
	if (spaceIsClicked())
	{
		elapsed_ += targetFrameTime;

		if (elapsed_ >= bulletFireDelay)
		{
			for (int i = 0; i < bullets_.size(); i++)
			{
				if (bullets_[i].isActive() == false)
				{
					bullets_[i].spawn();
					bullets_[i].shoot(player1);
					break;
				}

			}

			elapsed_ = 0.f;
		}
	}
	else
	{
		elapsed_ = 0.24f;
	}


	for (int i = 0; i < bullets_.size(); i++)
	{
		bullets_[i].update();
	}

}

void BulletPool::draw(sf::RenderWindow& window)
{
	for(int i = 0; i < bullets_.size(); i++)
	{
		if (bullets_[i].isActive())
			bullets_[i].draw(window);
	}

}
