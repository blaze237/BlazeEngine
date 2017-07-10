#include <stdio.h>
#include "BlazeEngine.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	//Engine return value
	int code = 0;

	BlazeEngine engine;
	code = engine.Init("BlazeEngine Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	engine.MainLoop();
	engine.DeInit();

	return code;

}