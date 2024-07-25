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
	, gameState_(0)
	, elapsed_(0)
	, elapsed1_(0)
	, elapsed2_(0)
	, elapsed3_(0)
{
	enemyTextures_.loadFromFile("../textures/enemyAnimation.png");
	explosionTextures_.loadFromFile("../textures/explosionAnimation.png");
	heartTexture_.loadFromFile("../textures/heart.png");
	emptyHeartTexture_.loadFromFile("../textures/emptyHeart.png");
	hitEnemyTextures_.loadFromFile("../textures/hitEnemyAnimation.png");
	font_.loadFromFile("../fonts/Square.ttf");



	player1_ = new Player(448, 254);


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

	makeStars(starField_);
}


Game::~Game()
{
	delete player1_;
}


void Game::update(RenderWindow& window)
{
	updateDeltaTime(deltaTime_);

	elapsed_ += deltaTime_;
	if(elapsed_ >= targetFrameTime)
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

	elapsed_ -= targetFrameTime;

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
	updateStars(starField_);

	player1_->update();

	bulletPool_.update(player1_);

	enemyPool_.update();

	explosions_.update(enemyPool_.enemies_);

	collisionDetection();

	shockwaves_.update(bulletPool_.bullets_);

	if (player1_->getHp() <= 0)
		gameState_ = 2;
}



void Game::updateStart()
{
	updateStars(starField_);

	elapsed1_ += targetFrameTime;


	if (elapsed1_ > 1.4f)
		elapsed1_ = 0;

	if(spaceIsClicked())
	{
		startGame();
		elapsed1_ = 0;
	}
}

void Game::updateOver()
{
	updateStars(starField_);
	startText_.setString("Press space to restart");
	startText_.setPosition(200, 400);

	elapsed1_ += targetFrameTime;


	if (elapsed1_ > 1.4f)
		elapsed1_ = 0;

	if (spaceIsClicked())
	{
		startGame();
		elapsed1_ = 0;
	}
}


void Game::drawGame(sf::RenderWindow& window)
{
	for (int i = 0; i < starField_.size(); i++)
		window.draw(starField_[i]);

	bulletPool_.draw(window);

	enemyPool_.draw(window);

	player1_->draw(window);

	explosions_.draw(window);

	shockwaves_.draw(window);

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

	if (elapsed1_ < 0.7f)
	{
		window.draw(startText_);
	}

	window.draw(gameName_);
}

void Game::drawOver(sf::RenderWindow& window)
{
	for (int i = 0; i < starField_.size(); i++)
		window.draw(starField_[i]);

	if (elapsed1_ < 0.7f)
	{
		window.draw(startText_);
	}

	window.draw(gameOver_);
}

void Game::collisionDetection()
{
	for(int i = 0; i < enemyPool_.enemies_.size(); i++)
	{
		if(enemyPool_.enemies_[i].isActive())
		{
			for (int j = 0; j < bulletPool_.bullets_.size(); j++)
			{
				if (bulletPool_.bullets_[j].colisionRectangle_.isColiding(enemyPool_.enemies_[i].colisionRectangle_))
				{
					bulletPool_.bullets_[j].hit();
					enemyPool_.enemies_[i].hit();
				}

				if (!player1_->isImmune())
				{
					if (player1_->colisionRectangle_.isColiding(enemyPool_.enemies_[i].colisionRectangle_))
						player1_->hit();
				}
			}
		}
	}

}

void Game::startGame()
{
	gameState_ = 1;

	player1_->setPosition(464, 254);
	player1_->fire_.setPosition(player1_->getPosX(), player1_->getPosY() + 34);
	player1_->stopImmunity();

	for (int i = 0; i < bulletPool_.bullets_.size(); i++)
		bulletPool_.bullets_[i].setPosition(0, -32);

	player1_->setHp(3);
}