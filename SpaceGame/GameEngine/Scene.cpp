#include "Scene.h"

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
