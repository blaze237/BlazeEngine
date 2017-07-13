#include <stdio.h>
#include "BlazeEngine.h"
#include "Comp1.h"
#include "comp2.h"
#include "TypeMap.h"
#include <iostream>
#include <memory>
#include <string>


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

	TypeMap<Component*> tmap;
	//TypeMap<std::unique_ptr<Component>> tmap;

	printf("before add: \n");
	Comp1 com1(10);
	Comp1 com12(20);

	comp2 com2;
	com1.Update();

	//tmap.put<std::unique_ptr<Comp1>>(std::make_unique<Comp1>(com12));
	//Comp1* p = dynamic_cast<Comp1*>(tmap.find<std::unique_ptr<Comp1>>()->second.get());

	
	tmap.put<Comp1*>(&com1);
	tmap.put<comp2*>(&com2);

	std::cout << "Size before repeat added" << tmap.size() << std::endl;

	tmap.put<Comp1*>(&com12);

	std::cout << "Size after repeat added" << tmap.size() << std::endl;


	Comp1* p = dynamic_cast<Comp1*>(tmap.find<Comp1*>()->second);
	comp2* p2 = dynamic_cast<comp2*>(tmap.find<comp2*>()->second);
	
	p2->Update();
	p->Update();



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