#pragma once
#include <ctime>
#include <cstdlib>

namespace ConsoleEngine
{
	static class Helpers
	{
	public:
		static void InitRandomSeed();

		static int GetRandomNumber(int min, int max);

		static char* ScoreToString(int n);

		static int GenerateId();
	};
}
