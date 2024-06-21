#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Player.h"
#include "Bullet.h"

#include <vector>

void gameLogic(Player &player1, std::vector<Bullet> &bullets, float& elapsed, const sf::Texture* bulletTexture);

#endif

