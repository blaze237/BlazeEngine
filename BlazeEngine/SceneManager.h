/*
	Scene manager utilizes strategy pattern to allow for on the fly, transparent changes to game/engine funcionality.
	This is a basic interface, and should be extended to work with whatever custom state objects you are using.
*/
#pragma once
#include "Scene.h"

class BlazeEngine;

class SceneManager
{
public:
	SceneManager(BlazeEngine* e)
		:engine(e){}
	
	~SceneManager();

	virtual Scene* GetCurrentScene() = 0; //Return a pointer to the current Scene
	virtual void CheckForStateTransition() = 0; //Check if current state is ready to transition to a new one.

protected:
	BlazeEngine* engine;
};

