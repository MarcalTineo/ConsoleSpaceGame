#include "Helpers.h"

void Helpers::InitRandomSeed()
{
	std::srand(time(0));
}

int Helpers::GetRandomNumber(int min, int max)
{
	return std::rand() % (max - min + 1) + min;
}

char* Helpers::ScoreToString(int n)
{
	int units = n % 10;
	int tens = ((n - units) / 10) % 10;
	int hundreds = ((n - units - (tens * 10)) / 100) % 10;
	int thousands = ((n - units - (tens * 10) - (hundreds * 100)) / 1000) % 10;
	return new char[5]{ (char)thousands + 48, (char)hundreds + 48, (char)tens + 48, (char)units + 48, '\0' };
}

int Helpers::GenerateId()
{
	return std::rand()%(4294967000)-2147483000;
}
