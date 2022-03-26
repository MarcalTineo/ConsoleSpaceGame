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
		for (Actor* actor : scene->GetAll())
		{
			if (actor->IsActive())
				actor->Update(dt);
		}
	}

	void Game::Draw()
	{
		for (Actor* actor : scene->GetAll())
		{
			if (actor->IsActive())
				actor->Draw();
		}
	}

	void Game::Kill()
	{
		isAlive = false;
	}
}
