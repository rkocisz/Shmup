#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Bullet.h"
#include "Animation.h"
#include "Enemy.h"
#include "deltaTime.h"
#include "Explosion.h"
#include "BulletPool.h"
#include "EnemyPool.h"
#include "ExplosionPool.h"
#include "Shockwave.h"
#include "ShockwavePool.h"

class Game {
public:
	Game();
	~Game();
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	Player* player1_;
	BulletPool bulletPool_;
	EnemyPool enemyPool_;
	ExplosionPool explosions_;
	ShockwavePool shockwaves_;
	std::vector<sf::RectangleShape> starField_;
	sf::Texture enemyTextures_;
	sf::Texture heartTexture_;
	sf::Texture explosionTextures_;
	sf::Texture emptyHeartTexture_;
	sf::Texture hitEnemyTextures_;
	sf::RectangleShape heart_;
	sf::RectangleShape emptyHeart_;
	sf::Font font_;
	sf::Text gameName_;
	sf::Text startText_;
	sf::Text gameOver_;	
	float deltaTime_;	
	int gameState_;
	

	float elapsed_;
	float elapsed1_;
	float elapsed2_;
	float elapsed3_;
	float elapsed4_;

	void updateGame();
	void updateStart();
	void updateOver();
	void startGame();

	void drawGame(sf::RenderWindow& window);
	void drawStart(sf::RenderWindow& window);
	void drawOver(sf::RenderWindow& window);

	void collisionDetection();

};

#endif
