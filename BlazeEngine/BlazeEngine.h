#pragma once
#include <SDL.h>

class BlazeEngine
{
public:
	BlazeEngine();
	virtual ~BlazeEngine();

	int initialize(const char* title, int screenWidth, int screenHeight);
	void deInitialize();

	void gameInit();

private:
	int screenWidth;
	int screenHeight;
	SDL_Window* window;
	SDL_Surface* screen;
};

