#include "Scene.h"

namespace ConsoleEngine
{
	Scene::Scene()
	{
		actors = std::vector<Actor*>();
		actorsToAdd = std::vector<Actor*>();
		actorsToDestroy = std::vector<Actor*>();
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

	void Scene::Update()
	{
		for (Actor* actorToDestroy : actorsToDestroy)
		{
			for (Actor* actor : actors)
			{
				if (actorToDestroy == actor)
					//erasea
			}
		}
	}

	std::vector<Actor*> Scene::GetAll()
	{
		return actors;
	}

	std::vector<Actor*> Scene::GetAll(std::string tag)
	{
		std::vector<Actor*> actorsToReturn = std::vector<Actor*>();
		for (Actor* actor : actors)
		{
			if (actor->CompareTag(tag))
				actorsToReturn.push_back(actor);
		}
		return actorsToReturn;
	}

	Actor* Scene::GetFirst(std::string tag)
	{
		for (Actor* actor : actors)
		{
			if (actor->CompareTag(tag))
				return actor;
		}
		return nullptr;
	}

	Actor* Scene::GetActor(int id)
	{
		for (Actor* actor : actors)
		{
			if (actor->GetId() == id)
				return actor;
		}
	}
}
