#ifndef BULLETPOOL_H
#define BULLETPOOL_H

#include "Player.h"
#include "Bullet.h"
#include <vector>

class BulletPool
{
public:
	BulletPool();
	void update(Player* player1);
	void draw(sf::RenderWindow& window);
	std::vector<Bullet> bullets_;


private:
	sf::Texture bulletTexture_;
	float elapsed_;

};

#endif
