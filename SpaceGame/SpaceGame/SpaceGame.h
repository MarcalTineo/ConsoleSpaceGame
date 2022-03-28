#pragma once
#include <Game.h>
#include <vector>
#include <Actor.h>
#include "Board.h"
#include "HUD.h"
#include "PlayerShip.h"
#include "Explosion.h"
#include "SmallShip.h"
#include "EnemyGunship.h"
#include "EnemyMotherShip.h"
#include "Laser.h"

using namespace ConsoleEngine;

class SpaceGame : public Game
{
public:
	enum State
	{
		TITLE_SCREEN,
		LOAD_XML,
		PLAY,
		GAME_OVER
	};
private:
	State state;
	HUD* hud;
public:
	SpaceGame();
	~SpaceGame();

	virtual void Start() override;

	virtual void Update(float dt) override;

	virtual void Draw() override;


};


