#include"Explosion.h"
#include "makeStars.h"
#include"common.h"

Explosion::Explosion()
: isActive_(false)
, isDone_(false)
, elapsed_(0)
{
	for(int i = 0; i < 30; i++)
	{
		particles_.push_back(Particle());
	}

	shockwave_.setTargetSize(83);
	shockwave_.setSpeed(5.5);

}

void Explosion::update(std::vector<Enemy> enemies)
{


	if (isActive_)
	{
		elapsed_ += targetFrameTime;

		shockwave_.update();

		for (int i = 0; i < particles_.size(); i++)
		{
			if(particles_[i].isActive())
			{
				particles_[i].particle_.setFillColor(sf::Color::White);
				particles_[i].particle_.setRadius(particles_[i].getSize());
				particles_[i].age_ += targetFrameTime;
				particles_[i].move(particles_[i].spdX_, particles_[i].spdY_);

				particles_[i].multiplySpeed(0.94, 0.94);

				if(particles_[i].age_ > 0.15)
				{
					particles_[i].particle_.setFillColor(sf::Color::Yellow);
				}
				if(particles_[i].age_ > 0.25)
				{
					particles_[i].particle_.setFillColor(sf::Color(255, 106, 0, 255));
				}
				if (particles_[i].age_ > 0.35)
				{
					particles_[i].particle_.setFillColor(sf::Color(255, 35, 35, 255));
				}
				if (particles_[i].age_ > 0.4)
				{
					particles_[i].particle_.setFillColor(sf::Color(127, 0, 0, 255));
				}
				if (particles_[i].age_ > 0.55)
				{
					particles_[i].particle_.setFillColor(sf::Color(96, 96, 96, 255));
				}

				if(particles_[i].age_ >= particles_[i].maxAge_)
				{
					particles_[i].changeSize(-1);
					particles_[i].move(1, 1);
					if(particles_[i].getSize() <= 0)
					{ 
						particles_[i].despawn();
					}
				}
			}
		}

		if(elapsed_ >= 0.8f)
		{
			isDone_ = true;
			for(int i = 0; i < particles_.size(); i++)
			{
				if(particles_[i].isActive())
					isDone_ = false;
			}

			if(shockwave_.isActive())
				isDone_ = false;

		if(isDone_)
		{
			elapsed_ = 0;
			despawn();
		}
		}
	}
}


void Explosion::draw(sf::RenderWindow& window)
{
	if(isActive_)
	{
		for(int i = 0; i < particles_.size(); i++)
		{
			if(particles_[i].isActive())
			{
				window.draw(particles_[i].particle_);
			}
		}
	
		shockwave_.draw(window);
	}
}

void Explosion::setPosition(float x, float y)
{
	posX_ = x;
	posY_ = y;
	for (int i = 0; i < particles_.size(); i++)
	{
		particles_[i].setPosition(posX_ + 16, posY_ + 16);
	}
}

bool Explosion::isActive() const
{
	return isActive_;
}

void Explosion::spawn()
{
	isActive_ = true;
	for (int i = 0; i < particles_.size(); i++)
	{
		particles_[i].setSize(getRandomFloat(6, 12));
		particles_[i].setSpeed(getRandomFloat(-4, 4), getRandomFloat(-4, 4));
		particles_[i].spawn();
		particles_[i].age_ = getRandomFloat(-0.2, 0);
		shockwave_.spawn();
		shockwave_.setPosition(posX_ + 16, posY_ + 16);
		
	}
}

void Explosion::despawn()
{
	isActive_ = false;
}
