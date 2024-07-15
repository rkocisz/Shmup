#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "inputManager.h"
#include "common.h"
#include "makeStars.h"

#include <iostream>

using namespace sf;

Game::Game()
	: player1_(nullptr)
	, fireAnimation_(nullptr)
	, enemyAnimation_(nullptr)
	, gameState_(0)
	, elapsed_(0)
	, elapsed2_(0)
	, elapsed3_(0)
{
	playerTexture_.loadFromFile("../textures/spaceship.png");
	playerTextureLeft_.loadFromFile("../textures/spaceshipLeft.png");
	playerTextureRight_.loadFromFile("../textures/spaceshipRight.png");
	bulletTexture_.loadFromFile("../textures/bullet.png");
	fireTextures_.loadFromFile("../textures/fireAnimation.png");
	enemyTextures_.loadFromFile("../textures/enemyAnimation.png");
	heartTexture_.loadFromFile("../textures/heart.png");
	emptyHeartTexture_.loadFromFile("../textures/emptyHeart.png");
	hitEnemyTextures_.loadFromFile("../textures/hitEnemyAnimation.png");
	font_.loadFromFile("../fonts/Square.ttf");


	player1_ = new Player(448, 254, &playerTexture_);
	fireAnimation_ = new Animation(&fireTextures_, Vector2u(5, 1), 0.05f);
	enemyAnimation_ = new Animation(&enemyTextures_, Vector2u(4, 1), 0.7f);

	fire_.setSize(Vector2f(32, 32));
	fire_.setTexture(&fireTextures_);
	fire_.setPosition(player1_->getPosX(), player1_->getPosY() + 34);
	heart_.setSize(Vector2f(32, 32));
	heart_.setTexture(&heartTexture_);
	emptyHeart_.setSize(Vector2f(32, 32));
	emptyHeart_.setTexture(&emptyHeartTexture_);

	gameName_.setFont(font_);
	gameName_.setCharacterSize(90);
	gameName_.setString("Just a shmup");
	gameName_.setPosition(180, 130);
	gameName_.setFillColor(Color::Blue);
	startText_.setFont(font_);
	startText_.setString("Press space to start");
	startText_.setCharacterSize(45);
	startText_.setPosition(220, 400);
	startText_.setFillColor(Color::Cyan);
	gameOver_.setFont(font_);
	gameOver_.setCharacterSize(90);
	gameOver_.setString("Game over");
	gameOver_.setPosition(245, 130);
	gameOver_.setFillColor(Color::Red);

	Enemy enemy(&enemyTextures_);
	enemy.setPosition(300, 50);
	Bullet bullet(&bulletTexture_);

	for (int i = 0; i < 128; i++)
	{
		enemies_.push_back(enemy);
	}

	for (int i = 0; i < 128; i++)
	{
		bullets_.push_back(bullet);
	}

	for(int i = 0; i < 10; i++)
	{

		enemies_[i].setPosition(300 + i * 50, 50);
		enemies_[i].spawn();
	}

	makeStars(starField_);
}


Game::~Game()
{
	delete player1_;
	delete fireAnimation_;
	delete enemyAnimation_;
}


void Game::update(RenderWindow& window)
{
	switch (gameState_)
	{
	case 0:
		updateStart();
		break;

	case 1:
		updateGame();
		break;

	case 2:
		updateOver();
		break;
	}
}


void Game::draw(sf::RenderWindow& window)
{
	switch (gameState_)
	{
	case 0:
		drawStart(window);
		break;

	case 1:
		drawGame(window);
		break;
	case 2:
		drawOver(window);
		break;
	}
}


