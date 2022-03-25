#pragma once
#include <vector>
#include <string>
#include "Vector2.h"

namespace ConsoleEngine
{
	struct HitInfo
	{
		int id;
		std::string tag;
		HitInfo(int id, std::string tag) : id(id), tag(tag) {};
		HitInfo() : id(0), tag("") {};
	};

	class Collider
	{
	protected:
		int actorId;
		std::vector<Vector2> collider;
		HitInfo lastHit;

	public:
		Collider();
		Collider(int _parentId, std::vector<Vector2> _collider);
		~Collider();

		std::vector<Vector2> GetCollider();
		int GetId();
		void SetLastHit(HitInfo);
		HitInfo GetLastHit();
	};
}

