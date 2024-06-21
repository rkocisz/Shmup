#include "gameLogic.h"
#include "inputManager.h"
#include "Player.h"
#include <algorithm>
#include <iostream>

constexpr float frameTime = 1.f / 60.f;
constexpr float bulletFireDelay = 0.25f;

void gameLogic(Player &player1, std::vector<Bullet>& bullets, float& elapsed, const sf::Texture* bulletTexture)
{
	if(leftIsClicked())
		player1.moveLeft();

	if(rightIsClicked())
		player1.moveRight();

	if(upIsClicked())
		player1.moveUp();

	if(downIsClicked())
		player1.moveDown();

	if(spaceIsClicked())
	{
		elapsed += frameTime;

		if (elapsed >= bulletFireDelay)
		{
			bullets.emplace_back(bulletTexture);
			bullets.back().shoot(player1);

			elapsed = 0.f;
		}
	}
	else
	{
		elapsed = 0.24f;
	}

	for (Bullet& bullet : bullets)
		bullet.moveUp();

	auto fun = [](const Bullet& bullet) -> bool { return bullet.getPosY() < -32; };

	bullets.erase(std::remove_if(bullets.begin(), bullets.end(), fun), bullets.end());
}