void Game::updateGame()
{
	updateDeltaTime(deltaTime_);

	player1_->colisionRectangle_.setSize(32, 32);
	player1_->colisionRectangle_.setPosition(player1_->getPosX(), player1_->getPosY());

//animations
	player1_->setTexture(&playerTexture_);


	fireAnimation_->run(0, deltaTime_);
	enemyAnimation_->run(0, deltaTime_);

	fire_.setTextureRect(fireAnimation_->uvRect_);

		for (int i = 0; i < enemies_.size(); i++)
		{
			if(enemies_[i].isActive())
			enemies_[i].enemy_.setTextureRect(enemyAnimation_->uvRect_);
		}

	updateStars(starField_, deltaTime_);

//moving stuff
	if (leftIsClicked())
	{
		player1_->moveLeft(deltaTime_);
		player1_->setTexture(&playerTextureLeft_);

		fire_.setPosition(player1_->getPosX() - 1, player1_->getPosY() + 34);
	}

	if (rightIsClicked())
	{
		player1_->moveRight(deltaTime_);
		player1_->setTexture(&playerTextureRight_);

		fire_.setPosition(player1_->getPosX() + 1, player1_->getPosY() + 34);
	}

	if (upIsClicked())
	{
		player1_->moveUp(deltaTime_);

		fire_.setPosition(player1_->getPosX(), player1_->getPosY() + 34);
	}

	if (downIsClicked())
	{
		player1_->moveDown(deltaTime_);

		fire_.setPosition(player1_->getPosX(), player1_->getPosY() + 34);
	}

	if (leftIsClicked() && rightIsClicked())
	{
		player1_->setTexture(&playerTexture_);
	}

//shooting
	if (spaceIsClicked())
	{
		elapsed_ += deltaTime_;

		if (elapsed_ >= bulletFireDelay)
		{
			for(int i = 0; i < bullets_.size(); i++)
			{
				if (bullets_[i].isActive() == false)
				{
					bullets_[i].spawn();
					bullets_[i].shoot(player1_);
					break;
				}
			
			}

			elapsed_ = 0.f;
		}
	}
	else
	{
		elapsed_ = 0.24f;
	}


	for (int i = 0; i < bullets_.size(); i++)
	{
		if (bullets_[i].isActive())
		{
			bullets_[i].moveUp(deltaTime_);
		}
		
		if(bullets_[i].getPosY() < -32)
			bullets_[i].kill();
	}
	

//collision detection
	for (int i = 0; i < enemies_.size(); i++)
	{
		if(enemies_[i].isActive())
		{
				enemies_[i].colisionRectangle_.setPosition(enemies_[i].getPosX(), enemies_[i].getPosY());
				
				for (int j = 0; j < bullets_.size(); j++)
				{
					if(bullets_[j].colisionRectangle_.isColiding(enemies_[i].colisionRectangle_))
					{
						std::cout << "col";
						bullets_[j].kill();
						enemies_[i].looseHp();
						enemies_[i].enemy_.setTexture(&hitEnemyTextures_);
						elapsed3_ = 0;
					}
				}

				if(enemies_[i].isHit())
				{
					elapsed3_ += deltaTime_;
					if(elapsed3_ >= 30 * deltaTime_)
					{
						enemies_[i].enemy_.setTexture(&enemyTextures_);
						elapsed3_ = 0;
					}
				}

				if (!player1_->isImmune())
				{
					if (player1_->colisionRectangle_.isColiding(enemies_[i].colisionRectangle_))
					{
						player1_->looseHp();
						player1_->makeImmune();
					}
				}

				if (player1_->isImmune())
				{
					elapsed2_ += deltaTime_;
					if (elapsed2_ >= 30)
					{
						player1_->stopImmunity();
						elapsed2_ = 0;
					}
				}

				if (enemies_[i].getHp() <= 0)
					enemies_[i].kill();
		}
	}
	if (player1_->getHp() <= 0)
		gameState_ = 2;

}


void Game::updateStart()
{
	updateDeltaTime(deltaTime_);
	updateStars(starField_, deltaTime_);

	elapsed_ += deltaTime_;


	if (elapsed_ > 1.4f)
		elapsed_ = 0;

	if(spaceIsClicked())
	{
		startGame();
		elapsed_ = 0;
	}
}

void Game::updateOver()
{
	updateDeltaTime(deltaTime_);
	updateStars(starField_, deltaTime_);
	startText_.setString("Press space to restart");
	startText_.setPosition(200, 400);

	elapsed_ += deltaTime_;


	if (elapsed_ > 1.4f)
		elapsed_ = 0;

	if (spaceIsClicked())
	{
		startGame();
		elapsed_ = 0;
	}
}


void Game::drawGame(sf::RenderWindow& window)
{
	for (int i = 0; i < starField_.size(); i++)
		window.draw(starField_[i]);

	for (int i = 0; i < bullets_.size(); i++)
	{
		if(bullets_[i].isActive())
			window.draw(bullets_[i].bullet_);
	}

	for (int i = 0; i < enemies_.size(); i++)
	{
		if(enemies_[i].isActive())
			window.draw(enemies_[i].enemy_);
	}


	if(!player1_->isImmune())
	{
		window.draw(player1_->player_);
		window.draw(fire_);
	}
	
	if (player1_->isImmune())
	{
		if((int)elapsed2_ % 5 >= 2 && (int)elapsed2_ % 5 <= 4)
			{
			window.draw(player1_->player_);
			window.draw(fire_);
			}
	}



	for(int i = 0; i < player1_->getHp(); i++)
	{
		heart_.setPosition(4 + i * 36, 504);
		window.draw(heart_);
	}
	for (int i = 1; i < player1_->maxHp_ - player1_->getHp() + 1; i++)
	{
		emptyHeart_.setPosition(heart_.getPosition().x + 4 + i * 32, 504);
		window.draw(emptyHeart_);
	}
}

void Game::drawStart(sf::RenderWindow& window)
{
	for (int i = 0; i < starField_.size(); i++)
		window.draw(starField_[i]);

	if (elapsed_ < 0.7f)
	{
		window.draw(startText_);
	}

	window.draw(gameName_);
}

void Game::drawOver(sf::RenderWindow& window)
{
	for (int i = 0; i < starField_.size(); i++)
		window.draw(starField_[i]);

	if (elapsed_ < 0.7f)
	{
		window.draw(startText_);
	}

	window.draw(gameOver_);
}

void Game::startGame()
{
	gameState_ = 1;

	player1_->setPosition(464, 254);
	fire_.setPosition(player1_->getPosX(), player1_->getPosY() + 34);
	player1_->stopImmunity();

	for (int i = 0; i < bullets_.size(); i++)
		bullets_[i].setPosition(0, -32);

	player1_->setHp(3);
}