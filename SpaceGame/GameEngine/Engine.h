#pragma once
#include <iostream>
#include <chrono>
#include "Windows.h"
#include "Input.h"
#include "DrawEngine.h"
#include "Game.h"


class Engine
{
public:
	Game* currentGame;

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

