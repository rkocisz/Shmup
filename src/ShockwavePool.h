#ifndef SHOCKWAVEPOOL_H
#define SHOCKWAVEPOOL_H

#include "Shockwave.h"
#include "SFML/Graphics.hpp"
#include "Bullet.h"

class ShockwavePool
{
public:
	ShockwavePool();
	void update(std::vector<Bullet> bullets);
	void draw(sf::RenderWindow& window);

	std::vector<Shockwave> shockwaves_;

private:

};

#endif 