#pragma once

#include "Module.h"

class ModuleRender;
class ModuleTextures;

class ModuleScene : public Module
{
public:

	ModuleScene();
	~ModuleScene() {};

	bool Init();
	update_status Update();

private:
	ModuleTextures * moduleTexture;
	ModuleRender * moduleRender;
};