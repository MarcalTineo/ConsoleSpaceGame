#include "XMLLoader.h"

int XMLLoader::LoadFile(const char* file, std::vector<Wave>& waves)
{
	doc.LoadFile(file);
	XMLElement* wavesElement = doc.FirstChildElement();

	int numberOfWaves = 0;
	wavesElement->FirstChildElement()->QueryIntAttribute("v", &numberOfWaves);
	XMLElement* currentWaveElement = wavesElement->FirstChildElement("wave");
	for (int i = 0; i < numberOfWaves; i++)
	{
		waves.push_back(CreateWave(currentWaveElement));
		if (i < numberOfWaves - 1)
			currentWaveElement = currentWaveElement->NextSiblingElement();
	}
	return doc.ErrorID();
}

Wave XMLLoader::CreateWave(XMLElement* waveElement)
{
	int numberOfShips;
	float delay;
	waveElement->QueryIntAttribute("ships", &numberOfShips);
	waveElement->QueryFloatAttribute("delay", &delay);
	int x, y;
	waveElement->FirstChildElement()->QueryIntAttribute("x", &x);
	waveElement->FirstChildElement()->QueryIntAttribute("y", &y);
	Vector2 wavePosition = Vector2(x, y);
	XMLElement* currentShipElement = waveElement->FirstChildElement("ship");
	std::vector<Ship> ships = std::vector<Ship>();
	for (int i = 0; i < numberOfShips; i++)
	{
		ships.push_back(CreateShip(currentShipElement));
		if (i < numberOfShips - 1)
			currentShipElement = currentShipElement->NextSiblingElement();
	}
	return Wave(wavePosition, ships, delay);
}

Ship XMLLoader::CreateShip(XMLElement* shipElement)
{
	int type;
	shipElement->FirstChildElement()->NextSiblingElement()->QueryIntAttribute("v", &type);
	int x, y;
	shipElement->FirstChildElement("position")->QueryIntAttribute("x", &x);
	shipElement->FirstChildElement("position")->QueryIntAttribute("y", &y);
	Vector2 localPosition = Vector2(x, y);
	float speed;
	shipElement->FirstChildElement("speed")->QueryFloatAttribute("v", &speed);
	return Ship(localPosition, speed, (Enemy::Type)type);
}
