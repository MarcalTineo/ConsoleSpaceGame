#include "Spawner.h"

void Spawner::OnCollision(HitInfo)
{
}

void Spawner::Start()
{
	timer = 0;
	waveIndex = 0;
}

void Spawner::Update(float dt)
{
	timer += dt;
	if (waves[waveIndex].delay > timer)
	{
		timer = 0;
		SpawnWave(waves[waveIndex]);
		waveIndex++;
	}
}

void Spawner::Draw()
{
}

void Spawner::SpawnWave(Wave wave)
{

}
