#pragma once
#include "Actor.h"
#include "Collider.h"
#include "Engine.h"

namespace ConsoleEngine
{
	class CollisionEngine
	{
	public:
		CollisionEngine();
		~CollisionEngine();

		void Update();

		bool CheckCollision(Collider*, Collider*);
	};

}