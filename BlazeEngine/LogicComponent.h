#pragma once
#include "Component.h"
class LogicComponent :
	public Component
{
public:
	LogicComponent(BlazeEngine* e, GameObject* parent, int id);
	virtual ~LogicComponent();

	//Called once every frame
	virtual void Update(int tick) = 0;
};

