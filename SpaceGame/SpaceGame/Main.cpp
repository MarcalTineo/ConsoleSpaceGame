#include <Engine.h>
#include <fstream>
#include "SpaceGame.h"


//delegates
//struct HitInfo
//{
//	int info;
//};
//
//
//class Collider
//{
//	HitInfo hit;
//	void (*OnCollisionCallback)(HitInfo);
//	std::vector<void(*)(HitInfo)> CallbackList;//no usar lista en este caso
//
//	void Update()
//	{
//		//check collision
//		//if collision
//		{
//			//rellenar hit
//			OnCollisionCallback(hit)
//		}
//	}
//
//};

int main()
{
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
	bool testCharacters = true;
	if (testCharacters)
	{
		for (int i = 0; i < 255; i++)
		{
			std::cout << i << ":  " << (char)i << std::endl;
		}
	}
	else
	{
		std::cout << "slfdjhseogs";
		Game* gameToPlay = new SpaceGame();
		Engine* engine = new ConsoleEngine::Engine(gameToPlay, 30);
		delete engine;
	}
	
	
}
