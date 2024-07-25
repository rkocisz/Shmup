#include "EnemyPool.h"

EnemyPool::EnemyPool()
{
	enemyTextures_.loadFromFile("../textures/enemyAnimation.png");
	hitEnemyTextures_.loadFromFile("../textures/hitEnemyAnimation.png");

	Enemy enemy(&enemyTextures_, &hitEnemyTextures_);
	enemy.setPosition(300, 50);

	enemies_.reserve(128);

	for (int i = 0; i < 128; i++)
	{
		enemies_.push_back(enemy);
	}

	for(int i = 0; i < 12; i++)
	{
		enemies_[i].setPosition(300 + i * 50, 150);
		enemies_[i].spawn();
	}
}

void EnemyPool::update()
{
	for(int i = 0; i < enemies_.size(); i++)
	{
		enemies_[i].update();
	}
}

void EnemyPool::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < enemies_.size(); i++)
	{
		if(enemies_[i].isActive())
			enemies_[i].draw(window);
	}

}
