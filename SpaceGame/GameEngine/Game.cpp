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

void Game::Start()
{
}

void Game::Update(float dt)
{
}

void Game::Draw()
{
}

void Game::Kill()
{
	isAlive = false;
}

