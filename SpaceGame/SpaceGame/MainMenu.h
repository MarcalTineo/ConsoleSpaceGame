#pragma once
#include <Actor.h>
using namespace ConsoleEngine;


class MainMenu :
	public Actor
{
public:
	enum PlayMode
	{
		ONCE, LOOP
	};
	bool allDone;
private:
	
	std::string title[23] = {
		"                                 ___          ___          ___          ___          ___      ",
		"                                /\\  \\        /\\  \\        /\\  \\        /\\  \\        /\\  \\     ",
		"                               /::\\  \\      /::\\  \\      /::\\  \\      /::\\  \\      /::\\  \\    ",
		"                              /:/\\ \\  \\    /:/\\:\\  \\    /:/\\:\\  \\    /:/\\:\\  \\    /:/\\:\\  \\   ",
		"                             _\\:\\~\\ \\  \\  /::\\~\\:\\  \\  /::\\~\\:\\  \\  /:/  \\:\\  \\  /::\\~\\:\\  \\  ",
		"                            /\\ \\:\\ \\ \\__\\/:/\\:\\ \\:\\__\\/:/\\:\\ \\:\\__\\/:/__/ \\:\\__\\/:/\\:\\ \\:\\__\\ ",
		"                            \\:\\ \\:\\ \\/__/\\/__\\:\\/:/  /\\/__\\:\\/:/  /\\:\\  \\  \\/__/\\:\\~\\:\\ \\/__/ ",
		"                             \\:\\ \\:\\__\\       \\::/  /      \\::/  /  \\:\\  \\       \\:\\ \\:\\__\\   ",
		"                              \\:\\/:/  /        \\/__/       /:/  /    \\:\\  \\       \\:\\ \\/__/   ",
		"                               \\::/  /                    /:/  /      \\:\\__\\       \\:\\__\\     ",
		"                                \\/__/                     \\/__/        \\/__/        \\/__/     ",
		"",		             
		"                          ___           ___           ___           ___           ___       ___      ",
		"                         /\\  \\         /\\  \\         /\\  \\         /\\  \\         /\\__\\     /\\  \\     ",
		"                        /::\\  \\       /::\\  \\        \\:\\  \\        \\:\\  \\       /:/  /    /::\\  \\    ",
		"                       /:/\\:\\  \\     /:/\\:\\  \\        \\:\\  \\        \\:\\  \\     /:/  /    /:/\\:\\  \\   ",
		"                      /::\\~\\:\\__\\   /::\\~\\:\\  \\       /::\\  \\       /::\\  \\   /:/  /    /::\\~\\:\\  \\  ",
		"                     /:/\\:\\ \\:|__| /:/\\:\\ \\:\\__\\     /:/\\:\\__\\     /:/\\:\\__\\ /:/__/    /:/\\:\\ \\:\\__\\ ",
		"                     \\:\\~\\:\\/:/  / \\/__\\:\\/:/  /    /:/  \\/__/    /:/  \\/__/ \\:\\  \\    \\:\\~\\:\\ \\/__/ ",
		"                      \\:\\ \\::/  /       \\::/  /    /:/  /        /:/  /       \\:\\  \\    \\:\\ \\:\\__\\   ",
		"                       \\:\\/:/  /        /:/  /    /:/  /        /:/  /         \\:\\  \\    \\:\\ \\/__/   ",
		"                        \\::/__/        /:/  /     \\/__/         \\/__/           \\:\\__\\    \\:\\__\\     ",
		"                         ~~            \\/__/                                     \\/__/     \\/__/     "
	};
	int pointerPosition;
	int numberOfEntries;
	PlayMode selectedPlayMode;
public:
	MainMenu();
	~MainMenu();

	// Inherited via Actor
	virtual void OnCollision(HitInfo) override;
	virtual void Start() override;
	virtual void Update(float) override;
	virtual void Draw() override;
	PlayMode GetPlayMode();
};
