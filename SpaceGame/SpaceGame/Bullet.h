#pragma once
#include <Actor.h>
using namespace ConsoleEngine;

class Bullet : public Actor
{
protected:

public:
	Bullet();
	~Bullet();

	// Heredado vía Actor
	virtual void OnCollision(HitInfo) override;
	virtual void Update(float) override;
	virtual void Draw() override;
};

