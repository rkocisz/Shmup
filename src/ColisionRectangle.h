#ifndef COLISIONRECTANGLE_H
#define COLISIONRECTANGLE_H

#include "SFML/Graphics.hpp"

class ColisionRectangle
{
public:
	bool isColiding(ColisionRectangle enemy);
	float getPosX() const;
	float getPosY() const;
	int getWidth() const;
	int getHeight() const;
	void setPosition(float x, float y);
	void setSize(int x, int y);
	sf::RectangleShape rect;
	void updateRect();

private:
	float posX_;
	float posY_;
	int width_;
	int height_;


};


#endif

