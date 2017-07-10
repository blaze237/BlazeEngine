#include "BlazeEngine.h"
#include <stdio.h>
#include <cstdlib>


BlazeEngine::BlazeEngine()
{
}


BlazeEngine::~BlazeEngine()
{
}

int BlazeEngine::initialize(const char* title, int scrnWidth, int scrnHeight)
{
	//Initialise screen size variables
	screenWidth = scrnWidth;
	screenHeight = scrnHeight;

	//Init SDL subsystems
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Could not initialise SDL. Error code: %s\n", SDL_GetError());
		return 1;
	}

	// Register SDL_Quit to be called at exit
	atexit(SDL_Quit);

	//Create the Window
	window = SDL_CreateWindow("BlazeEngineDemo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		printf("Error creating window! Error code: %s\n", SDL_GetError());
		return 1;
	}

	//Get surface
	screen = SDL_GetWindowSurface(window);

	//Initialise the surface
	SDL_FillRect(screen, NULL, 0xffff00);// SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

	//Update the surface
	SDL_UpdateWindowSurface(window);

	//Initialize gameLogic
	gameInit();


	//Wait two seconds
	SDL_Delay(2000);
	//Destroy window
	SDL_DestroyWindow(window);
	//Quit SDL subsystems
	SDL_Quit();
	
	return 0;
}

void BlazeEngine::gameInit(){};