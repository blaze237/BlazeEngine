/*
	State manager utilizes strategy pattern to allow for on the fly, transparent changes to game/engine funcionality.
	This is a basic interface, and should be extended to work with whatever custom state objects you are using.
*/
#pragma once
#include "State.h"

class BlazeEngine;

class StateManager
{
public:
	StateManager(BlazeEngine* e)
		:engine(e){}
	
	~StateManager();

	virtual State* GetCurrentState() = 0; //Return a pointer to the current state
	virtual void CheckForStateTransition() = 0; //Check if current state is ready to transition to a new one.

protected:
	BlazeEngine* engine;
};

