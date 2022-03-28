#pragma once
#include "Actor.h"
#include "Collider.h"

namespace ConsoleEngine
{
	class CollisionEngine
	{

		Vector2 collisionPoint;
	public:
		CollisionEngine();
		~CollisionEngine();

		void Update();

		bool CheckCollision(Actor*, Actor*);
	};

}