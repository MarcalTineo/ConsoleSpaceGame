#pragma once
#include "Object.h"
#include <vector>
#include <string>
#include "Collider.h"
#include "Helpers.h"

namespace ConsoleEngine
{
	class IActor
	{
	public:
		virtual void Update(float) = 0;
		virtual void Draw() = 0;
	};

	class Actor : public Object, IActor, ICollidable
	{
	protected:
		std::string tag;
	public:
		Actor();
		~Actor();

		void SetTag(std::string tag);
		std::string GetTag();
		bool CompareTag(std::string tag);

		// Heredado vía ICollidable
		virtual void OnCollision(HitInfo) override;
		virtual Collider* GetCollider() override;
	};
}


