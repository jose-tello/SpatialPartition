#include "Window.h"
#include "Application.h"

#include "SDL/include/SDL.h"

Window::Window(Application* app) : Module(app),
	window(nullptr)
{
}


Window::~Window()
{
}


void Window::Start()
{
	SDL_InitSubSystem(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
}


void Window::CleanUp()
{
	SDL_DestroyWindow(window);
	window = nullptr;
}


SDL_Window* Window::GetWindow()
{
	return window;
}