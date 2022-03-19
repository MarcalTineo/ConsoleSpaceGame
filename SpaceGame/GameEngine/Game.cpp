#include "Game.h"

Vector2 Game::GetSize()
{
	return size;
}

Game::Game()
{
	isAlive = true;
}

Game::~Game()
{
}

bool Game::IsAlive()
{
	return isAlive;
}

void Game::Kill()
{
	isAlive = false;
}

