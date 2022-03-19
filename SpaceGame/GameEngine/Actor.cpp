#include "Actor.h"



Actor::Actor()
{
	isActive = true;
	position = Vector2::Zero();
}


Actor::~Actor()
{
}

std::vector<Vector2> Actor::GetCollider()
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


