#pragma once
#include <Actor.h>
using namespace ConsoleEngine;

class GameOverMenu :
	public Actor
{
private:

	std::string title[11] = {
		"  _____          __  __ ______  ",
		" / ____|   /\\   |  \\/  |  ____| ",
		"| |  __   /  \\  | \\  / | |__    ",
		"| | |_ | / /\\ \\ | |\\/| |  __|   ",
		"| |__| |/ ____ \\| |  | | |____  ",
		" \\_____/_/    \\_\\_|__|_|______| ",
		" / __ \\\\ \\    / /  ____|  __ \\   ",
		"| |  | |\\ \\  / /| |__  | |__) |  ",
		"| |  | | \\ \\/ / |  __| |  _  /   ",
		"| |__| |  \\  /  | |____| | \\ \\   ",
		" \\____/    \\/   |______|_|  \\_\\  "
	};
		

	int pointerPosition;
	int numberOfEntries; 
	bool allDone;
public:
	GameOverMenu();
	~GameOverMenu();

	// Inherited via Actor
	virtual void OnCollision(HitInfo) override;
	virtual void Start() override;
	virtual void Update(float) override;
	virtual void Draw() override;
	bool GetAllDone();
};

