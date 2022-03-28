#pragma once
#include <Actor.h>
#include <Engine.h>
#include "Explosion.h"
using namespace ConsoleEngine;

class Bullet : public Actor
{
protected:
	float timer;
	float speed;
	Vector2 forward;
	int color;

public:
	Bullet();
	Bullet(Vector2 _position, float _speed, bool isPlayerBullet);
	~Bullet();

	// Heredado vía Actor
	virtual void OnCollision(HitInfo) override;
	virtual void Start() override;
	void GenerateCollider();
	virtual void Update(float) override;
	virtual void Draw() override;
};

