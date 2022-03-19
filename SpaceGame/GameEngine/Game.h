#pragma once
#include "Vector2.h"

class Game
{
protected:
	bool isAlive;
	Vector2 size;
public:
	Vector2 GetSize();
	int GetDefultColor();
	Game();
	~Game();
	bool IsAlive();
	virtual void Start() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
	void Kill();
};

