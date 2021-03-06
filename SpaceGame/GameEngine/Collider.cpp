#include "Collider.h"

namespace ConsoleEngine
{
	Collider::Collider()
	{
	}

	Collider::Collider(int _actorId, std::vector<Vector2> _collider)
	{
		actorId = _actorId;
		collider = _collider;
		enabled = true;
	}

	Collider::~Collider()
	{
	}

	std::vector<Vector2> Collider::GetCollider()
	{
		return collider;
	}

	void Collider::SetCollider(std::vector<Vector2> _collider)
	{
		collider = _collider;
	}

	int Collider::GetId()
	{
		return actorId;
	}
	void Collider::SetLastHit(HitInfo _lastHit)
	{
		lastHit = _lastHit;
	}
	HitInfo Collider::GetLastHit()
	{
		return lastHit;
	}
}

