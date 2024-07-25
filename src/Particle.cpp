#include "Particle.h"
#include "makeStars.h"

Particle::Particle()
{
	size_ = getRandomFloat(6, 12);

	particle_.setRadius(size_);
	particle_.setPosition(0, 0);
	particle_.setFillColor(sf::Color::White);
	spdX_ = getRandomFloat(-4, 4);
	spdY_ = getRandomFloat(-4, 4);
	age_ = getRandomFloat(-0.2, 0);
	maxAge_ = 0.5 + getRandomFloat(0, 0.3f);
	

}

void Particle::setPosition(float x, float y)
{
	posX_ = x;
	posY_ = y;
	particle_.setPosition(posX_, posY_);
}

void Particle::setSpeed(float x, float y)
{
	spdX_ = x;
	spdY_ = y;
}

void Particle::multiplySpeed(float x, float y)
{
	spdX_ *= x;
	spdY_ *= y;
}

void Particle::move(float x, float y)
{
	posX_ += x;
	posY_ += y;
	particle_.setPosition(posX_, posY_);

}

bool Particle::isActive() const
{
	return isActive_;
}

void Particle::setSize(float size)
{
	size_ = size;
}

void Particle::changeSize(float x)
{
	size_ += x;

}

float Particle::getSize()
{
	return size_;
}

void Particle::spawn()
{
	isActive_ = true;
}

void Particle::despawn()
{
	isActive_ = false;
}

