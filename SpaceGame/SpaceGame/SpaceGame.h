#pragma once
#include <Game.h>
#include <vector>
#include <Actor.h>

using namespace std;

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
	vector<Actor> sceneElements;
	State state;
public:
	SpaceGame();
	~SpaceGame();

	virtual void Start() override;
	virtual void Update(float dt) override;
	virtual void Draw() override;

	vector<Actor> GetSceneElemets();
};

