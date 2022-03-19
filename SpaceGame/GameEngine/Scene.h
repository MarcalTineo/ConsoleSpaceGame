#pragma once
#include <vector>
#include "Actor.h"


class Scene
{
	std::vector<Actor*> actors;
	std::vector<Actor*> actorsToAdd;
	std::vector<Actor*> actorsToDestroy;

public:
	Scene();
	~Scene();

	//public T Create<T>() where T : Actor, new()
	//{
	//  T actor = new T();
	//  actorsToAdd.Add(actor);
	//  return actor;
	//}

	void Create(Actor* actor);
	void Destroy(Actor* actor);

	std::vector<Actor*> GetAll();
	std::vector<Actor*> GetAll(type_info type);
	std::vector<Actor*> GetAll(std::string tag);

	Actor* GetFirst(type_info type);
	Actor* GetFirst(std::string tag);



};

