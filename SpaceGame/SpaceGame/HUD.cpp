#include "HUD.h"

HUD::HUD()
{
	score = 0;
	highScore = 0;
}

HUD::~HUD()
{
}

void HUD::Update(float dt)
{
}

void HUD::Draw()
{
	DrawScore();
	DrawHighScore();
}

void HUD::DrawHighScore()
{
	DrawEngine::GetInstance().Write((char*)"HIGHSCORE: ", 11, 5, 1);
	DrawEngine::GetInstance().Write((char*)Helpers::ScoreToString(highScore), 4, 16, 1);
}

void HUD::DrawScore()
{
	DrawEngine::GetInstance().Write((char*)"SCORE: ", 7, 44, 1);
	DrawEngine::GetInstance().Write((char*)Helpers::ScoreToString(score), 4, 51, 1);
}

int HUD::GetScore()
{
	return score;
}

int HUD::GetHighScore()
{
	return highScore;
}

void HUD::SetScore(int n)
{
	score = n;
}

void HUD::SetHighScore()
{
	highScore = score;
}

void HUD::AddScore(int n)
{
	score += n;
}
