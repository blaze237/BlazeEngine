#pragma once
#include "Component.h"
#include <stdio.h>

class comp2 :
	public Component
{
public:
	comp2();
	~comp2();

	void Update(){
		printf("COmp 2!\n");
	}
};

