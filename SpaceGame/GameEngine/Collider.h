#pragma once
#include <vector>
#include <string>
#include "Vector2.h"


struct HitInfo
{
	int info;
	std::string tag;
};

class Collider
{
	int actorId;
	std::vector<Vector2> collider;
public:
	Collider();
	Collider(int _parentId, std::vector<Vector2> _collider, void(*CollisionCallback)(HitInfo));
	~Collider();

	HitInfo hit;
	void (*OnCollisionCallback)(HitInfo);
	//std::vector<void(*)(HitInfo)> CallbackList;//no usar lista en este caso

	void Update()
	{
		//check collision
		//if collision
		{
			//rellenar hit
			OnCollisionCallback(hit);
		}
	}
};

