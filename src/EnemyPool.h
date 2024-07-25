#ifndef ENEMYPOOL_H
#define ENEMYPOOL_H

#include "Enemy.h"
#include <vector>

class EnemyPool
{
public:
	EnemyPool();
	void update();
	void draw(sf::RenderWindow& window);

	std::vector<Enemy> enemies_;


private:
	sf::Texture enemyTextures_;
	sf::Texture hitEnemyTextures_;
	float elapsed_;

};

#endif