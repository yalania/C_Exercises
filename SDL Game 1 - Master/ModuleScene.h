#pragma once

#include "Module.h"
#include "Globals.h"

#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Module.h"


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
	char * path;
	int x;
	int y;
	SDL_Rect * section;
};