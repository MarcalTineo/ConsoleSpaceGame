#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
}

PlayerShip::PlayerShip(Vector2 _position, float _speed)
{
	position = _position;
	speed = _speed;
}

PlayerShip::~PlayerShip()
{
	delete collider;
}

void PlayerShip::Start()
{
	tag = "PLAYER";
	forward = Vector2::Zero();
	timer = 0;
	collider = new Collider(id, GenerateCollider());
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
		Engine::GetGame()->GetScene()->Create(new Bullet(position + Vector2::Right()*3, 20, true));
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
}

void PlayerShip::Draw()
{/*
	 |\
	[=O}>
	 |/
*/
	for (int i = 0; i < modelSize.y; i++)
	{
		for (int j = 0; j < modelSize.x; j++)
		{
			int posX = position.x + j - modelOffset.x;
			int posY = position.y + i - modelOffset.y;
			char partToDraw = model[i * modelSize.x + j];
			if(partToDraw != '0')
				DrawEngine::GetInstance().DrawAtPos(partToDraw, posX, posY, 14);
		}
	}
	/*for (Vector2 col : collider->GetCollider())
		DrawEngine::GetInstance().DrawAtPos(254, position.x + col.x, position.y + col.y, 10);*/
}

void PlayerShip::OnCollision(HitInfo hit)
{
	if (hit.tag == "BOARD")
	{
		position -= forward;
	}
}


std::vector<Vector2> PlayerShip::GenerateCollider()
{
	std::vector<Vector2> col = std::vector<Vector2>();
	for (int i = 0; i < modelSize.y; i++)
	{
		for (int j = 0; j < modelSize.x; j++)
		{
			int posX = j - modelOffset.x;
			int posY = i - modelOffset.y;
			if (model[i * modelSize.x + j] != '0')
				col.push_back(Vector2(posX, posY));
		}
	}
	return col;
}


