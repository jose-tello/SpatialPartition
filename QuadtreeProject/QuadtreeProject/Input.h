#ifndef __INPUT_H__
#define __INPUT_H__

#include "Module.h"

#define MAX_KEYS 300

enum class KEY_STATE : int
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

class M_Input : public Module
{
public:
	M_Input(Application* app);
	~M_Input() override;

	void Awake() override;

	void PreUpdate() override;

	virtual void CleanUp();

private:

	KEY_STATE keyboard[MAX_KEYS];

};


#endif // !__INPUT_H__
