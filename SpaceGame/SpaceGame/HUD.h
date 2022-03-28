#pragma once
#include <Actor.h>
#include <DrawEngine.h>
#include <Helpers.h>
using namespace ConsoleEngine;

class HUD : public Object, IActor
{
	int score;
	int highScore;
	int sizeX;


public:
	HUD();
	HUD(int size) : sizeX(size) {};
	~HUD();
	// Heredado vía IActor
	virtual void Start() override;
	virtual void Update(float dt) override;
	virtual void Draw() override;

	void DrawHighScore();
	void DrawScore();

	int GetScore();
	int GetHighScore();
	void SetScore(int n);
	void SetHighScore();

	void AddScore(int n);

	

	

};

