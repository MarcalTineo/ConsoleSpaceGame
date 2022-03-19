#pragma once
#include "Vector2.h"
class Object
{
protected:
	int id;
	bool isActive;
public:
	Vector2 position;
	
	Object();
	~Object();
	bool IsActive();
	void SetActive(bool active);
	int GetId();
};

