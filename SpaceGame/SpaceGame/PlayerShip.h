#pragma once
#include <Actor.h>

class PlayerShip : Actor
{
	// Heredado v�a Actor
	virtual void Update(float) override;
	virtual void Draw() override;
};

