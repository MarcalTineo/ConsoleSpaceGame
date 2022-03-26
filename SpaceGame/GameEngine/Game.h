#pragma once
#include "Vector2.h"
#include "Scene.h"
#include "Scene.h"

namespace ConsoleEngine
{
	class IGame
	{
		virtual bool IsAlive() = 0;

		virtual void Start() = 0;

		virtual void Update(float dt) = 0;

		virtual void Draw() = 0;

		virtual void Kill() = 0;
	};

	class Game : public IGame
	{
	protected:
		bool isAlive;
		Vector2 size;
		Scene* scene;
	public:

		Game();
		~Game();

		Vector2 GetSize();

		Scene* GetScene();

		// Heredado vía IGame
		virtual bool IsAlive() override;

		virtual void Start() override;

		virtual void Update(float dt) override;

		virtual void Draw() override;

		virtual void Kill() override;

	};
}
