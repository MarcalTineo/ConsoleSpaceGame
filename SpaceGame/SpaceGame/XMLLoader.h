#pragma once
#if defined( _MSC_VER )
	#if !defined( _CRT_SECURE_NO_WARNINGS )
		#define _CRT_SECURE_NO_WARNINGS		// This test file is not intended to be secure.
	#endif
#endif

#include "tinyxml2.h"
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

#if defined( _MSC_VER ) || defined (WIN32)
	#include <crtdbg.h>
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	/*_CrtMemState startMemState;
	_CrtMemState endMemState;*/
#else
	#include <sys/stat.h>
	#include <sys/types.h>
#endif

using namespace tinyxml2;
using namespace std;

class XMLLoader
{
public:
	tinyxml2::XMLDocument doc;
	XMLLoader() {};
	int LoadFile();

};

