#pragma once
#include "BlazeEngine.h"

class GameObject;
class Component
{
public:
	Component(BlazeEngine* e, GameObject* parent, int id);

	virtual ~Component() {};


	//This function is called by the gameobject the component is attatched when the gameobject is set to be active (if it was previously not)
	virtual void OnParentEnabled() {}
	//This function is called by the gameobject the component is attatched when the gameobject is set to be not active (if it previously was)
	virtual void OnParentDisabled() {}
	//This function is called by the gameobject the component is attatched when the gameobject is about to be destroyed and removed from the scene
	virtual void OnParentDestroyed() {}

	/*Deletes the components.
	Parent gameobject is made aware of this deletion and provided refs to this object in other places
	are references to the original pointer stored in the scenes object container, then these
	refs will also automaticly become null*/
	void Destroy();

private:
	BlazeEngine* engine;
	GameObject* const parent;

public:
	//Refernce used to identify this game object in the scene it exists in
	const int ID;
};

