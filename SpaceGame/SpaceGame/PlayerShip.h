#pragma once
#include <Actor.h>

class PlayerShip : Actor
{
	// Heredado vía Actor
	virtual void Update(float) override;
	virtual void Draw() override;
};

