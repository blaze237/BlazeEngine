#include "Scene.h"
#include <stdio.h>
#include <cstdlib>
#include "GameObject.h"

Scene::Scene(BlazeEngine* e)
:engine(e)
{
}


Scene::~Scene()
{
	for (auto& obj : GameObjects)
	{
		if (obj != NULL)
			delete obj;
	}
}


void Scene::UpdateGameObjects(int tick)
{
	for (auto& obj : GameObjects)
	{
		if (obj != NULL)
			obj->UpdateComponents(tick);
	}
}

void Scene::PhysicsUpdate(int tick)
{
	/*for each (PhsyicsHandler phys in PhysicsHandlers)
	phys.update();*/
}

//Tell any objects with renderers attatched to draw themselves to the screen
void Scene::DrawRenderers()
{

}

//Remove an object from the scene by setting pointer to it to NULL and deleting the object
void Scene::DeleteObject(GameObject* obj)
{
	GameObjects[obj->ID] = NULL;

	delete obj;
}

void Scene::ResetTransitionFlags()
{
	for (auto& flag : transitionFlags)
		flag = false;
}


bool Scene::ReadyToTransition()
{
	//If any flag is true, then the scene is ready to transtion to some other scene
	for (auto& flag : transitionFlags)
	{
		if (flag)
			return true;
	}

	return false;
}