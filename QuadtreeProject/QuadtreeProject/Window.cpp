#include "Window.h"
#include "Application.h"

#include "SDL/include/SDL.h"

M_Window::M_Window(Application* app) : Module(app),
	window(nullptr)
{
}


M_Window::~M_Window()
{
}


void M_Window::Awake()
{
	SDL_InitSubSystem(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
}


void M_Window::CleanUp()
{
	SDL_DestroyWindow(window);
	window = nullptr;
}


SDL_Window* M_Window::GetWindow()
{
	return window;
}