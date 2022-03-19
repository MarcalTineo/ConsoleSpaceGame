#pragma once
#include <iostream>
#include "windows.h"
#include "Helpers.h"
#include "Vector2.h"

class DrawEngine
{
protected:
	Vector2 size;

	HANDLE hConsole;

	int defaultColor;
	char* viewport;
	char* viewportColors;

public:
	static DrawEngine& GetInstance()
	{
		static DrawEngine instance;
		return instance;
	}
	

	DrawEngine() {};
	~DrawEngine();

	void SetDrawEngine(Vector2 size);
private:
	void ShowConsoleCursor(bool showFlag);
public:
	void DrawAtPos(char c, int x, int y);
	void DrawAtPos(char c, int x, int y, int color);

	void Write(char* text, int lenght, int x, int y);
	void Write(char* text, int lenght, int x, int y, int color);

	void Flush();

	void InitViewport();

	void SetCursorPosition(int x, int y);

	void Clear();

};

