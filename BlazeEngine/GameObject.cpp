#include "GameObject.h"


GameObject::GameObject(BlazeEngine* e, bool active)
:active(active)
{
}


GameObject::~GameObject()
{
	for (Component* c : components)
	{
		delete c;
	}
}
