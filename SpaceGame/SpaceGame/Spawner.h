#pragma once
#include <Vector2.h>
#include <Actor.h>

#include "EnemyGunship.h"
#include "EnemyMotherShip.h"
#include "SmallShip.h"
#include "MainMenu.h"
#include "HUD.h"
using namespace ConsoleEngine;

class Ship
{
public:
	Vector2 localPosition;
	float speed;
	Enemy::Type type;
	Ship(Vector2 localPosition, float speed, Enemy::Type type) :localPosition(localPosition), speed(speed), type(type) {};
};

class Wave
{
public:
	Vector2 position;
	std::vector<Ship> members;
	float delay;
	Wave(Vector2 position, std::vector<Ship> members, float delay) : position(position), members(members), delay(delay) {};
};

class Spawner : public Actor
{
protected:
	std::vector<Wave> waves;
	float timer;
	int waveIndex;
	MainMenu::PlayMode playMode;
	HUD* hud;
public:
	Spawner(std::vector<Wave> waves, MainMenu::PlayMode playMode, HUD* hud) : waves(waves), playMode(playMode), hud(hud) {};
	~Spawner();

	// Inherited via Actor
	virtual void OnCollision(HitInfo);

	virtual void Start() override;

	virtual void Update(float dt) override;

	virtual void Draw() override;

	void SpawnWave(Wave wave);
};

