#include "Game.h"

namespace ConsoleEngine
{
	Vector2 Game::GetSize()
	{
		return size;
	}

	Scene* Game::GetScene()
	{
		return scene;
	}

	Game::Game()
	{
		isAlive = true;
		scene = new Scene();
	}

	Game::~Game()
	{
		delete scene;
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
}
