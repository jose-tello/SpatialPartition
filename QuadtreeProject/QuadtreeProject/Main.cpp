#include <stdlib.h>
#include <iostream>

#include "SDL/include/SDL.h"

#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )

#define MAX_KEYS 300

enum class KEY_STATE : int
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};


int main(int argc, char* argv[])
{
	SDL_Init(0);

	SDL_InitSubSystem(SDL_INIT_EVENTS);

	SDL_InitSubSystem(SDL_INIT_VIDEO);

	SDL_Window* window = nullptr;

	window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_RESIZABLE );


	SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);


	KEY_STATE keyboard[MAX_KEYS];
	memset(keyboard, 0, MAX_KEYS * sizeof(int));

	bool quit = false;
	

	while (quit == false)
	{
		const Uint8* keys = SDL_GetKeyboardState(NULL);

		for (int i = 0; i < MAX_KEYS; ++i)
		{
			if (keys[i] == 1)
			{
				if (keyboard[i] == KEY_STATE::KEY_IDLE)
					keyboard[i] = KEY_STATE::KEY_DOWN;

				else if (keyboard[i] == KEY_STATE::KEY_DOWN)
					keyboard[i] = KEY_STATE::KEY_REPEAT;
			}
			else
			{
				if (keyboard[i] == KEY_STATE::KEY_REPEAT)
					keyboard[i] = KEY_STATE::KEY_UP;

				else
					keyboard[i] = KEY_STATE::KEY_IDLE;
			}
		}


		static SDL_Event event;

		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;

			case SDL_MOUSEBUTTONDOWN:
				break;

			case SDL_MOUSEBUTTONUP:
				break;
			}
		}


		if (keyboard[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
		{
			quit = true;
		}

		SDL_RenderClear(render);

		SDL_SetRenderDrawColor(render, 250, 0, 0, 250);

		SDL_Rect outputRect = { 0, 0, 800, 800 };
		SDL_RenderDrawRect(render, &outputRect);

		SDL_RenderPresent(render);
	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}