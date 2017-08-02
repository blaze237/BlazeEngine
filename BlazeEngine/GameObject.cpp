#include "GameObject.h"
#include "Scene.h"

GameObject::GameObject(BlazeEngine* e, int id, bool active)
:active(active), ID(id)
{
}


GameObject::~GameObject()
{
	//Delete all components that have not allready been deleted at some point during the game
	for (auto c : components)
	{
		if (c != NULL)
			delete c;
	}
}

void GameObject::UpdateComponents(int tick)
{
	//Instead need to store refs to pointers of components tht are logic components and only update those


	/*if (active)
	{
		for (auto& c : components)
		{
			if (c != NULL)
				c->Update(tick);
		}
	}*/
}

void GameObject::SetActive(bool v)
{
	//If the game object is being made active then inform all components
	if (v && !active)
	{
		for (auto& c : components)
			if (c != NULL)
				c->OnParentEnabled();
	}
	//Else inform all components the gameobject is being made inactive.
	else if (!v && active)
	{
		for (auto& c : components)
			if (c != NULL)
				c->OnParentDisabled();
	}

	active = v;
}

void GameObject::Destroy()
{
	parentScene->DeleteObject(this);

	for (auto& c : components)
		if (c != NULL)
			c->OnParentDestroyed();
}

void GameObject::DeleteComponent(Component* comp)
{
	//components[comp->ID] = NULL;

	delete comp;
}