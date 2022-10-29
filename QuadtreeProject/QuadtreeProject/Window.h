#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "Module.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800

struct SDL_Window;

class M_Window : public Module
{
public:
	M_Window(Application* app);
	~M_Window() override;

	void Awake() override;

	void CleanUp() override;

	SDL_Window* GetWindow();

private:

	SDL_Window* window = nullptr;

};


#endif // !__WINDOW_H__
