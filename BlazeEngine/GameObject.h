#pragma once
#include <vector>

class Component;
class GameObject
{
public:
	
	GameObject();
	virtual ~GameObject();

	//Game logic relating to this object should be placed here
	virtual void UpdateComponents(int tick) = 0;

	//Template to get components of type
	//template <typename T>
	//std::ve

protected:
	//Container for all components added to the object
	std::vector<Component*> components;
};

//Get component just return the first one
//Get components return all