#pragma once
#include "Component.h"
class baseTest :
	public Component
{
public:
	baseTest();
	virtual ~baseTest();

	virtual void Update() = 0;
};

