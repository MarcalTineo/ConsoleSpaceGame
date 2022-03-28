#pragma once
#include "Object.h"
#include <vector>
#include <string>
#include "Collider.h"
#include "Helpers.h"
#include "ICollidable.h"

namespace ConsoleEngine
{
	class IActor
	{
	public:
		virtual void Start() = 0;
		virtual void Update(float) = 0;
		virtual void Draw() = 0;
	};

	class Actor : public Object, public ICollidable, public IActor
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
		virtual void OnCollision(HitInfo) = 0;
		virtual Collider* GetCollider() override;

		// Inherited via IActor
		virtual void Start() = 0;
		virtual void Update(float) = 0;
		virtual void Draw() = 0;
	};
}


