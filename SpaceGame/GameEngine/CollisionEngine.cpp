#include "CollisionEngine.h"
#include "Engine.h"

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
		for (int i = 0; i < actors.size(); i++)
		{
			for (int j = i + 1; j < actors.size(); j++)
			{
				if (CheckCollision(actors.at(i), actors.at(j)))
				{
					actors.at(i)->OnCollision(HitInfo(actors.at(j)->GetId(), actors.at(j)->GetTag(), collisionPoint));
					actors.at(j)->OnCollision(HitInfo(actors.at(i)->GetId(), actors.at(i)->GetTag(), collisionPoint));
					actors.at(i)->GetCollider()->SetLastHit(HitInfo(actors.at(j)->GetId(), actors.at(j)->GetTag(), collisionPoint));
					actors.at(j)->GetCollider()->SetLastHit(HitInfo(actors.at(i)->GetId(), actors.at(i)->GetTag(), collisionPoint));
				}
			}
		}
	}
	bool CollisionEngine::CheckCollision(Actor* coll1, Actor* coll2)
	{
		
		if (!coll1->GetCollider()->enabled || !coll2->GetCollider()->enabled)
			return false;


		///----------------------------------------
		//poso aquest codi aqui per no haber de refer tot el sistema de colliders. No es net pero funciona
		//els lasers no poden funcionar amb l'altre tipus de collider perquè al haber de fer tantes comprocacions com caracters el rendiment es veu altament afectat.
		if (coll1->CompareTag("LASER"))
		{
			if (coll2->position.x < coll1->position.x && coll2->position.y >= coll1->position.y - 1 && coll2->position.y <= coll1->position.y + 1)
				return true;
		}
		else if (coll2->CompareTag("LASER"))
		{
			if (coll1->position.x < coll2->position.x && coll1->position.y >= coll2->position.y - 1 && coll1->position.y <= coll2->position.y + 1)
				return true;
		}
		///-----------------------------------------
		else
		{
			std::vector<Vector2> collider1 = coll1->GetCollider()->GetCollider();
			std::vector<Vector2> collider2 = coll2->GetCollider()->GetCollider(); 
			for (int i = 0; i < collider1.size(); i++)
			{
				for (int j = 0; j < collider2.size(); j++)
				{
					if (coll1->position + collider1.at(i) == coll2->position + collider2.at(j))
					{
						collisionPoint = coll1->position + collider1.at(i);
						return true;
					}
				}
			}
		}
		return false;
	}
}