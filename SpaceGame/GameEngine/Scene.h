#pragma once
#include <vector>
#include "Actor.h"

namespace ConsoleEngine
{
	class Scene
	{
		std::vector<Actor*> actors;
		std::vector<Actor*> actorsToAdd;
		std::vector<Actor*> actorsToDestroy;

	public:
		Scene();
		~Scene();

		void Create(Actor* actor);
		void Destroy(Actor* actor);

		std::vector<Actor*> GetAll();
		std::vector<Actor*> GetAll(type_info type);
		std::vector<Actor*> GetAll(std::string tag);

		Actor* GetFirst(type_info type);
		Actor* GetFirst(std::string tag);



	};
}
