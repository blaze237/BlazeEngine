#include "Scene.h"
#include <stdio.h>
#include <cstdlib>


Scene::Scene(BlazeEngine* e)
:engine(e)
{
}


Scene::~Scene()
{
}

void Scene::UpdateGameObjects(int tick)
{
	/*for each (GameObject obj in GameObjects)
		obj.update();*/
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