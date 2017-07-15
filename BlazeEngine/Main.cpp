#include <stdio.h>
#include "BlazeEngine.h"
#include "Component.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "GameObject.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{

	//Engine return value
	int code = 0;

	BlazeEngine engine;
	code = engine.Init("BlazeEngine Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	
	GameObject* obj = new GameObject (&engine);

	delete obj;


///	std::vector<Component*> comps = obj.GetComponents<Component>();



	/*if (p!= NULL)
		p->Update();*/

	engine.MainLoop();
	engine.DeInit();

	return code;
}