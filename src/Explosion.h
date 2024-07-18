#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "SFML/Graphics.hpp"
#include "Animation.h"

class Explosion
{
public:
	
	Explosion(sf::Texture* texture);
	void setPosition(float x, float y);

	sf::RectangleShape explosion_;
	Animation* explosionAnimation_;

	bool isActive() const;
	void spawn();
	void despawn();

private:
	float posX_;
	float posY_;
	bool isActive_;
	sf::Texture* texture_;
};

#endif