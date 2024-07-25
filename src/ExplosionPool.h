#ifndef EXPLOSIONPOOL_H
#define EXPLOSIONPOOL_H

#include "Explosion.h"

class ExplosionPool
{
public:
	ExplosionPool();
	void update(std::vector<Enemy> enemies);
	void draw(sf::RenderWindow& window);
	std::vector<Explosion> explosions_;


private:
	sf::Texture bulletTexture_;
	float elapsed_;

};

#endif
