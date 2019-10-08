#pragma once

#include "Module.h"
#include "Globals.h"


class ModuleRender;
class ModuleTextures;

class ModuleScene : public Module
{
public:

	ModuleScene();
	~ModuleScene() {};

	bool Init();
	update_status PreUpdate();

private:

	ModuleTextures * moduleTexture;
	ModuleRender * moduleRender;
	int x;
	int y;
};