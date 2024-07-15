#include "ColisionRectangle.h"
#include <iostream>

bool ColisionRectangle::isColiding(ColisionRectangle enemy)
{

	if (posX_ + width_ >= enemy.getPosX() && posX_ + width_ <= enemy.getPosX() + enemy.width_ && posY_ >= enemy.getPosY() && posY_ <= enemy.getPosY() + enemy.getHeight())
	{
		//std::cout << "collision";
		return true;
	}
	if (posX_ + width_ >= enemy.getPosX() && posX_ + width_ <= enemy.getPosX() + enemy.getWidth() && posY_ + height_ >= enemy.getPosY() && posY_ + height_ <= enemy.getPosY() + enemy.getHeight())
	{
		//std::cout << "collision";
		return true;
	}
	
	if (posX_ >= enemy.getPosX() && posX_ <= enemy.getPosX() + enemy.getWidth() && posY_ + height_ >= enemy.getPosY() && posY_ + height_ <= enemy.getPosY() + enemy.getHeight())
	{
		//std::cout << "collision";
		return true;
	}
	if (posX_ >= enemy.getPosX() && posX_ <= enemy.getPosX() + enemy.getWidth() && posY_ >= enemy.getPosY() && posY_ <= enemy.getPosY() + enemy.getHeight())
	{
		//std::cout << "collision";
		return true;
	}

	return false;
}

float ColisionRectangle::getPosX() const
{
	return posX_;
}

float ColisionRectangle::getPosY() const
{
	return posY_;
}

int ColisionRectangle::getWidth() const
{
	return width_;
}

int ColisionRectangle::getHeight() const
{
	return height_;
}

void ColisionRectangle::setPosition(float x, float y)
{
	posX_ = x;
	posY_ = y;
}

void ColisionRectangle::setSize(int x, int y)
{
	width_ = x;
	height_ = y;
}

void ColisionRectangle::updateRect()
{
	rect.setFillColor(sf::Color::Red);
	rect.setSize(sf::Vector2f(width_, height_));
	rect.setPosition(posX_, posY_);
}
