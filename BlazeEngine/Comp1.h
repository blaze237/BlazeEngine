#pragma once
#include "Component.h"
#include "baseTest.h"
#include <stdio.h>
class Comp1 :
	public baseTest
{
public:
	Comp1(int val);
	virtual ~Comp1();

	void Update()
	{
		printf("This is comp1 %d\n",value);
	}

	virtual void update()
	{
		printf("This is comp1 via base ref %d\n", value);
	}

private:
	int value;
};

