#include "Collider.h"


Collider::Collider()
{
}

Collider::Collider(int _actorId, std::vector<Vector2> _collider, void(*CollisionCallback)(HitInfo))
{
	actorId = _actorId;
	collider = _collider;
	OnCollisionCallback = CollisionCallback;
}

Collider::~Collider()
{
	OnCollisionCallback = nullptr;
}
