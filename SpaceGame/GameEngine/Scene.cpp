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
		for (int i = 0; i < actors.size(); i++)
			delete actors[i];
		for (int i = 0; i < actorsToAdd.size(); i++)
			delete actorsToAdd[i];
		for (int i = 0; i < actorsToDestroy.size(); i++)
			delete actorsToDestroy[i];
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
		//Destroy actors
		for (Actor* actorToDestroy : actorsToDestroy)
		{
			for (int i = 0; i < actors.size(); i++)
			{
				if (actorToDestroy == actors[i])
				{
					actors.erase(actors.begin() + i);
					delete actorToDestroy;
					break;
				}
			}
		}
		actorsToDestroy.clear();

		//add new actors
		for (Actor* actorToAdd : actorsToAdd)
		{
			actorToAdd->SetActive(true);
			actors.push_back(actorToAdd);
		}
		actorsToAdd.clear();
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

	bool Scene::IsDestroying(Actor* _actor)
	{
		for (Actor* actor : actorsToDestroy)
		{
			if (actor == _actor)
				return true;
		}
		return false;
	}
}
