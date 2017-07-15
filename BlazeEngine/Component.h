#pragma once
#include "BlazeEngine.h"
class Component
{
public:
	Component(BlazeEngine* e);
	//The destructor is made pure virtual to prevent instantion of base component objects, as this would make no sense to allow. 
	//By only making the destrucot virtual this allows for custom components to be made without having to worry about provdidng 
	//Implementations for all base class fucntions, when many would likley be blank functions as few components will use all component
	//functionality.
	virtual ~Component() = 0; 

	//Called once every frame
	virtual void Update(int tick) {}

	//This function is called by the gameobject the component is attatched when the gameobject is set to be active (if it was previously not)
	virtual void OnParentEnabled() {}
	//This function is called by the gameobject the component is attatched when the gameobject is set to be not active (if it previously was)
	virtual void OnParentDisabled() {}

private:
	BlazeEngine* engine;
};

