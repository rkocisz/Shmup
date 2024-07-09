#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Bullet.h"
#include "Animation.h"


class Game {
public:
	Game();
	~Game();
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);

private:
	Player* player1_;
//	Animation* goLeftAnimation_;
//	Animation* goRightAnimation_;
	Animation* fireAnimation_;
	std::vector<Bullet> bullets_;
	std::vector<sf::RectangleShape> starField;
	sf::Texture fireTextures_;
	sf::Texture playerTexture_;
	sf::Texture playerTextureLeft_;
	sf::Texture playerTextureRight_;
	sf::Texture bulletTexture_;
	sf::RectangleShape fire;

	float elapsed_; // in seconds
	

};

#endif
