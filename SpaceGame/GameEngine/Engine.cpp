#include "Engine.h"

namespace ConsoleEngine
{
	Game* Engine::currentGame = nullptr;

	Engine::Engine(Game* game, int fps)
	{
		currentGame = game;
		FPS = fps;
		deltaSeconds = 1.0 / FPS;
		dt = 0;
		collisionEngine = new CollisionEngine();
		RunGame();
	}

	Engine::~Engine()
	{
		delete currentGame;
		delete collisionEngine;
	}

	void Engine::RunGame()
	{
		DrawEngine::GetInstance().SetDrawEngine(currentGame->GetSize());
		Helpers::InitRandomSeed();
		initTime = GetTime();
		nextTime = GetTime();
		lastFrameTime = 0;
		while (currentGame->IsAlive())
		{
			long long currentTime = GetTime();
			if (currentTime >= nextTime)
			{
				if (Input::GetInstance().GetKey(VK_ESCAPE))
					currentGame->Kill();
#ifdef _DEBUG
				DrawEngine::GetInstance().SetCursorPosition(0, currentGame->GetSize().y);
				std::cout << "Frame Time: " << currentTime - lastFrameTime << "ms" << "                    " << std::endl;
				std::cout << "Scene Actors: " << currentGame->GetScene()->GetAll().size() << "                   " << std::endl;
#endif
				nextTime = currentTime + (double)deltaSeconds * 1000.0f;
				float deltaTime = (currentTime - lastFrameTime) * 1000.0f;
				currentGame->Update(deltaSeconds);
				collisionEngine->Update();
				currentGame->Draw();
				Input::GetInstance().ResetInput();
				lastFrameTime = currentTime;
			}
			Input::GetInstance().UpdateInput();
		}
	}
	long long Engine::GetTime()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	}
}