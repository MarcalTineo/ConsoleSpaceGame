#pragma once
#include <Vector2.h>
#include <Actor.h>
using namespace ConsoleEngine;

class Wave
{
public:
	Vector2 position;
	std::vector<Actor*> members;
	float delay;
	Wave(Vector2 position, std::vector<Actor*> members, float delay) : position(position), members(members), delay(delay) {};
};

class Spawner : public Actor
{
protected:
	std::vector<Wave> waves;
	float timer;
	int waveIndex;
public:
	Spawner(std::vector<Wave> waves) : waves(waves) {};
	~Spawner();

	// Inherited via Actor
	virtual void OnCollision(HitInfo);

	virtual void Start() override;

	virtual void Update(float) override;

	virtual void Draw() override;

	void SpawnWave(Wave wave);
};

