#pragma once
#include <Actor.h>
#include <DrawEngine.h>
#include <Helpers.h>
#include "PlayerShip.h"
using namespace ConsoleEngine;

class HUD : public Object, IActor
{
	int score;
	int highScore;
	int sizeX;
	PlayerShip* player;

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
	void DrawHealtPoints();

	int GetScore() { return score; };
	int GetHighScore() { return highScore; };
	void SetScore(int n) { score = n; };
	void SetHighScore() { highScore = score; };
	void SetPlayer(PlayerShip* _player) { player = _player; };

	void AddScore(int n) { score += n; };

	

	

};

