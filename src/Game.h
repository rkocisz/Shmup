#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Bullet.h"
#include "Animation.h"
#include "Enemy.h"
#include "deltaTime.h"


class Game {
public:
	Game();
	~Game();
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	Player* player1_;
	Animation* fireAnimation_;
	Animation* enemyAnimation_;
	std::vector<Bullet> bullets_;
	std::vector<Enemy> enemies_; 
	std::vector<sf::RectangleShape> starField_;
	sf::Texture fireTextures_;
	sf::Texture playerTexture_;
	sf::Texture playerTextureLeft_;
	sf::Texture playerTextureRight_;
	sf::Texture bulletTexture_;
	sf::Texture enemyTextures_;
	sf::Texture heartTexture_;
	sf::Texture emptyHeartTexture_;
	sf::Texture hitEnemyTextures_;
	sf::RectangleShape fire_;
	sf::RectangleShape heart_;
	sf::RectangleShape emptyHeart_;
	sf::Font font_;
	sf::Text gameName_;
	sf::Text startText_;
	sf::Text gameOver_;	
	float deltaTime_;	
	int gameState_;
	

	float elapsed_;
	float elapsed2_;
	float elapsed3_;

	void updateGame();
	void updateStart();
	void updateOver();
	void startGame();

	void drawGame(sf::RenderWindow& window);
	void drawStart(sf::RenderWindow& window);
	void drawOver(sf::RenderWindow& window);

};

#endif
