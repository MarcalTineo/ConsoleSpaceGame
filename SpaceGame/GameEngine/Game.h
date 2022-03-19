#pragma once
#include "Vector2.h"

class IGame
{
	bool isAlive;

	virtual bool IsAlive() = 0;

	virtual void Start() = 0;

	virtual void Update(float dt) = 0;

	virtual void Draw() = 0;

	virtual void Kill() = 0;
};

class Game : public IGame
{
public:
	static Game& GetInstance()
	{
		static Game instance;
		return instance;
	}
protected:
	bool isAlive;
	Vector2 size;
public:
	
	Game();
	~Game();

	Vector2 GetSize();
	
	// Heredado vía IGame
	virtual bool IsAlive() override;

	virtual void Start() override;

	virtual void Update(float dt) override;

	virtual void Draw() override;

	virtual void Kill() override;

};

