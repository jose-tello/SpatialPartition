#ifndef __RENDER_H__
#define __RENDER_H__

#include "Module.h"

struct SDL_Renderer;

class Render : public Module
{
public:
	Render(Application* app);
	~Render() override;

	void Start() override;

	void PreUpdate() override;
	void PostUpdate() override;

	void CleanUp() override;

private:

	SDL_Renderer* render = nullptr;
};

#endif // !__M_RENDER_H__
