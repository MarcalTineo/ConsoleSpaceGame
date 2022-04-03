#include "GameOverMenu.h"
#include <Engine.h>



GameOverMenu::GameOverMenu()
{
	Start();
}


GameOverMenu::~GameOverMenu()
{
}

void GameOverMenu::OnCollision(HitInfo)
{
}

void GameOverMenu::Start()
{
	pointerPosition = 0;
	numberOfEntries = 2;
	allDone = false;
}

void GameOverMenu::Update(float)
{
	if (Input::GetInstance().GetKeyDown(VK_UP))
	{
		if (pointerPosition > 0)
			pointerPosition--;
	}
	if (Input::GetInstance().GetKeyDown(VK_DOWN))
	{
		if (pointerPosition < numberOfEntries - 1)
			pointerPosition++;
	}
	if (Input::GetInstance().GetKeyDown(VK_RETURN) || Input::GetInstance().GetKeyDown(VK_SPACE))
	{
		if (pointerPosition == 0)
		{
			allDone = true;
		}
		else if (pointerPosition == 1)
		{
			Engine::GetGame()->Kill();
		}
	}
}

void GameOverMenu::Draw()
{
	DrawEngine::GetInstance().InitViewport();
	DrawEngine::GetInstance().Write("Back To Menu", 55, 25, 11);
	DrawEngine::GetInstance().Write("Exit", 55, 27, 11);
	DrawEngine::GetInstance().DrawAtPos(16, 53, 25 + pointerPosition * 2);
	for (int i = 0; i < 11; i++)
	{
		DrawEngine::GetInstance().Write(title[i], 45, i+5);
	}
	DrawEngine::GetInstance().Flush();

}

bool GameOverMenu::GetAllDone()
{
	return allDone;
}
