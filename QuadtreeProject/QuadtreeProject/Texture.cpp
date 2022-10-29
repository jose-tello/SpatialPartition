#include "Texture.h"
#include "Application.h"

#include "Render.h"

#include <cassert>

#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )

#include "SDL/include/SDL.h"

M_Textures::M_Textures(Application* app) : Module(app)
{
}


M_Textures::~M_Textures()
{
}


void M_Textures::Awake()
{
	int init = IMG_Init(IMG_INIT_JPG);

	assert((init != 0) && "Could not init SDL_image, %s", IMG_GetError());
}


void M_Textures::CleanUp()
{
	IMG_Quit();
}


SDL_Texture* M_Textures::LoadTexture(const char* file)
{
	SDL_Surface* surface = IMG_Load(file);
	assert((surface != nullptr) && "Could not load texture: %s, IMG_Load: %s", file, IMG_GetError());

	SDL_Renderer* render = static_cast<M_Render*>(app->GetModule(MODULE_TYPE::RENDER))->GetRenderer();

	SDL_Texture* texture = SDL_CreateTextureFromSurface(render, surface);
	assert((texture != nullptr) && "Unable to create texture from surface! SDL Error: %s\n", SDL_GetError());

	SDL_FreeSurface(surface);

	return texture;
}


void M_Textures::UnloadTexture(SDL_Texture* texture)
{
	SDL_DestroyTexture(texture);
}