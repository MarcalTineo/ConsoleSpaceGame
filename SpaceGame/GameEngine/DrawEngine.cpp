#include "DrawEngine.h"

namespace ConsoleEngine
{
	DrawEngine::~DrawEngine()
	{
		delete viewport;
		delete viewportColors;
	}

	void DrawEngine::SetDrawEngine(Vector2 _size)
	{
		size = Vector2(_size.x + 1, _size.y);
		viewport = new char[(size.x * size.y) + 1];
		viewportColors = new char[((size.x + 1) * size.y) + 1];
		for (int i = 0; i < size.x * size.y; i++)
			viewportColors[i] = defaultColor;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		RECT r;
		HWND console = GetConsoleWindow();
		GetWindowRect(console, &r);
		MoveWindow(console, r.left, r.top, 1140, 800, TRUE);

		ShowConsoleCursor(false);

	}

	//credit: Capitain Oblivious - stack overflow
	void DrawEngine::ShowConsoleCursor(bool showFlag)
	{
		CONSOLE_CURSOR_INFO     cursorInfo;

		GetConsoleCursorInfo(hConsole, &cursorInfo);
		cursorInfo.bVisible = showFlag; // set the cursor visibility
		SetConsoleCursorInfo(hConsole, &cursorInfo);
	}

	void DrawEngine::DrawAtPos(char c, int x, int y)
	{
		viewport[size.x * y + x] = c;
	}

	void DrawEngine::DrawAtPos(char c, int x, int y, int color)
	{
		viewportColors[size.x * y + x] = color;
		viewport[size.x * y + x] = c;
	}

	void DrawEngine::Write(char* text, int lenght, int x, int y)
	{
		for (int i = 0; i < lenght; i++)
			DrawAtPos(text[i], x + i, y);
	}

	void DrawEngine::Write(char* text, int lenght, int x, int y, int color)
	{
		for (int i = 0; i < lenght; i++)
			DrawAtPos(text[i], x + i, y, color);
	}

	void DrawEngine::Flush()
	{
		COORD coord = { (SHORT)0, (SHORT)0 };
		SetConsoleCursorPosition(hConsole, coord);
		std::string out = "";
		int lastColor = 15;
		SetConsoleTextAttribute(hConsole, lastColor);
		for (int i = 0; i < size.x * size.y; i++)
		{
			if (viewportColors[i] != lastColor)
			{
				std::cout << out;
				out = "";
				SetConsoleTextAttribute(hConsole, viewportColors[i]);
				lastColor = viewportColors[i];
			}
			out += viewport[i];
		}
		std::cout << out;

	}

	void DrawEngine::InitViewport()
	{
		for (size_t i = 0; i < size.x * size.y; i++)
		{
			if (i % size.x == size.x - 1)
				viewport[i] = '\n';
		}
		viewport[size.x * size.y] = '\0';
		for (int i = 0; i < size.x * size.y; i++)
			viewportColors[i] = 15;
	}

	void DrawEngine::SetCursorPosition(int x, int y)
	{
		COORD coord = { (SHORT)x, (SHORT)y };
		SetConsoleCursorPosition(hConsole, coord);
	}

	void DrawEngine::Clear()
	{
		system("cls");
	}

}

