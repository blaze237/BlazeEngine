#pragma once
#include <vector>

class Component;
class GameObject
{
public:
	
	GameObject();
	virtual ~GameObject();

	//Game logic relating to this object should be placed here
	virtual void Update(int tick) = 0;

	//Template to get components of type

protected:
	//Container for all components added to the object
	std::vector<Component> components;
};

