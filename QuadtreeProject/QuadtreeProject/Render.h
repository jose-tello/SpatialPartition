#ifndef __RENDER_H__
#define __RENDER_H__

#include "Module.h"

struct SDL_Renderer;
struct SDL_Texture;

class M_Render : public Module
{
public:
	M_Render(Application* app);
	~M_Render() override;

	void Awake() override;
	void Start() override;

	void PreUpdate() override;
	void PostUpdate() override;

	void CleanUp() override;

	SDL_Renderer* GetRenderer() const;

private:

	SDL_Renderer* render = nullptr;
	SDL_Texture* background = nullptr;
};

#endif // !__M_RENDER_H__
