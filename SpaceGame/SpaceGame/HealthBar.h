#pragma once
#include <Actor.h>
using namespace ConsoleEngine;

class HealthBar : public Actor
{
protected:
	int color;
	int bgColor;
	std::string owner;
	int maxHealthPoints;
	int currentHealthPoints;
	int length;
	int currentLength;

public:
	HealthBar(std::string owner) : owner(owner) { };
	~HealthBar() {};
	// Heredado vía Actor
	virtual void OnCollision(HitInfo) override;
	virtual void Start() override;
	virtual void Update(float) override;
	virtual void Draw() override;
	void SetMaxHealthPoints(int points);
	void SetCurrentHealthPounts(int points);
};

