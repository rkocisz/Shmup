#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Particle.h"
#include "Enemy.h"
#include "Shockwave.h"

class Explosion
{
public:
	
	
	Explosion();
	void update(std::vector<Enemy> enemies);
	void draw(sf::RenderWindow& window);
	void setPosition(float x, float y);
	bool isActive() const;
	void spawn();
	void despawn();

	Shockwave shockwave_;
	std::vector<Particle> particles_;

private:
	float posX_;
	float posY_;
	float elapsed_;
	bool isActive_;
	bool isDone_;
};

#endif