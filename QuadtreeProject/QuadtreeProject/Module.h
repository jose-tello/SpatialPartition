#ifndef __MODULE_H__
#define __MODULE_H__

struct Application;

class Module
{
public:
	Module(Application* app);
	virtual ~Module();

	virtual void Awake();
	virtual void Start();

	virtual void PreUpdate();
	virtual void Update();
	virtual void PostUpdate();
	
	virtual void CleanUp();

protected:
	Application* app;
};

#endif // !__MODULE_H__
