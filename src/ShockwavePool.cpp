#include "ShockwavePool.h"

ShockwavePool::ShockwavePool()
{
	shockwaves_.reserve(10);

	for(int i = 0; i < 10; i++)
	{
		shockwaves_.emplace_back();
	}

}

void ShockwavePool::update(std::vector<Bullet> bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if(bullets[i].isHit())
		{
			for (int j = 0; j < shockwaves_.size(); j++)
			{
				if (shockwaves_[j].isActive() == false)
				{
					shockwaves_[j].spawn();
					shockwaves_[j].setPosition(bullets[i].getPosX() + 12, bullets[i].getPosY());
					break;
				}
			}
		}
		
	}


	for (int i = 0; i < shockwaves_.size(); i++)
	{
		shockwaves_[i].update();
	}
}

void ShockwavePool::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < shockwaves_.size(); i++)
	{
		shockwaves_[i].draw(window);
	}
}
