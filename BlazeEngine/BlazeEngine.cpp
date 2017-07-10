#include "BlazeEngine.h"
#include <stdio.h>
#include <cstdlib>


BlazeEngine::BlazeEngine()
:exitGame(false)
{
}


BlazeEngine::~BlazeEngine()
{
}

int BlazeEngine::Init(const char* title, int scrnWidth, int scrnHeight)
{
	//Initialise screen size variables
	screenWidth = scrnWidth;
	screenHeight = scrnHeight;

	//Initialize SDL subsystems
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

	//Initialize current gameState
	//GameInit();

	//Initialise the surface
	SDL_FillRect(screen, NULL, 0xffff00);

	//Update the surface
	SDL_UpdateWindowSurface(window);

	return 0;
}


void BlazeEngine::DeInit()
{
	//Destroy window
	SDL_DestroyWindow(window);
	//Quit SDL subsystems
	SDL_Quit();
}

void BlazeEngine::MainLoop()
{
	SDL_Event event;

	while (!exitGame)
	{
		//Handle event polling
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				exitGame = true;


			//Call statemanagers keydown
		}

		//Check for state transition

		//Handle game logic in state manager

		//Handle Physics

		//Handle rendering

	}
}