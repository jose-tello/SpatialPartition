#include "Render.h"
#include "Application.h"

#include "Window.h"

#include "SDL/include/SDL.h"


Render::Render(Application* app) : Module(app),
	render(nullptr)
{
}


Render::~Render()
{

}


void Render::Start()
{
	Window* mWindow = static_cast<Window*>(app->GetModule(MODULE_TYPE::WINDOW));
	
	render = SDL_CreateRenderer(mWindow->GetWindow(), -1, 0);
}


void Render::PreUpdate()
{
	SDL_RenderClear(render);
}


void Render::PostUpdate()
{
	SDL_SetRenderDrawColor(render, 250, 0, 0, 250);

	SDL_Rect outputRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
	SDL_RenderDrawRect(render, &outputRect);

	SDL_RenderPresent(render);
}


void Render::CleanUp()
{
	SDL_DestroyRenderer(render);
	render = nullptr;
}