#include "Application.h"
#include "Module.h"

#include "Input.h"
#include "Window.h"
#include "Texture.h"
#include "Render.h"


void Application::Awake()
{
	//push all modules
	modules.push_back(new M_Input(this));
	modules.push_back(new M_Window(this));
	modules.push_back(new M_Textures(this));
	modules.push_back(new M_Render(this));

	int moduleCount = modules.size();

	for (int i = 0; i < moduleCount; ++i)
	{
		modules[i]->Awake();
	}
}


void Application::Start()
{
	int moduleCount = modules.size();

	for (int i = 0; i < moduleCount; ++i)
	{
		modules[i]->Start();
	}
}


void Application::Update()
{
	int moduleCount = modules.size();

	//Preupdate
	for (int i = 0; i < moduleCount; ++i)
	{
		modules[i]->PreUpdate();
	}

	//Update
	for (int i = 0; i < moduleCount; ++i)
	{
		modules[i]->Update();
	}

	//PostUpdate
	for (int i = 0; i < moduleCount; ++i)
	{
		modules[i]->PostUpdate();
	}
}



void Application::CleanUp()
{
	int moduleCount = modules.size();

	for (int i = 0; i < moduleCount; ++i)
	{
		modules[i]->CleanUp();
	}
}


Module* Application::GetModule(MODULE_TYPE type)
{
	return modules[(int)type];
}