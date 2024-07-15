#include "windowLoop.h"
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "common.h"

#include <iostream>
#include <vector>

using namespace sf;

void windowLoop()
{
	RenderWindow window(VideoMode(windowWidth, windowHeight), "mocna gierka", Style::Close | Style::Resize);
//	window.setFramerateLimit(60);
	
	Game game;

	while(window.isOpen())
	{
		window.clear(Color::Black);
		
		sf::Event evnt;
		while(window.pollEvent(evnt))
		{
			if(evnt.type == evnt.Closed)
				window.close();
		}

		game.update(window);
		game.draw(window);

		
		window.display();
	
		
	}
}
