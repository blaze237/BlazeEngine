#pragma once
#include <vector>
#include "Component.h"
#include "BlazeEngine.h"

class Component;
class GameObject
{
public:
	
	GameObject(BlazeEngine* e, bool active = true);
	~GameObject();

	//Call Update loop on all attatched components.
	void UpdateComponents(int tick)
	{
		if (active)
		{
			for (auto& c : components)
			{
				c->Update(tick);
			}
		}
	}

	inline void SetActive(bool v)
	{
		//If the game object is being made active then inform all components
		if (v && !active)
		{
			for (auto& c : components)
				c->OnParentEnabled();
		}
		//Else inform all components the gameobject is being made inactive.
		else if (!v && active)
		{
			for (auto& c : components)
				c->OnParentDisabled();
		}
		

		active = v;
	}

	inline bool IsActive(){
		return active;
	}

	

	template <class T>
	T* GetComponent()
	{
		for (Component* const c : components)
		{
			if (dynamic_cast<T*>(c) != 0)
				return static_cast<T*>(c);
		}

		return NULL;
	}

	template <class T>
	std::vector<T*> GetComponents()
	{
		std::vector<T*> objs;

		for (Component* const c : components)
		{
			if (dynamic_cast<T*>(c) != 0)
				objs.push_back(static_cast<T*>(c));	
		}

		return objs;
	}

	inline std::vector<Component*> GetAllComponents(){
		return components;
	}

	inline void AddComponent(Component* c){
		components.push_back(c);
	}

protected:
	//Container for all components added to the object
	std::vector<Component*> components;

	bool active;
};
