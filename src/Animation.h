#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float animationFrameTime);
	void run(int row);
	int getCurrentFrame();

	sf::RectangleShape frame_;
	sf::IntRect uvRect_;


private:
	float animationFrameTime_;
	float elapsed_;
	int currentFrame_;
	int currentRow_;
	sf::Vector2u textureSize_;
	sf::Vector2u imageCount_;
};


#endif
