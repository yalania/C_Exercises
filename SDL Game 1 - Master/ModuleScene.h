#pragma once

#include "Module.h"
#include "Globals.h"


class ModuleRender;
class ModuleTextures;
class SDL_Rect;

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
	int x;
	int y;
};