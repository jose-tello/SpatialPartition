#include "Input.h"
#include "Application.h"

#include "SDL/include/SDL.h"


M_Input::M_Input(Application* app) : Module(app)
{
	memset(keyboard, 0, MAX_KEYS * sizeof(int));
}


M_Input::~M_Input()
{

}

void M_Input::Awake()
{
	SDL_Init(0);
	SDL_InitSubSystem(SDL_INIT_EVENTS);
}


void M_Input::PreUpdate()
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
			app->quit = true;
			break;

		case SDL_MOUSEBUTTONDOWN:
			break;

		case SDL_MOUSEBUTTONUP:
			break;
		}
	}



	if (keyboard[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
	{
		app->quit = true;
	}
}


void M_Input::CleanUp()
{
	app = nullptr;
	memset(keyboard, 0, MAX_KEYS * sizeof(int));
}