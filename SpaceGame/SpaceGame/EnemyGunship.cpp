#include "EnemyGunship.h"
#include <DrawEngine.h>
#include <Engine.h>

EnemyGunship::EnemyGunship(Vector2 _position, float _speed, HUD* _hud)
{
	position = _position;
	speed = _speed;
	hud = _hud;
}

EnemyGunship::~EnemyGunship()
{
	delete collider;
}

void EnemyGunship::Start()
{
	tag = "ENEMY_GUNSHIP";
	forward = -Vector2::Right();
	timer = 0;
	color = 5;
	reactorOn = true;
	lifepoints = 5;
	collider = new Collider(id, GenerateCollider());
	shootSpeed = 0.2f;
	shootTimer = 0;
	shootSide = false;
}

std::vector<Vector2> EnemyGunship::GenerateCollider()
{
	std::vector<Vector2> col = std::vector<Vector2>();
	for (int i = 0; i < modelSize.y; i++)
	{
		for (int j = 0; j < modelSize.x; j++)
		{
			int posX = j - modelOffset.x;
			int posY = i - modelOffset.y;
			if (model[i][j] != '0')
				col.push_back(Vector2(posX, posY));
		}
	}
	return col;
}

void EnemyGunship::Update(float dt)
{
	UpdatePosition(dt);
	reactorOn = !reactorOn;
	CheckLifePoints();
	Shoot(dt);
}

void EnemyGunship::Shoot(float dt)
{
	shootTimer += dt;
	if (shootTimer > 1 / shootSpeed)
	{
		shootTimer -= 1 / shootSpeed;
		shootSide = !shootSide;
		if (shootSide)
			Engine::GetGame()->GetScene()->Create(new Bullet(position + Vector2(-3, 1), 15, false));
		else
			Engine::GetGame()->GetScene()->Create(new Bullet(position + Vector2(-3, -1), 15, false));
	}
}

void EnemyGunship::CheckLifePoints()
{
	if (lifepoints == 0)
	{
		Engine::GetGame()->GetScene()->Destroy(this);
		Engine::GetGame()->GetScene()->Create(new Explosion(position));
		hud->AddScore(20);
	}
}

void EnemyGunship::UpdatePosition(float dt)
{
	timer += dt;
	if (timer > 1 / speed)
	{
		timer -= 1 / speed;
		position += forward;
	}
}

void EnemyGunship::Draw()
{
	for (int i = 0; i < modelSize.y; i++)
	{
		for (int j = 0; j < modelSize.x; j++)
		{
			int posX = position.x + j - modelOffset.x;
			int posY = position.y + i - modelOffset.y;
			if (model[i][j] != '0')
				DrawEngine::GetInstance().DrawAtPos(model[i][j], posX, posY, color);
		}
	}
	if(reactorOn)				
		DrawEngine::GetInstance().DrawAtPos('>', position.x + 3, position.y, 11);

}

void EnemyGunship::OnCollision(HitInfo hit)
{
	if (hit.tag == "BOARD")
		Engine::GetGame()->GetScene()->Destroy(this);
	else if (hit.tag == "PLAYER_BULLET" || hit.tag == "PLAYER")
	{
		lifepoints--;
	}
}