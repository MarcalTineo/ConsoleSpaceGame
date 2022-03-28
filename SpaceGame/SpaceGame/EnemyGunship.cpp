#include "EnemyGunship.h"


EnemyGunship::EnemyGunship(Vector2 _position, float _speed)
{
	position = _position;
	speed = _speed;
}

EnemyGunship::~EnemyGunship()
{
}

void EnemyGunship::Start()
{
	tag = "BIG_ENEMY";
	forward = -Vector2::Right();
	timer = 0;
	color = 6;
}

void EnemyGunship::Update(float dt)
{
}

void EnemyGunship::Draw()
{
}

void EnemyGunship::OnCollision(HitInfo hit)
{
}