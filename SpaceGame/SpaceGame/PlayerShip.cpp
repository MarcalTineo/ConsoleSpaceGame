#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
}

PlayerShip::PlayerShip(Vector2 _position, float _speed)
{
	id = Helpers::GenerateId();
	position = _position;
	collider = new Collider();
	tag = "PLAYER";
	forward = Vector2::Zero();
	timer = 0;
	speed = _speed;
	std::vector<Vector2> col = std::vector<Vector2>();
	col.push_back(Vector2::Zero());
	collider->SetCollider(col);

}

PlayerShip::~PlayerShip()
{
	delete collider;
}

void PlayerShip::Update(float dt)
{
	timer += dt;
	UpdateInput();
	if (timer > (1.0f / speed))
	{
		timer -= 1.0f / speed;
		position += forward;
	}
	if (Input::GetInstance().GetKeyDown(VK_SPACE))
	{
		Engine::GetGame()->GetScene()->Create(new Bullet(position + Vector2::Right(), 20, true));
	}

}

void PlayerShip::UpdateInput()
{
	forward = Vector2::Zero();
	if (Input::GetInstance().GetKey(VK_UP))
		forward -= Vector2::Up();
	if (Input::GetInstance().GetKey(VK_DOWN))
		forward += Vector2::Up();
	if (Input::GetInstance().GetKey(VK_LEFT))
		forward -= Vector2::Right();
	if (Input::GetInstance().GetKey(VK_RIGHT))
		forward += Vector2::Right();
	//std::cout << forward.x << " " << forward.y;
}

void PlayerShip::Draw()
{
	DrawEngine::GetInstance().DrawAtPos('>', position.x, position.y);
}

void PlayerShip::OnCollision(HitInfo)
{
}

