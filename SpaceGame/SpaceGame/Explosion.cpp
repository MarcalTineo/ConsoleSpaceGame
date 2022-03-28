#include "Explosion.h"
#include <DrawEngine.h>
#include <Engine.h>

Explosion::Explosion(Vector2 _position)
{
	position = _position;
}

Explosion::~Explosion()
{
}

void Explosion::OnCollision(HitInfo)
{
}

void Explosion::Start()
{
	tag = "EXPLOSION";
	std::vector<Vector2> col = std::vector<Vector2>();
	collider = new Collider(id, col);
	timer = 0;
	frame = 0;
	animationFrameRate = 12.0f;
}

void Explosion::Update(float dt)
{
	timer += dt;
	if (timer > (1 / animationFrameRate))
	{
		frame++;
		timer -= 1 / animationFrameRate;
	}
	if (frame >= 3)
	{
		Engine::GetGame()->GetScene()->Destroy(this);
	}
}

void Explosion::Draw()
{
	for (int i = 0; i < modelSize.y; i++)
	{
		for (int j = 0; j < modelSize.x; j++)
		{
			int posX = position.x + j - modelOffset.x;
			int posY = position.y + i - modelOffset.y;
			char partToDraw = model[frame][i][j];
			if (partToDraw != '0')
				DrawEngine::GetInstance().DrawAtPos(partToDraw, posX, posY, 6);
		}
	}
}
