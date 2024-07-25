#ifndef SHOCKWAVE_H
#define SHOCKWAVE_H

#include "SFML/Graphics.hpp"

class Shockwave
{
public:
	Shockwave();
	void update();
	void draw(sf::RenderWindow& window);
	bool isActive() const;
	void spawn();
	void despawn();
	void setPosition(float x, float y);
	void setTargetSize(float targetSize);
	void setSpeed(float speed);


	sf::CircleShape shockwave_;
	
private:
	bool isActive_;
	float size_;
	float targetSize_;
	float posX_;
	float posY_;
	float speed_;


};

#endif 