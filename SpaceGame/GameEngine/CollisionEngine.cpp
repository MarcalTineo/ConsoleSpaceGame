#include "CollisionEngine.h"


namespace ConsoleEngine
{
	CollisionEngine::CollisionEngine()
	{
	}


	CollisionEngine::~CollisionEngine()
	{
	}

	void CollisionEngine::Update()
	{
		std::vector<Actor*> actors = Engine::GetGame()->GetScene()->GetAll();
		for (int i = 0; i < actors.size() - 1; i++)
		{
			Actor* current = actors[i];
			for (int j = i + 1; j < actors.size(); j++)
			{
				Actor* compare = actors[j];
				if (current->GetId() == compare->GetId())
					continue;
				if (CheckCollision(current->GetCollider(), compare->GetCollider()))
				{
					current->OnCollision(HitInfo(compare->GetId(), compare->GetTag()));
					
				}
			}
		}
	}
	bool CollisionEngine::CheckCollision(Collider* coll1, Collider* coll2)
	{
		std::vector<Vector2> collider1 = coll1->GetCollider();
		std::vector<Vector2> collider2 = coll2->GetCollider();
		for (int i = 0; i < collider1.size(); i++)
		{
			for (int j = 0; j < collider1.size(); j++)
			{
				if (collider1[i] == collider2[j])
					return true;
			}
		}
		return false;
	}
}