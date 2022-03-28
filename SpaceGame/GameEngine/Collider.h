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
		Vector2 position;
		HitInfo(int id, std::string tag, Vector2 position) : id(id), tag(tag), position(position) {};
		HitInfo() : id(0), tag(""), position(Vector2::Zero()) {};
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
		void SetCollider(std::vector<Vector2> _collider);
		int GetId();
		void SetLastHit(HitInfo);
		HitInfo GetLastHit();
	};
}

