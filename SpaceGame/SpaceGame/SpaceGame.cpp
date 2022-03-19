#include "SpaceGame.h"



SpaceGame::SpaceGame()
{
}


SpaceGame::~SpaceGame()
{
}

void SpaceGame::Start()
{
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
		for (size_t i = 0; i < sceneElements.size; i++)
		{
			if (sceneElements[i].IsActive())
				sceneElements[i].Update(dt);
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
		for (size_t i = 0; i < sceneElements.size; i++)
		{
			if (sceneElements[i].IsActive())
				sceneElements[i].Draw();
		}
		break;
	case SpaceGame::GAME_OVER:
		break;
	default:
		break;
	}
	
}

vector<Actor> SpaceGame::GetSceneElemets()
{
	return sceneElements;
}
