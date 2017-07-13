#pragma once
#include "Component.h"
#include <stdio.h>

class comp2 :
	public Component
{
public:
	comp2(int v);
	~comp2();

	void Update(){
		printf("COmp 2! Myval %d\n", value);
	}

private: int value;
};

