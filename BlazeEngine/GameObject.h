#pragma once
#include <vector>
#include "Component.h"
#include "BlazeEngine.h"

class Component;
class Scene;
class GameObject
{
public:
	

	GameObject(BlazeEngine* e, int id, bool active = true);
	~GameObject();

	//Call Update loop on all attatched components.
	void UpdateComponents(int tick);
	
	//Use to toggle the GameObject between active and inactive.
	inline void SetActive(bool v);

	/*Deletes the game object and all attatched components.
	Scene is made aware of this deletion and provided refs to this object in other places
	are references to the original pointer stored in the scenes object container, then these
	refs will also automaticly become null*/
	void Destroy();

	void DeleteComponent(Component* comp);


	//Return active flag
	inline bool IsActive(){
		return active;
	}

	//Return all the components stored by this game objects
	inline std::vector<Component*> GetAllComponents(){
		return components;
	}

	//Add a component to the game object
	inline void AddComponent(Component* c){
		components.push_back(c);
	}

	//Return the first instance of component type, T, stored in the component container
	template <class T>
	T* GetComponent()
	{
		//Loop through each component until we find one that is of the type we are looking for
		for (Component* const c : components)
		{
			try
			{
				return dynamic_cast<T*>(c);
			}
			catch (std::bad_cast)
			{
				//Ignore if not what were looking for
			}
			
		}

		return NULL;
	}

	//Return all instances of component type, T, stored in the component container
	template <class T>
	std::vector<T*> GetComponents()
	{
		std::vector<T*> objs;

		//Loop through each component adding any that match the type we are looking for to a vector
		for (Component* const c : components)
		{
			try
			{
				T* tmp = dynamic_cast<T*>(c);
				objs.push_back(tmp);
			}
			catch (std::bad_cast)
			{
				//Ignore if not what were looking for
			}
		}

		return objs;
	}

	

protected:
	//Container for all components added to the object
	std::vector<Component*> components;

	//Active flag
	bool active;

	//Reference to the scene
	Scene* parentScene;

public:
	//Refernce used to identify this game object in the scene it exists in
	const int ID;
};
