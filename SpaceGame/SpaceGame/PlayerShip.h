#pragma once
#include <Actor.h>
#include <DrawEngine.h>
#include <Input.h>
#include "Bullet.h"

using namespace ConsoleEngine;

class PlayerShip : public Actor
{
protected:
	Vector2 forward;
	float timer;
	float speed;
public:
	PlayerShip();
	PlayerShip(Vector2 _position, float speed);
	~PlayerShip();

	// Heredado vía Actor
	virtual void Update(float) override;

	void UpdateInput();

	virtual void Draw() override;

	virtual void OnCollision(HitInfo) override;
};

