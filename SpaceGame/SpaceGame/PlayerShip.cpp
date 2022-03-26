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

