#include "HealthBar.h"
#include <DrawEngine.h>
#include <Engine.h>


void HealthBar::OnCollision(HitInfo)
{
}

void HealthBar::Start()
{
	collider = new Collider(id, std::vector<Vector2>());
	tag = "HEALTH_BAR";
	length = 75;
	position = Vector2(Engine::GetGame()->GetSize().x / 2, 5);
	color = 4;
	bgColor = 8;
	currentHealthPoints = 75;
}

void HealthBar::Update(float)
{
	currentLength = ceil((float)(length * currentHealthPoints) / (float)maxHealthPoints);
}

void HealthBar::Draw()
{
	for (int i = 0; i < length; i++)
	{
		int partColor = i > currentLength ? bgColor : color;
		DrawEngine::GetInstance().DrawAtPos(205, position.x + i - length / 2, position.y, partColor);
	}
	DrawEngine::GetInstance().Write(const_cast<char*>(owner.c_str()), owner.size(), position.x - owner.size() / 2, position.y - 1, color);
}

void HealthBar::SetMaxHealthPoints(int points)
{
	maxHealthPoints = points;
}

void HealthBar::SetCurrentHealthPounts(int points)
{
	currentHealthPoints = points;
}
