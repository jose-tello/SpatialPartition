#include "Render.h"
#include "Application.h"

#include "Window.h"
#include "Texture.h"

#include "SDL/include/SDL.h"


M_Render::M_Render(Application* app) : Module(app),
	render(nullptr),
	background(nullptr)
{
}


M_Render::~M_Render()
{

}


void M_Render::Awake()
{
	M_Window* mWindow = static_cast<M_Window*>(app->GetModule(MODULE_TYPE::WINDOW));
	
	render = SDL_CreateRenderer(mWindow->GetWindow(), -1, 0);
}


void M_Render::Start()
{
	M_Textures* textures = static_cast<M_Textures*>(app->GetModule(MODULE_TYPE::TEXTURES));
	background = textures->LoadTexture("Images/Background2.jpg");
}



void M_Render::PreUpdate()
{
	SDL_RenderClear(render);
}


void M_Render::PostUpdate()
{
	SDL_SetRenderDrawColor(render, 250, 0, 0, 250);

	SDL_Rect outputRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
	SDL_RenderCopy(render, background, &outputRect, &outputRect);

	SDL_RenderPresent(render);
}


void M_Render::CleanUp()
{
	SDL_DestroyRenderer(render);
	render = nullptr;
}


SDL_Renderer* M_Render::GetRenderer() const
{
	return render;
}
