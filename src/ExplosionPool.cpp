#include "ExplosionPool.h"

ExplosionPool::ExplosionPool()
{
	explosions_.reserve(10);

	for (int i = 0; i < 10; i++)
	{
		explosions_.emplace_back();
	}

}

void ExplosionPool::update(std::vector<Enemy> enemies)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if(enemies[i].didJustDie())
		{
			for(int j = 0; j < explosions_.size(); j++)
			{
				if(explosions_[j].isActive() == false)
				{
 					explosions_[j].setPosition(enemies[i].getPosX(), enemies[i].getPosY());
					explosions_[j].spawn();
					break;
				}
			}
		}
	}

	for(int i = 0; i < explosions_.size(); i++)
	{
		explosions_[i].update(enemies);
	}
}

void ExplosionPool::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < explosions_.size(); i++)
	{
		explosions_[i].draw(window);
	}
}
