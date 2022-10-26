#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <vector>

class Module;

enum class MODULE_TYPE : int
{
	INPUT = 0,
	WINDOW,
	RENDER,
	MAX
};

struct Application
{
public:
	void Start();

	void Update();

	void CleanUp();

	Module* GetModule(MODULE_TYPE type);

public:
	bool quit = false;;

private:
	std::vector<Module*> modules;
};

#endif // !__APPLICATION_H__
