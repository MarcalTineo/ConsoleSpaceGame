#include "Bullet.h"

Bullet::Bullet()
{
	timer = 0;
	speed = 0;
	forward = Vector2::Zero();
}

Bullet::Bullet(Vector2 _position, float _speed, bool isPlayerBullet)
{
	timer = 0;
	speed = _speed;
	position = _position;
	if (isPlayerBullet)
	{
		forward = Vector2::Right();
		tag = "PLAYER_BULLET";
	}
	else
	{
		forward = -Vector2::Right();
		tag = "ENEMY_BULLET";
	}
	collider = new Collider();
	std::vector<Vector2> col = std::vector<Vector2>();
	col.push_back(Vector2::Zero());
	collider->SetCollider(col);
	
	
}

Bullet::~Bullet()
{
	delete collider;
}

void Bullet::OnCollision(HitInfo)
{
	std::cout << "collision";
	Engine::GetGame()->GetScene()->Destroy(this);
}

void Bullet::Update(float dt)
{
	timer += dt;
	if (timer > (1.0f / speed))
	{
		timer -= 1.0f / speed;
		position += forward;
	}
}

void Bullet::Draw()
{
	DrawEngine::GetInstance().DrawAtPos('.', position.x, position.y);
	/*for (Vector2 col : collider->GetCollider())
		DrawEngine::GetInstance().DrawAtPos(254, position.x + col.x, position.y + col.y, 10);*/
}
