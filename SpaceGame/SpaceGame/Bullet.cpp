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
		color = 2;
	}
	else
	{
		forward = -Vector2::Right();
		tag = "ENEMY_BULLET";
		color = 12;
	}
}

Bullet::~Bullet()
{
	delete collider;
}

void Bullet::OnCollision(HitInfo hit)
{
	if (hit.tag == "BOARD")
		Engine::GetGame()->GetScene()->Destroy(this);
	else if (hit.tag != "PLAYER_BULLET" && hit.tag != "ENEMY_BULLET")
	{
		if (!(hit.tag == "PLAYER" && tag == "PLAYER_BULLET"))
		{
			Engine::GetGame()->GetScene()->Destroy(this);
			Engine::GetGame()->GetScene()->Create(new Explosion(hit.position));
		}
	}
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
	DrawEngine::GetInstance().DrawAtPos('-', position.x, position.y, color);
}
