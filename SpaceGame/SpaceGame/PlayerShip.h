#pragma once
#include <Actor.h>
#include <DrawEngine.h>
#include <Input.h>
#include "Bullet.h"
#include <array>;

using namespace ConsoleEngine;

class PlayerShip : public Actor
{
protected:
	Vector2 forward;
	float timer;
	float speed;
	const std::array<char, 15> model = { '0', '|', '\\', '0', '0', '[', '=', 'O', '}' , '>', '0', '|', '/', '0', '0' };
	const Vector2 modelSize = Vector2(5, 3);
	const Vector2 modelOffset = Vector2(2, 1);
	int healthPoints;

public:
	PlayerShip();
	PlayerShip(Vector2 _position, float speed);
	std::vector<Vector2> GenerateCollider();
	~PlayerShip();

	virtual void Start() override;

	virtual void Update(float) override;

	void UpdateInput();

	virtual void Draw() override;

	virtual void OnCollision(HitInfo) override;

	int GetHealthPoints();

};

