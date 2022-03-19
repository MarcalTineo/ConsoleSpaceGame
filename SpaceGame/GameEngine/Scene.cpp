#include "Scene.h"

namespace ConsoleEngine
{
	Scene::Scene()
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Create(Actor* actor)
	{
		actorsToAdd.push_back(actor);
	}

	void Scene::Destroy(Actor* actor)
	{
		actorsToDestroy.push_back(actor);
	}
}
