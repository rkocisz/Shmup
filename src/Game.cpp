#include"Game.h"

#include "Player.h"
#include "Bullet.h"
#include "inputManager.h"
#include "common.h"
#include "makeStars.h"

using namespace sf;

Game::Game()
	: player1_(nullptr)
	, fireAnimation_(nullptr)
{
	playerTexture_.loadFromFile("../textures/spaceship.png");
	playerTextureLeft_.loadFromFile("../textures/spaceshipLeft.png");
	playerTextureRight_.loadFromFile("../textures/spaceshipRight.png");
	bulletTexture_.loadFromFile("../textures/bullet.png");
	fireTextures_.loadFromFile("../textures/fireAnimation.png");

	player1_ = new Player(300, 300, &playerTexture_);
	fireAnimation_ = new Animation(&fireTextures_, Vector2u(5, 1), 0.05f);

	elapsed_ = 0.f;

	makeStars(starField);

	fire.setSize(Vector2f(32, 32));
	fire.setTexture(&fireTextures_);
	fire.setPosition(player1_->getPosX(), player1_->getPosY() + 34);
}

Game::~Game()
{
	delete player1_;
	delete fireAnimation_;
}

void Game::update(RenderWindow& window)
{
	player1_->setTexture(&playerTexture_);
	
	fireAnimation_->run(0);
	fire.setTextureRect(fireAnimation_->uvRect_);

	if (leftIsClicked())
	{
		player1_->moveLeft();
		player1_->setTexture(&playerTextureLeft_);
		
		fire.setPosition(player1_->getPosX() - 1, player1_->getPosY() + 34);
	}

	if (rightIsClicked())
	{
		player1_->moveRight();
		player1_->setTexture(&playerTextureRight_);
		
		fire.setPosition(player1_->getPosX() + 1, player1_->getPosY() + 34);
	}

	if (upIsClicked())
	{
		player1_->moveUp();
		
		fire.setPosition(player1_->getPosX(), player1_->getPosY() + 34);
	}

	if (downIsClicked())
	{
		player1_->moveDown();
		
		fire.setPosition(player1_->getPosX(), player1_->getPosY() + 34);
	}

	if (leftIsClicked() && rightIsClicked())
	{
		player1_->setTexture(&playerTexture_);
	}

	if (spaceIsClicked())
	{
		elapsed_ += frameTime;

		if (elapsed_ >= bulletFireDelay)
		{
			bullets_.emplace_back(&bulletTexture_);
			bullets_.back().shoot(player1_);

			elapsed_ = 0.f;
		}
	}
	else
	{
		elapsed_ = 0.24f;
	}


	for (Bullet& bullet : bullets_)
		bullet.moveUp();

	auto fun = [](const Bullet& bullet) -> bool { return bullet.getPosY() < -32; };

	bullets_.erase(std::remove_if(bullets_.begin(), bullets_.end(), fun), bullets_.end());

	updateStars(starField);

}


void Game::draw(sf::RenderWindow& window)
{
	for(int i = 0; i < starField.size(); i++)
		window.draw(starField[i]);

	for (int i = 0; i < bullets_.size(); i++)
		window.draw(bullets_[i].bullet_);

	window.draw(player1_->player_);
	window.draw(fire);
}
