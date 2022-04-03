#include "Spawner.h"
#include <Engine.h>

void Spawner::OnCollision(HitInfo)
{
}

void Spawner::Start()
{
	timer = 0;
	waveIndex = 0;
	tag = "SPAWNER";
}

void Spawner::Update(float dt)
{
	timer += dt;
	if (waves[waveIndex].delay < timer)
	{
		timer = 0;
		SpawnWave(waves[waveIndex]);
		waveIndex++;
		if (waveIndex>=waves.size())
		{
			SetActive(false);
			if (playMode == MainMenu::PlayMode::LOOP)
				waveIndex = 0;
		}
	}
}

void Spawner::Draw()
{
}

void Spawner::SpawnWave(Wave wave)
{
	for (Ship shipData : wave.members)
	{
		Vector2 localPosition = shipData.localPosition;
		float speed = shipData.speed;
		Actor* ship;
		Enemy::Type type = shipData.type;

		switch (type)
		{
			case Enemy::MOTHERSHIP:
				ship = new EnemyMotherShip(localPosition, hud);
				break;
			case Enemy::SMALL1:
				ship = new SmallShip(localPosition + wave.position, speed, 0, hud);
				break;
			case Enemy::SMALL2:
				ship = new SmallShip(localPosition + wave.position, speed, 1, hud);
				break;
			case Enemy::SMALL3:
				ship = new SmallShip(localPosition + wave.position, speed, 2, hud);
				break;
			case Enemy::SMALL4:
				ship = new SmallShip(localPosition, speed, 3, hud);
				break;
			case Enemy::GUNSHIP:
				ship = new EnemyGunship(localPosition + wave.position, speed, hud);
				break;
			case Enemy::LASER:
				ship = new Laser(localPosition);
				break;
			default:
				ship = new SmallShip(Vector2::Zero(), 0, 0, hud);
				break;
		}

		Engine::GetGame()->GetScene()->Create(ship);
	}
}
