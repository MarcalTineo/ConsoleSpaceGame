#pragma once
#include "Actor.h"
#include "Collider.h"

namespace ConsoleEngine
{
	class CollisionEngine
	{
	public:
		CollisionEngine();
		~CollisionEngine();

		void Update();

		bool CheckCollision(Actor*, Actor*);
	};

}