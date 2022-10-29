#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "Module.h"

struct SDL_Texture;
struct SDL_Surface;

class M_Textures : public Module
{
public:
	M_Textures(Application* app);
	~M_Textures() override;

	void Awake() override;
	void CleanUp() override;

	SDL_Texture* LoadTexture(const char* file);
	void UnloadTexture(SDL_Texture* texture);
};

#endif // !__TEXTURE_H__
