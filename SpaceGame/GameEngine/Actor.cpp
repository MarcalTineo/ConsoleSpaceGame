#include "Actor.h"

namespace ConsoleEngine
{
	Actor::Actor()
	{
		
		isActive = true;
		collider = new Collider();
		collider->OnCollisionCallback = OnCollision;
	}

	Actor::~Actor()
	{
		delete collider;
	}

	Collider* Actor::GetCollider()
	{
		return collider;
	}

	void Actor::SetTag(std::string _tag)
	{
		tag = _tag;
	}

	std::string Actor::GetTag()
	{
		return tag;
	}

	bool Actor::CompareTag(std::string _tag)
	{
		return tag == _tag;
	}

	void Actor::OnCollision(HitInfo)
	{
	}

}


