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
	scene->Create(new PlayerShip(Vector2(20, 20), 10));
	hud = new HUD(size.x);
	hud->Start();
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
		if (Input::GetInstance().GetKeyDown('S'))
		{
			/*scene->Create(new SmallShip(Vector2(100, 10), 5, 0));
			scene->Create(new SmallShip(Vector2(100, 15), 5, 1));
			scene->Create(new SmallShip(Vector2(100, 20), 5, 2));
			scene->Create(new SmallShip(Vector2(100, 25), 5, 3));*/
			scene->Create(new EnemyMotherShip(Vector2(100, 20), 3));
			//scene->Create(new Laser(Vector2(100, 20)));
		}




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

