#include "Input.h"

Input::Input()
{
	enabled = true;
	keysPressed = new bool[256];
	lastKeysPressed = new bool[256];
	for (int i = 0; i < 256; i++)
		keysPressed[i] = false;
}

Input::~Input()
{
	delete keysPressed;
	delete lastKeysPressed;
}

void Input::Enable()
{
	enabled = true;
}

void Input::Disable()
{
	enabled = false;
}

bool Input::GetKey(int key)
{
	return enabled ? keysPressed[key] : false;
}

bool Input::GetKeyDown(int key)
{
	return enabled ? keysPressed[key] && !lastKeysPressed[key] : false;
}

bool Input::GetKeyUp(int key)
{
	return enabled ? !keysPressed[key] && lastKeysPressed[key] : false;
}

void Input::UpdateInput()//call always
{
	for (int i = 0; i < 256; i++)
	{
		if (GetKeyState(i) & 0x8000)
			keysPressed[i] = true;
	}
}

void Input::ResetInput()//call after every update/frame
{
	for (int i = 0; i < 256; i++)
		lastKeysPressed[i] = keysPressed[i];
	for (int i = 0; i < 256; i++)
		keysPressed[i] = false;
}

bool Input::AnyKey()
{
	if (!enabled)
		return false;
	for (int i = 0; i < 256; i++)
	{
		if (keysPressed[i])
			return true;
	}
	return false;
}