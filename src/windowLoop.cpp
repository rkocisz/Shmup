#include "windowLoop.h"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "gameLogic.h"
#include "inputManager.h"
#include "Bullet.h"

#include <iostream>
#include <vector>

using namespace sf;

void windowLoop()
{
	RenderWindow window(VideoMode(960,540), "mocna gierka", Style::Close);
	window.setFramerateLimit(60);

	Texture playerTexture;
	playerTexture.loadFromFile("../textures/spaceship.png");
	Texture bulletTexture;
	bulletTexture.loadFromFile("../textures/bullet.png");


	Player player1(100, 100, &playerTexture);
	std::vector<Bullet> bullets;

	//for(int i = 0; i < 10; i++)
	//{
	//	Bullet bullet(&bulletTexture);
	//	bullets.push_back(bullet);
	//}

	float elapsed = 0.f; // in seconds

	while(window.isOpen())
	{
		window.clear(Color::Black);
		
		sf::Event evnt;
		while(window.pollEvent(evnt))
		{
			if(evnt.type == evnt.Closed)
				window.close();
		}

		gameLogic(player1, bullets, elapsed, &bulletTexture);

		for(const Bullet& bullet : bullets)
			window.draw(bullet.bullet_);

		window.draw(player1.player_);

		window.display();
	}
}