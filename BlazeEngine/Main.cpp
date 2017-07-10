#include <stdio.h>
#include "BlazeEngine.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	int code = 0;

	BlazeEngine engine;

	code = engine.initialize("BlazeEngine Demo", SCREEN_WIDTH, SCREEN_HEIGHT);

	return code;

	////Setup SDL window
	//SDL_Window* window = NULL;
	//SDL_Surface* screen = NULL;

	////SDL init
	//if (SDL_Init(SDL_INIT_VIDEO) < 0)
	//	printf("Could not initialise SDL. Error code: %s\n", SDL_GetError());
	//else
	//{
	//	//Make Window
	//	window = SDL_CreateWindow("BlazeEngineDemo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	//	if (window == NULL)
	//		printf("Error creating window! Error code: %s\n", SDL_GetError());
	//	else
	//	{
	//		//Get surface
	//		screen = SDL_GetWindowSurface(window);

	//		//Initialise the surface
	//		SDL_FillRect(screen, NULL, 0xffff00);// SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

	//		//Update the surface
	//		SDL_UpdateWindowSurface(window);

	//		//Wait two seconds
	//		SDL_Delay(2000);
	//	}
	//}

	////Destroy window
	//SDL_DestroyWindow(window);

	////Quit SDL subsystems
	//SDL_Quit();

	//return 0;
}