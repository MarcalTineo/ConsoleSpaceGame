#include "EnemyMotherShip.h"
#include <DrawEngine.h>
#include <Engine.h>

EnemyMotherShip::EnemyMotherShip(Vector2 _position, HUD* _hud)
{
	position = _position;
	hud = _hud;
}

EnemyMotherShip::~EnemyMotherShip()
{
	delete collider;
}

void EnemyMotherShip::Start()
{
	tag = "ENEMY_MOTHERSHIP";
	forward = Vector2::Zero();
	timer = 0;
	color = 5;
	lifepoints = 100;
	collider = new Collider(id, GenerateCollider());
	shootSpeed = 1;
	shootTimer = 0;
	shootSide = false;
	initialYPosition = position.y;
	sinAmplitude = 8;
	sinVelocity = 0.15f;

	std::string healthBarOwner = "MOTHERSHIP";
	healthBar = new HealthBar(healthBarOwner);
	Engine::GetGame()->GetScene()->Create(healthBar);
	healthBar->SetMaxHealthPoints(lifepoints);

	laserTimer = 0;
	laserOffset = Vector2(-8, 2);
	laserTimeBetweenShots = 12.0f;
	laserDuration = 5.0f;

	laser = new Laser(position + laserOffset);
	Engine::GetGame()->GetScene()->Create(laser);
}

std::vector<Vector2> EnemyMotherShip::GenerateCollider()
{
	std::vector<Vector2> col = std::vector<Vector2>();
	/*for (int i = 0; i < modelSize.y; i++)
	{
		for (int j = 0; j < modelSize.x; j++)
		{
			int posX = j - modelOffset.x;
			int posY = i - modelOffset.y;
			if (model[i][j] != '0')
			{
				if (!(i == 1 && model[i][j] == '_') && model[i][j] != ' ')
					col.push_back(Vector2(posX, posY));
			}
		}
	}*/

	//afegir nomes els punts necesaris optimitza el rendiment
	for (int i = 7; i <= 13; i++)
		col.push_back(Vector2(i, 4));
	for (int i = 7; i <= 13; i++)
		col.push_back(Vector2(i, -4));
	col.push_back(Vector2(10, -3));
	col.push_back(Vector2(10, 3));
	for (int i = -4; i <= 10; i++)
		col.push_back(Vector2(i, -2));
	col.push_back(Vector2(-5, -1));
	col.push_back(Vector2(-6, -1));
	col.push_back(Vector2(-7, -1));
	col.push_back(Vector2(-8, -1));
	col.push_back(Vector2(-9, -1));
	col.push_back(Vector2(-7, 1));
	col.push_back(Vector2(-9, 0));
	col.push_back(Vector2(-10, 0));
	col.push_back(Vector2(-7, 0));
	col.push_back(Vector2(-8, 0));
	for (int i = -7; i < 10; i++)
		col.push_back(Vector2(i, 2));
	return col;
}

void EnemyMotherShip::Update(float dt)
{
	UpdatePosition(dt);
	CheckLifePoints();
	ShootUpdate(dt);
	healthBar->SetCurrentHealthPounts(lifepoints);
}

void EnemyMotherShip::ShootUpdate(float dt)
{
	ShootTurretUpdate(dt);
	ShootLaserUpdate(dt);
}

void EnemyMotherShip::ShootTurretUpdate(float dt)
{
	shootTimer += dt;
	if (shootTimer > 1 / shootSpeed)
	{
		shootTimer -= 1 / shootSpeed;
		shootSide = !shootSide;
		if (shootSide)
			Engine::GetGame()->GetScene()->Create(new Bullet(position + Vector2(6, 4), 15, false));
		else
			Engine::GetGame()->GetScene()->Create(new Bullet(position + Vector2(6, -4), 15, false));
	}
}

void EnemyMotherShip::ShootLaserUpdate(float dt)
{
	laserTimer += dt;
	if (laserTimer >= laserTimeBetweenShots)
	{
		laserTimer -= laserTimeBetweenShots;
		laser->Fire();
	}
	if (laserTimer >= laserDuration)
	{
		laser->TurnOff();
	}
}

void EnemyMotherShip::CheckLifePoints()
{
	if (lifepoints <= 0)
	{
		Engine::GetGame()->GetScene()->Destroy(this);
		Engine::GetGame()->GetScene()->Create(new Explosion(position));
		Engine::GetGame()->GetScene()->Destroy(healthBar);
		Engine::GetGame()->GetScene()->Destroy(laser);
		hud->AddScore(100);
	}
}

void EnemyMotherShip::UpdatePosition(float dt)
{
	timer += dt;
	float delta = floor(sin(timer * sinVelocity) * sinAmplitude);
	position.y = initialYPosition + delta;
	laser->position = position + laserOffset;
}

void EnemyMotherShip::Draw()
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
	//Debug collider
	/*for (Vector2 col : collider->GetCollider())
		DrawEngine::GetInstance().DrawAtPos(254, position.x + col.x, position.y + col.y, 10);*/
}

void EnemyMotherShip::OnCollision(HitInfo hit)
{
	if (hit.tag == "BOARD")
		Engine::GetGame()->GetScene()->Destroy(this);
	else if (hit.tag == "PLAYER_BULLET" || hit.tag == "PLAYER")
	{
		lifepoints--;
	}
}