#ifndef PARTICLE_H
#define PARTICLE_H

#include "SFML/Graphics.hpp"

class Particle
{
public:
	Particle();

	sf::CircleShape particle_;
	void setPosition(float x, float y);
	void setSpeed(float x, float y);
	void multiplySpeed(float x, float y);
	void move(float x, float y);
	bool isActive() const;
	void setSize(float size);
	void changeSize(float x);
	float getSize();
	void spawn();
	void despawn();

	float spdX_;
	float spdY_;
	float age_;
	float maxAge_;

private:
	float posX_;
	float posY_;
	float size_;
	bool isActive_;

};

#endif 