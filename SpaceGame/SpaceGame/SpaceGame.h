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
#include "XMLLoader.h"
#include "MainMenu.h"
#include "GameOverMenu.h"

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
	XMLLoader* loader;
	std::vector<Wave> waves;
	MainMenu* mainMenu;
	MainMenu::PlayMode playmode;
	PlayerShip* player;
	float timer;
	GameOverMenu* gameOverMenu;
public:
	SpaceGame();
	~SpaceGame();

	virtual void Start() override;

	virtual void Update(float dt) override;

	void LoadWaves();

	virtual void Draw() override;

	HUD* GetHud() { return hud; };



};


