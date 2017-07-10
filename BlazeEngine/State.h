#pragma once
class BlazeEngine;

class State
{
public:
	State(BlazeEngine* e)
	:engine(e){}

	virtual ~State();

	//Called whenever a state is transitioned to, used for initalialisation
	virtual void InitialiseState() = 0;
	//Called whenever a state is about to be left, used for calling any appropriate utility functions such as pausing AI etc
	virtual void PrepareForTransition() = 0;

	//It is intended that you will make your own custom state interface based on this one, which will have its own set of transition flags and associated functions.
	virtual void ResetTransitionFlags() = 0;
	//Just return boolean combination of all transition flags youre state interface has.
	virtual void ReadyToTransition() = 0;
	
//Drawing Functions
	
	//Undraw GUI
	virtual void UndrawGUI() = 0;
	//Draw Strings behind objects
	virtual void DrawBackgroundText() = 0;
	//Apply Screen Effects. Screen effects are the penultimate step in the rendering pipepline, only GUI rendering is done after.
	virtual void ApplyScreenEffects() = 0;
	//Draw GUI above all other objects. This could be anything you want, strings, primitives images etc.
	virtual void DrawGUI() = 0;

//Input functions

	//Called when a keyboard button pressed
	virtual void OnKeyDown(int keyCode) = 0;
	//Caled when a keyboard button is released
	virtual void OnKeyUp(int keyCode) = 0;
	//Called when mouse button pressed
	virtual void OnMouseDown(int button, int x, int y) = 0;
	//Called when mouse button released
	virtual void OnMouseUp(int button, int x, int y) = 0;
	//Called when mouse position changes
	virtual void OnMouseMove(int x, int y) = 0;

protected:
	BlazeEngine* engine; //Reference to egine used for calling non state specific engine functions

};

