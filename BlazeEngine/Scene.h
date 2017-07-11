#pragma once
#include <vector>
class BlazeEngine;

class Scene
{
public:
	Scene(BlazeEngine* e);

	virtual ~Scene();

	//Called whenever a Scene is transitioned to, used for initalialisation
	virtual void InitialiseScene() = 0;
	//Called whenever a Scene is about to be left, used for calling any appropriate utility functions such as pausing AI etc
	virtual void PrepareForTransition() = 0;
	//Sets all transition flags to false
	virtual void ResetTransitionFlags();
	//Returns true if any transition flag is true
	virtual bool ReadyToTransition();

//Update functions

	//Overide this to run your own custom game logic as required. This is called before object update functions
	virtual void Update() = 0;
	//This is where game objects are updated
	virtual void UpdateGameObjects(int tick);
	//This is where game objects with physics components should be updated.
	virtual void PhysicsUpdate(int tick);



//Drawing Functions
	
	//Tell any objects with renderers attatched to draw themselves to the screen
	virtual void DrawRenderers();
	//Undraw GUI
	virtual void UndrawGUI() = 0;
	//Undraw background Strings
	virtual void UndrawBackgroundText() = 0;
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
	BlazeEngine* engine; //Reference to egine used for calling non Scene specific engine functions
	std::vector<bool> transitionFlags;

	//std::vector<InputManagers> Inputs;
	//std::vector<GameObjects> Objects;
	//std::vector<PhysicsObjects> PhysicsObjs;
	//std::vector<Renderer> Renderers;


};

