#include "Bullet.h"

Bullet::Bullet()
{
	timer = 0;
	speed = 0;
	forward = Vector2::Zero();
}

Bullet::Bullet(Vector2 _position, float _speed, bool isPlayerBullet)
{
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
}

Bullet::~Bullet()
{
	delete collider;
}

void Bullet::OnCollision(HitInfo)
{
	Engine::GetGame()->GetScene()->Destroy(this);
}

void Bullet::Start()
{
	timer = 0;
	GenerateCollider();
}

void Bullet::GenerateCollider()
{
	std::vector<Vector2> col = std::vector<Vector2>();
	col.push_back(Vector2::Zero());
	collider = new Collider(id, col);
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
	DrawEngine::GetInstance().DrawAtPos('-', position.x, position.y, 2);
}
