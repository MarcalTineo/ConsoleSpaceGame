#pragma once
#include "Collider.h"

namespace ConsoleEngine
{
	class ICollidable
	{
	protected:
		Collider* collider;
	public:
		virtual void OnCollision(HitInfo) = 0;
		virtual Collider* GetCollider() = 0;
	};
}
