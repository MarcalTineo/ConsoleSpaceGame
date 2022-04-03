#include "MainMenu.h"
#include <Engine.h>


MainMenu::MainMenu()
{
	
}

MainMenu::~MainMenu()
{
}

void MainMenu::OnCollision(HitInfo)
{
}

void MainMenu::Start()
{
	numberOfEntries = 3;
	pointerPosition = 0;
	allDone = false;
}

void MainMenu::Update(float)
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
			selectedPlayMode = PlayMode::ONCE;
			allDone = true;
		}
		else if (pointerPosition == 1)
		{
			selectedPlayMode = PlayMode::LOOP;
			allDone = true;
		}
		else
		{
			Engine::GetGame()->Kill();
			allDone = true;
		}
	}
}

void MainMenu::Draw()
{
	DrawEngine::GetInstance().InitViewport();
	DrawEngine::GetInstance().Write("Play Once", 55, 25, 11);
	DrawEngine::GetInstance().Write("Play Loop",55, 27, 11);
	DrawEngine::GetInstance().Write("Exit", 55, 29, 11);
	DrawEngine::GetInstance().DrawAtPos(16, 53, 25 + pointerPosition * 2);
	for (int i = 0; i < 23; i++)
	{
		DrawEngine::GetInstance().Write(title[i], 0, i);
	}
	DrawEngine::GetInstance().Flush();
	DrawEngine::GetInstance().SetCursorPosition(0, 0);
	
}

MainMenu::PlayMode MainMenu::GetPlayMode()
{
	return selectedPlayMode;
}
