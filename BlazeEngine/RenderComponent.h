#pragma once
#include "Component.h"
class RenderComponent :
	public Component
{
public:
	RenderComponent(BlazeEngine* e, GameObject* parent, int id);
	virtual ~RenderComponent();

	//Called once every frame update. 
	//Object drawing functions should be placed here
	virtual void Render() = 0;
};

