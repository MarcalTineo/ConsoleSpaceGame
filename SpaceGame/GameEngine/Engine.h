#pragma once
#include <iostream>
#include <chrono>
#include "Windows.h"
#include "Input.h"
#include "DrawEngine.h"
#include "Game.h"
#include "CollisionEngine.h"

namespace ConsoleEngine
{
	class Engine
	{
	protected:
		CollisionEngine* collisionEngine;
		static Game* currentGame;
	public:
		static Game* GetGame()
		{
			return currentGame;
		}
		int FPS;
		float deltaSeconds;

		long long initTime;
		float dt;

		long long nextTime;

		Engine(Game* game, int fps);
		~Engine();
		void RunGame();
		long long GetTime();
	};
}
