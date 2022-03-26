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
		//collisionEngine = new CollisionEngine();
		RunGame();
	}

	Engine::~Engine()
	{
		delete currentGame;
		//delete collisionEngine;
	}

	void Engine::RunGame()
	{
		DrawEngine::GetInstance().SetDrawEngine(currentGame->GetSize());
		Helpers::InitRandomSeed();
		initTime = GetTime();
		nextTime = GetTime();
		int count = 0;
		while (currentGame->IsAlive())
		{
			double currentTime = GetTime();
			if (currentTime >= nextTime)
			{
				if (Input::GetInstance().GetKey(VK_ESCAPE))
					currentGame->Kill();

				nextTime += (double)deltaSeconds * 1000.0f;
				count++;
				//collisionEngine->Update();
				currentGame->Update(deltaSeconds);
				currentGame->Draw();
#ifdef _DEBUG
				std::cout << "Frames: " << count << std::endl;
				std::cout << "Miliseconds: " << GetTime() - initTime << std::endl;
#endif
				Input::GetInstance().ResetInput();
			}
			Input::GetInstance().UpdateInput();
		}
	}

	long long Engine::GetTime()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	}
}