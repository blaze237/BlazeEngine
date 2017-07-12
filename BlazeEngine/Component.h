#pragma once
class Component
{
public:
	Component();
	virtual ~Component();

	virtual void update(int tick){};
};

