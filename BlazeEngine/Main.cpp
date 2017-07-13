#include <stdio.h>
#include "BlazeEngine.h"
#include "Comp1.h"
#include "comp2.h"
#include "ComponentMap.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	//Engine return value
	int code = 0;

	BlazeEngine engine;
	code = engine.Init("BlazeEngine Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	
	

	//TypeMap<std::string> tmap;

	/*tmap.put<int>(std::string("integers!"));
	tmap.put<double>(std::string("doubles!"));
	std::cout << (tmap.find<double>()->second) << "\n";*/

	ComponentMap<Component*> tmap;
	//TypeMap<std::unique_ptr<Component>> tmap;

	Comp1 com1(10);
	Comp1 com12(20);
	comp2 com2(2);

	tmap.AddComponent<Comp1*>(&com1);
	tmap.AddComponent<comp2*>(&com2);

	//std::cout << "Size before repeat added" << tmap.Size() << std::endl;
	//std::cout << "number of comp1 "<< tmap.Count<Comp1*>() << std::endl;

	tmap.AddComponent<Component*>(&com12);

	/*std::cout << "Size after repeat added" << tmap.Size() << std::endl;
	std::cout << "number of comp1 " << tmap.Count<Comp1*>() << std::endl;

	std::cout << "number of comp2 " << tmap.Count<comp2*>() << std::endl;*/

	std::vector<Comp1*> compOnes = tmap.GetComponents<Comp1*>();

	//If any flag is true, then the scene is ready to transtion to some other scene
	for (auto& c : compOnes)
	{
		c->Update();
	}

	Comp1* p = tmap.GetComponent<Comp1*>();
	comp2* p2 = tmap.GetComponent<comp2*>();

	////Up to you to check there actualy is component returned!
	//if (p2 != NULL)
	//	p2->Update();
	//if (p != NULL)
	//p->Update();



	//comp2 com2;

	//tmap.put<Comp1>(std::make_unique<Comp1>());


	//tmap.put<Component>(std::forward<std::unique_ptr<Component>>(com1));
	//tmap.put<double>("doubles!");

	//ComponentMap comMap;

	//Comp1 com1;
	//comp2 com2;

	//printf("before add: \n");
	//com1.Update();
	//comMap.put<Comp1>(&com1);
	//printf("after add: \n");
	////Comp1 p = *comMap.GetComponent<Comp1*>();

//	p.Update();

	engine.MainLoop();
	engine.DeInit();

	return code;
}