#pragma once
#include "windows.h"

class Input
{
	bool enabled;
	//singleton
public:
	static Input& GetInstance()
	{
		static Input instance;
		return instance;
	}

private:
	bool* keysPressed;
	bool* lastKeysPressed;
public:
	Input();

	~Input();

	void Enable();

	void Disable();

	bool GetKey(int key);

	bool GetKeyDown(int key);

	bool GetKeyUp(int key);

	void UpdateInput();

	void ResetInput();

	bool AnyKey();

};

