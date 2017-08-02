#include "Component.h"
#include "GameObject.h"

Component::Component(BlazeEngine* e, GameObject* parent, int id)
:engine(e), ID(id), parent(parent)
{
}


void Component::Destroy()
{
//	parent->DeleteComponent(this);
}