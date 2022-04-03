#include "HUD.h"
#include <Engine.h>

HUD::HUD()
{

}

HUD::~HUD()
{
}

void HUD::Start()
{
	id = Helpers::GenerateId();
	score = 0;
	highScore = 0;
	SetActive(true);
}



void HUD::Update(float dt)
{
}

void HUD::Draw()
{
	if (isActive)
	{
		DrawScore();
		DrawHighScore();
		DrawHealtPoints();
	}
}

void HUD::DrawHighScore()
{
	DrawEngine::GetInstance().Write((char*)"HIGHSCORE: ", 11, 10, 1);
	DrawEngine::GetInstance().Write((char*)Helpers::ScoreToString(highScore), 4, 21, 1);
}

void HUD::DrawScore()
{
	DrawEngine::GetInstance().Write((char*)"SCORE: ", 7, sizeX - 20, 1);
	DrawEngine::GetInstance().Write((char*)Helpers::ScoreToString(score), 4, sizeX - 13, 1);
}

void HUD::DrawHealtPoints()
{
	int healthPoints = player->GetHealthPoints();
	if (healthPoints <= 0)
		DrawEngine::GetInstance().Write("GAME OVER", sizeX / 2 - 5, 1, 15);
	else
	{
		for (int i = 0; i < healthPoints; i++)
			DrawEngine::GetInstance().DrawAtPos(3, sizeX / 2 - 5 + i * 2, 1, 4);
	}
	
}
