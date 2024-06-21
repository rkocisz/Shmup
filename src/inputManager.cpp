#include "SFML/Graphics.hpp"
#include "inputManager.h"

using namespace sf;

bool leftIsClicked()
{
	if(Keyboard::isKeyPressed(Keyboard::Key::A))
		return true;
	return false;
}

bool rightIsClicked()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::D))
		return true;
	return false;
}

bool upIsClicked()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::W))
		return true;
	return false;
}

bool downIsClicked()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::S))
		return true;
	return false;
}

bool spaceIsClicked()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Space))
		return true;
	return false;
}