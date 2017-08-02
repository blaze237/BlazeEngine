#pragma once
#include "Component.h"
class PhysicsComponent :
	public Component
{
public:
	PhysicsComponent(BlazeEngine* e, GameObject* parent, int id);
	virtual ~PhysicsComponent();

	//Call rate is invarient under frame ret. Set within BlazeEngine.
	//Should be used for all physics logic.
	virtual void FixedUpdate(int time) = 0;
};

