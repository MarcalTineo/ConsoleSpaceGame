#pragma once
#include <vector>
#include <string>
#include "Vector2.h"


struct HitInfo
{
	int id;
	std::string tag;
};

class ICollidable
{
protected:
	Collider* collider;
public:
	virtual void OnCollision(HitInfo) = 0;
	virtual Collider* GetCollider() = 0;
};

class Collider
{
	int actorId;
	std::vector<Vector2> collider;
	HitInfo hit;

public:
	Collider();
	Collider(int _parentId, std::vector<Vector2> _collider, void(*CollisionCallback)(HitInfo));
	~Collider();

	//CollisionCallback OnCollisionCallback;
	void (Actor::*OnCollisionCallback)(HitInfo);
	//std::vector<void(*)(HitInfo)> CallbackList;//no usar lista en este caso

	void Collide(HitInfo);

	std::vector<Vector2> GetCollider();
	int GetId();
};

