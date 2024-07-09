#include "Animation.h"
#include "common.h"

using namespace sf;

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float animationFrameTime)
: animationFrameTime_(animationFrameTime)
, imageCount_(imageCount)
, elapsed_(0)
,currentFrame_(0)
,currentRow_(0)
{
	

	uvRect_.width = texture->getSize().x / imageCount.x;
	uvRect_.height = texture->getSize().y / imageCount.y;
}


void Animation::run(int row)
{
	currentRow_ = row;
	
	elapsed_ += frameTime;


	if(elapsed_ >= animationFrameTime_)
	{
		currentFrame_++;
		elapsed_ -= animationFrameTime_;
	
		if (currentFrame_ >= imageCount_.x)
		{
			currentFrame_ = 0;
		}

	}
	
	uvRect_.left = currentFrame_ * uvRect_.width;
	uvRect_.top = currentRow_ * uvRect_.height;

}