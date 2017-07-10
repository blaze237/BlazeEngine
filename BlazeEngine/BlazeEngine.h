#pragma once
#include <SDL.h>

class BlazeEngine
{
public:
	BlazeEngine();
	~BlazeEngine();

	//Initialize SDL and create window
	int Init(const char* title, int screenWidth, int screenHeight);

	//Cleanup before program ends
	void DeInit();

	//Core game loop. Handles input polling and calling of game logic and render functions.
	//Runs untill application is quit
	void MainLoop();

	void Render();


private:
	int screenWidth;
	int screenHeight;
	SDL_Window* window;
	SDL_Surface* screen;

	bool exitGame;
};

