#include <stdlib.h>
#include <iostream>

#include "SDL/include/SDL.h"

#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

#include "Application.h"

int main(int argc, char* argv[])
{
	bool quit = false;
	
	Application app;

	app.Awake();
	app.Start();

	while (app.quit == false)
	{
		app.Update();
	}

	app.CleanUp();

	SDL_Quit();

	return 0;
}