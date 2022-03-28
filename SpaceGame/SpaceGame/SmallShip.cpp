#include "SmallShip.h"
#include <DrawEngine.h>
#include <Engine.h>

SmallShip::SmallShip(Vector2 _position, float _speed, int _modelType)
{
	position = _position;
	speed = _speed;
	type = _modelType;
}

SmallShip::~SmallShip()
{
	delete collider;
}

void SmallShip::Start()
{
	timer = 0;
	tag = "SMALL_ENEMY";
	collider = new Collider(id, std::vector<Vector2>{Vector2(0, 0), Vector2(1, 0)});
	forward = -Vector2::Right();
	color = 13;
}

void SmallShip::Update(float dt)
{
	timer += dt;
	if (timer > 1 / speed)
	{
		timer -= 1 / speed;
		position += forward;
	}
}

void SmallShip::Draw()
{
	for (int i = 0; i < 2; i++)
		DrawEngine::GetInstance().DrawAtPos(model[type][i], position.x + i, position.y, color);
}

void SmallShip::OnCollision(HitInfo hit)
{
	if (hit.tag == "PLAYER_BULLET")
	{
		Engine::GetGame()->GetScene()->Destroy(this); 
		Engine::GetGame()->GetScene()->Create(new Explosion(position));
	}
	else if (hit.tag == "BOARD")
	{
		Engine::GetGame()->GetScene()->Destroy(this);
	}
}
