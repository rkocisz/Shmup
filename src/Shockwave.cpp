#include "Shockwave.h"

Shockwave::Shockwave()
: isActive_(false)
, targetSize_(6)
, size_(2)
, speed_(0.4)
{
	shockwave_.setFillColor(sf::Color::Transparent);
	shockwave_.setOutlineColor(sf::Color::White);
	shockwave_.setRadius(10);
	shockwave_.setOutlineThickness(2);

}

void Shockwave::update()
{
	if (isActive_)
	{
		shockwave_.setPosition(posX_, posY_);
		shockwave_.setRadius(size_);
		size_ += speed_;
		posX_ -= speed_;
		posY_ -= speed_;

		if(size_ >= targetSize_)
		{
			size_ = 2;
			despawn();
		}
	
	}

}

void Shockwave::draw(sf::RenderWindow& window)
{
	if(isActive_)
	{
		window.draw(shockwave_);
	}
}

bool Shockwave::isActive() const
{
	return isActive_;
}

void Shockwave::spawn()
{
	isActive_ = true;
}

void Shockwave::despawn()
{
	isActive_ = false;
}

void Shockwave::setPosition(float x, float y)
{
	posX_ = x;
	posY_ = y;

	shockwave_.setPosition(posX_, posY_);
}

void Shockwave::setTargetSize(float targetSize)
{
	targetSize_ = targetSize;
}

void Shockwave::setSpeed(float speed)
{
	speed_ = speed;
}
