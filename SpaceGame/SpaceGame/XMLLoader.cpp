#include "XMLLoader.h"

int XMLLoader::LoadFile()
{
	doc.LoadFile("waves.xml");
	XMLElement* titleElement = doc.FirstChildElement("PLAY")->FirstChildElement("WAVE");
	const char* title = titleElement->GetText();
	std::cout << title;
	return doc.ErrorID();
}
