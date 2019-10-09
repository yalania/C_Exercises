#include "ModuleScene.h"
#include "Application.h"
#include "SDL/include/SDL.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
ModuleScene::ModuleScene()  {


}

bool ModuleScene::Init() {

	moduleTexture = App->textures;
	moduleRender = App->renderer;
	return true;
}

update_status ModuleScene::Update() {

	SDL_Rect section;
	section.x = 0;
	section.y = 0;
	section.w = 60;
	section.h = 60;

	SDL_Texture * loadedtexture = moduleTexture->Load(SPRITE_FILE);
	moduleRender->Blit(loadedtexture,0 ,0, &section);
	return UPDATE_CONTINUE;
}