#include "SpaceGame.h"

SpaceGame::SpaceGame()
{
	size = Vector2(120, 35);
	state = State::PLAY;
	scene = new Scene();
	Start();
}

SpaceGame::~SpaceGame()
{
	delete scene;
}

void SpaceGame::Start()
{
	scene->Create(new Board(size));
	scene->Create(new PlayerShip(Vector2(20, 20), 5));
	hud = new HUD(size.x);
}

void SpaceGame::Update(float dt)
{
	switch (state)
	{
	case SpaceGame::TITLE_SCREEN:
		break;
	case SpaceGame::LOAD_XML:
		break;
	case SpaceGame::PLAY:
		scene->Update();
		this->Game::Update(dt);
		break;
	case SpaceGame::GAME_OVER:
		break;
	default:
		break;
	}
	
}

void SpaceGame::Draw()
{
	switch (state)
	{
	case SpaceGame::TITLE_SCREEN:
		break;
	case SpaceGame::LOAD_XML:
		break;
	case SpaceGame::PLAY:
		DrawEngine::GetInstance().InitViewport();
		this->Game::Draw();
		hud->Draw();
		DrawEngine::GetInstance().Flush();
		break;
	case SpaceGame::GAME_OVER:
		break;
	default:
		break;
	}
	
}

