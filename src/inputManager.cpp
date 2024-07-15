#include "SFML/Graphics.hpp"
#include "inputManager.h"

using namespace sf;

bool leftIsClicked()
{
	return Keyboard::isKeyPressed(Keyboard::Key::A);
}

bool rightIsClicked()
{
	return Keyboard::isKeyPressed(Keyboard::Key::D);
}

bool upIsClicked()
{
	return Keyboard::isKeyPressed(Keyboard::Key::W);

}

bool downIsClicked()
{
	return Keyboard::isKeyPressed(Keyboard::Key::S);
}

bool spaceIsClicked()
{
	return Keyboard::isKeyPressed(Keyboard::Key::Space);
}