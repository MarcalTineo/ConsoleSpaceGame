#pragma once
#include "tinyxml2.h"
#include <vector>
#include "Spawner.h"

using namespace tinyxml2;

class XMLLoader
{
public:
	tinyxml2::XMLDocument doc;
	XMLLoader() {};
	int LoadFile(const char* file, std::vector<Wave>& wavesVector);
	Wave CreateWave(XMLElement* waveElement);
	Ship CreateShip(XMLElement* shipElement);

};

