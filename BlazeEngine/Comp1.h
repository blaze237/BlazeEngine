#pragma once
#include "Component.h"
#include <stdio.h>
class Comp1 :
	public Component
{
public:
	Comp1(int val);
	virtual ~Comp1();

	void Update()
	{
		printf("This is comp1 %d\n",value);
	}

private:
	int value;
};

