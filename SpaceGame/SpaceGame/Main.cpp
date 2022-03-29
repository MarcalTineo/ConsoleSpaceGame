#include <Engine.h>
#include <fstream>
#include "SpaceGame.h"
#include "XMLLoader.h"

int main()
{
	XMLLoader* loader = new XMLLoader();
	loader->LoadFile();

	bool testCharacters = false;
	if (testCharacters)
	{
		for (int i = 0; i < 255; i++)
		{
			std::cout << i << ":  " << (char)i << std::endl;
		}
	}
	else
	{
		std::cout << "Start Engine";
		Game* gameToPlay = new SpaceGame();
		Engine* engine = new ConsoleEngine::Engine(gameToPlay, 30);
		delete engine;
	}
	/*
	std::ofstream myOutputFile("rafa.txt");
	
	//std::fstream myInputOuputFile;

	myOutputFile.open("rafa.txt");
	if (myOutputFile.is_open)
	{
		//sofihaeoifap
	}

	myOutputFile.close();


	std::ifstream myInputFile("rafa.txt");
	if (myInputFile.is_open)
	{
		std::string linea;
		while (std::getline(myInputFile, linea))
		{
			std::cout << linea << std::endl;
		}
	}*/
	
	
	
}
